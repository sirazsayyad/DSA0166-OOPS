#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 2

void encrypt(char* plaintext, char* ciphertext, int key[SIZE][SIZE]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        int p1 = plaintext[i] - 'a';
        int p2 = plaintext[i + 1] - 'a';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        ciphertext[i] = c1 + 'a';
        ciphertext[i + 1] = c2 + 'a';
    }
    ciphertext[len] = '\0';
}

int main() {
    char message[] = "meetmeattheusualplaceattenratherthaneightoclock";
    char ciphertext[100];

    int key[SIZE][SIZE] = {
        {9, 4},
        {5, 7}
    };

    encrypt(message, ciphertext, key);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}
