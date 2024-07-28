#include <stdio.h>
#include <stdint.h>

typedef uint8_t byte;

// S-DES parameters and tables
byte IP[] = {1, 5, 2, 0, 3, 7, 4, 6};
byte IP_INV[] = {3, 0, 2, 4, 6, 1, 7, 5};
byte EP[] = {3, 0, 1, 2, 1, 2, 3, 0};
byte P4[] = {1, 3, 2, 0};
byte P10[] = {2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
byte P8[] = {5, 2, 6, 3, 7, 4, 9, 8};
byte S0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}};
byte S1[4][4] = {
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}};

// Utility functions
byte permute(byte input, byte *table, int size) {
    byte output = 0;
    for (int i = 0; i < size; i++) {
        output |= ((input >> table[i]) & 0x01) << i;
    }
    return output;
}

byte left_shift(byte input) {
    return ((input << 1) | (input >> 4)) & 0x1F;
}

byte sbox(byte input, byte sbox[4][4]) {
    int row = ((input & 0x08) >> 2) | (input & 0x01);
    int col = (input & 0x06) >> 1;
    return sbox[row][col];
}

byte f(byte r, byte k) {
    byte temp = permute(r, EP, 8) ^ k;
    byte left = sbox((temp >> 4) & 0x0F, S0);
    byte right = sbox(temp & 0x0F, S1);
    return permute((left << 2) | right, P4, 4);
}

// Key generation
void generate_keys(byte key, byte *k1, byte *k2) {
    byte p10 = permute(key, P10, 10);
    byte ls1 = left_shift((p10 >> 5) & 0x1F) << 5 | left_shift(p10 & 0x1F);
    *k1 = permute(ls1, P8, 8);
    byte ls2 = left_shift((ls1 >> 5) & 0x1F) << 5 | left_shift(ls1 & 0x1F);
    *k2 = permute(ls2, P8, 8);
}

// S-DES encryption/decryption
byte sdes(byte input, byte k1, byte k2, int mode) {
    byte ip = permute(input, IP, 8);
    byte left = (ip >> 4) & 0x0F;
    byte right = ip & 0x0F;
    byte temp;
    if (mode == 1) {
        temp = f(right, k1) ^ left;
        left = f(temp, k2) ^ right;
    } else {
        temp = f(right, k2) ^ left;
        left = f(temp, k1) ^ right;
    }
    return permute((left << 4) | temp, IP_INV, 8);
}

// ECB mode encryption/decryption
void ecb_mode(byte *input, byte *output, byte key, int len, int mode) {
    byte k1, k2;
    generate_keys(key, &k1, &k2);
    for (int i = 0; i < len; i++) {
        output[i] = sdes(input[i], k1, k2, mode);
    }
}

// CBC mode encryption
void cbc_encrypt(byte *plaintext, byte *ciphertext, byte key, byte iv, int len) {
    byte k1, k2;
    generate_keys(key, &k1, &k2);
    byte previous_block = iv;
    for (int i = 0; i < len; i++) {
        byte input_block = plaintext[i] ^ previous_block;
        ciphertext[i] = sdes(input_block, k1, k2, 1);
        previous_block = ciphertext[i];
    }
}

// CBC mode decryption
void cbc_decrypt(byte *ciphertext, byte *plaintext, byte key, byte iv, int len) {
    byte k1, k2;
    generate_keys(key, &k1, &k2);
    byte previous_block = iv;
    for (int i = 0; i < len; i++) {
        byte decrypted_block = sdes(ciphertext[i], k1, k2, 0);
        plaintext[i] = decrypted_block ^ previous_block;
        previous_block = ciphertext[i];
    }
}

// CFB mode encryption
void cfb_encrypt(byte *plaintext, byte *ciphertext, byte key, byte iv, int len) {
    byte k1, k2;
    generate_keys(key, &k1, &k2);
    byte shift_register = iv;
    for (int i = 0; i < len; i++) {
        byte encrypted_shift = sdes(shift_register, k1, k2, 1);
        ciphertext[i] = plaintext[i] ^ encrypted_shift;
        shift_register = ciphertext[i];
    }
}

// CFB mode decryption
void cfb_decrypt(byte *ciphertext, byte *plaintext, byte key, byte iv, int len) {
    byte k1, k2;
    generate_keys(key, &k1, &k2);
    byte shift_register = iv;
    for (int i = 0; i < len; i++) {
        byte encrypted_shift = sdes(shift_register, k1, k2, 1);
        plaintext[i] = ciphertext[i] ^ encrypted_shift;
        shift_register = ciphertext[i];
    }
}

// Print binary representation of a byte
void print_binary(byte value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 0x01);
    }
}

int main() {
    byte plaintext[] = {0x01, 0x23};  // Binary plaintext 0000 0001 0010 0011
    byte ciphertext[2];
    byte decrypted[2];
    byte key = 0xFD;  // Binary key 01111 11101
    byte iv = 0xAA;   // Initialization vector 1010 1010

    printf("Plaintext: ");
    for (int i = 0; i < 2; i++) {
        print_binary(plaintext[i]);
        printf(" ");
    }
    printf("\n");

    // ECB mode
    ecb_mode(plaintext, ciphertext, key, 2, 1);
    printf("ECB Ciphertext: ");
    for (int i = 0; i < 2; i++) {
        print_binary(ciphertext[i]);
        printf(" ");
    }
    printf("\n");
    ecb_mode(ciphertext, decrypted, key, 2, 0);
    printf("ECB Decrypted: ");
    for (int i = 0; i < 2; i++) {
        print_binary(decrypted[i]);
        printf(" ");
    }
    printf("\n");

    // CBC mode
    cbc_encrypt(plaintext, ciphertext, key, iv, 2);
    printf("CBC Ciphertext: ");
    for (int i = 0; i < 2; i++) {
        print_binary(ciphertext[i]);
        printf(" ");
    }
    printf("\n");
    cbc_decrypt(ciphertext, decrypted, key, iv, 2);
    printf("CBC Decrypted: ");
    for (int i = 0; i < 2; i++) {
        print_binary(decrypted[i]);
        printf(" ");
    }
    printf("\n");

    // CFB mode
    cfb_encrypt(plaintext, ciphertext, key, iv, 2);
    printf("CFB Ciphertext: ");
    for (int i = 0; i < 2; i++) {
        print_binary(ciphertext[i]);
        printf(" ");
    }
    printf("\n");
    cfb_decrypt(ciphertext, decrypted, key, iv, 2);
    printf("CFB Decrypted: ");
    for (int i = 0; i < 2; i++) {
        print_binary(decrypted[i]);
        printf(" ");
    }
    printf("\n");

    return 0;
}