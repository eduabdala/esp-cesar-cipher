#ifndef BSC_PROTOCOL_H
#define BSC_PROTOCOL_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Maximum buffer size for reading and sending BSC frames.
 */
#define MAX_BUFFER 256

/**
 * @brief Start of Text marker for BSC frames.
 */
#define STX 0x02

/**
 * @brief End of Text marker for BSC frames.
 */
#define ETX 0x03

/**
 * @brief Shift value used for Caesar cipher.
 */
#define SHIFT 3

/**
 * @brief Reads a BSC frame from standard input.
 * 
 * The frame format is: STX + payload + ETX + BCC.
 * 
 * @param buffer Buffer where the payload will be stored.
 * @param payload_len Pointer to a variable that will receive the payload length.
 * @return true If the frame is successfully read and validated.
 * @return false If the frame is invalid or BCC check fails.
 */
bool read_frame(uint8_t* buffer, uint32_t* payload_len);

/**
 * @brief Sends a BSC frame to standard output.
 * 
 * The frame format is: STX + payload + ETX + BCC.
 * 
 * @param payload Buffer containing the payload to send.
 * @param length Length of the payload.
 * @return true If the frame is successfully sent.
 * @return false If there is a size error or write failure.
 */
bool send_response(uint8_t* payload, uint32_t length);

/**
 * @brief Calculates the BCC (Block Check Character) for a given data buffer.
 * 
 * The BCC is computed as the XOR of all bytes in the data.
 * 
 * @param data Pointer to the data buffer.
 * @param length Number of bytes to process.
 * @return uint8_t The calculated BCC value.
 */
uint8_t calculate_bcc(const uint8_t* data, uint32_t length);

#endif // BSC_PROTOCOL_H
