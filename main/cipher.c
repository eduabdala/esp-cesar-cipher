#include "cipher.h"

/**
 * @brief Encrypts a message using a Caesar cipher.
 * 
 * This function shifts each alphabetic character in the message by the given shift value.
 * Uppercase and lowercase letters are processed independently. Non-alphabetic characters
 * remain unchanged.
 * 
 * @param message The string to encrypt. The string is modified in-place.
 * @param shift The number of positions to shift each letter.
 */
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

/**
 * @brief Decrypts a message encrypted with a Caesar cipher.
 * 
 * This function shifts each alphabetic character in the message backward by the given shift value.
 * Uppercase and lowercase letters are processed independently. Non-alphabetic characters
 * remain unchanged.
 * 
 * @param message The string to decrypt. The string is modified in-place.
 * @param shift The number of positions each letter was shifted during encryption.
 */
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
