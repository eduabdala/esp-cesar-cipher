#ifndef CIPHER_H
#define CIPHER_H

#include <stdint.h>

/**
 * @brief Encrypts a message using the Caesar cipher.
 * 
 * Shifts each alphabetic character in the message forward by the specified shift value.
 * Uppercase and lowercase letters are processed independently. Non-alphabetic characters
 * are not changed.
 * 
 * @param message Pointer to the string to encrypt. The string is modified in-place.
 * @param shift Number of positions to shift each letter.
 */
void caesar_cipher(char* message, int shift);

/**
 * @brief Decrypts a message encrypted with the Caesar cipher.
 * 
 * Shifts each alphabetic character in the message backward by the specified shift value.
 * Uppercase and lowercase letters are processed independently. Non-alphabetic characters
 * are not changed.
 * 
 * @param message Pointer to the string to decrypt. The string is modified in-place.
 * @param shift Number of positions each letter was shifted during encryption.
 */
void caesar_decipher(char* message, int shift);

#endif // CIPHER_H
