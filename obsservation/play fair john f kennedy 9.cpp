#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];
int pos[26][2];

void createMatrix(char* key) {
    int alpha[26] = {0};
    int k = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (alpha[key[i] - 'A'] == 0) {
            matrix[k / SIZE][k % SIZE] = key[i];
            pos[key[i] - 'A'][0] = k / SIZE;
            pos[key[i] - 'A'][1] = k % SIZE;
            alpha[key[i] - 'A'] = 1;
            k++;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (alpha[c - 'A'] == 0) {
            matrix[k / SIZE][k % SIZE] = c;
            pos[c - 'A'][0] = k / SIZE;
            pos[c - 'A'][1] = k % SIZE;
            k++;
        }
    }
}

void decrypt(char* message, char* decrypted) {
    int len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        char a = message[i];
        char b = message[i + 1];
        if (a == 'J') a = 'I';
        if (b == 'J') b = 'I';
        int row1 = pos[a - 'A'][0];
        int col1 = pos[a - 'A'][1];
        int row2 = pos[b - 'A'][0];
        int col2 = pos[b - 'A'][1];

        if (row1 == row2) {
            decrypted[i] = matrix[row1][(col1 + SIZE - 1) % SIZE];
            decrypted[i + 1] = matrix[row2][(col2 + SIZE - 1) % SIZE];
        } else if (col1 == col2) {
            decrypted[i] = matrix[(row1 + SIZE - 1) % SIZE][col1];
            decrypted[i + 1] = matrix[(row2 + SIZE - 1) % SIZE][col2];
        } else {
            decrypted[i] = matrix[row1][col2];
            decrypted[i + 1] = matrix[row2][col1];
        }
    }
    decrypted[len] = '\0';
}

int main() {
    char key[] = "YOURKEY";  // Replace with the appropriate key
    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char decrypted[sizeof(message)];

    createMatrix(key);
    decrypt(message, decrypted);

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
