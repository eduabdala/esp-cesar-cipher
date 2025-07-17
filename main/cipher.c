#include "cipher.h"

void caesar_cipher(char* message, int shift) {
    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A' + shift) % 26) + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a' + shift) % 26) + 'a';
        }
        message++;
    }
}

void caesar_decipher(char* message, int shift) {
    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A' - shift + 26) % 26) + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a' - shift + 26) % 26) + 'a';
        }
        message++;
    }
}
