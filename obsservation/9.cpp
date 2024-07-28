#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Playfair matrix
char matrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

// Position of each character in the matrix
int pos[26][2] = {
    {0, 3}, {4, 4}, {4, 4}, {4, 0}, {3, 0}, // A, B, C, D, E
    {0, 1}, {3, 4}, {0, 2}, {0, 3}, {0, 3}, // F, G, H, I/J, J
    {0, 4}, {3, 1}, {0, 0}, {1, 1}, {1, 2}, // K, L, M, N, O
    {1, 2}, {1, 4}, {3, 3}, {4, 1}, {4, 2}, // P, Q, R, S, T
    {1, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, // U, V, W, X, Y
    {2, 0} // Z
};

// Function to prepare the message
void prepareMessage(char* message, char* prepared) {
    int len = strlen(message);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            prepared[j] = toupper(message[i]);
            if (prepared[j] == 'J') prepared[j] = 'I';
            j++;
        }
    }
    prepared[j] = '\0';
}

// Function to add padding if needed
void addPadding(char* message) {
    int len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        if (message[i] == message[i + 1]) {
            memmove(&message[i + 1], &message[i], len - i);
            message[i + 1] = 'X';
            len++;
        }
    }
    if (len % 2 != 0) {
        message[len] = 'X';
        message[len + 1] = '\0';
    }
}

// Function to encrypt the message
void encrypt(char* message, char* encrypted) {
    int len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        char a = message[i];
        char b = message[i + 1];
        int row1 = pos[a - 'A'][0];
        int col1 = pos[a - 'A'][1];
        int row2 = pos[b - 'A'][0];
        int col2 = pos[b - 'A'][1];

        if (row1 == row2) {
            encrypted[i] = matrix[row1][(col1 + 1) % SIZE];
            encrypted[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encrypted[i] = matrix[(row1 + 1) % SIZE][col1];
            encrypted[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            encrypted[i] = matrix[row1][col2];
            encrypted[i + 1] = matrix[row2][col1];
        }
    }
    encrypted[len] = '\0';
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char prepared[100];
    char encrypted[100];

    prepareMessage(message, prepared);
    addPadding(prepared);
    encrypt(prepared, encrypted);

    printf("Original message: %s\n", message);
    printf("Prepared message: %s\n", prepared);
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}
