#include "bscProtocol.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_BUFFER 256   // Maximum buffer size for reading and writing BSC frames
#define STX 0x02         // Start of Text
#define ETX 0x03         // End of Text

/**
 * @brief Calculates the BCC (Block Check Character) for a given byte sequence.
 *        The BCC is an XOR of all payload bytes plus the ETX.
 * 
 * @param data Pointer to the data used in the calculation.
 * @param length Number of bytes to consider.
 * @return uint8_t Calculated BCC value.
 */
uint8_t calculate_bcc(const uint8_t* data, uint32_t length) {
    uint8_t bcc = 0;
    for (uint32_t i = 0; i < length; i++) {
        bcc ^= data[i];
    }
    return bcc;
}

/**
 * @brief Reads a BSC frame from stdin.
 *        The frame format should be: STX + payload + ETX + BCC.
 * 
 * @param buffer Buffer where the payload will be stored.
 * @param payload_len Pointer to a variable that will receive the payload length.
 * @return true If the frame is successfully read and validated.
 * @return false If there is a read error, formatting issue, or invalid BCC.
 */
bool read_frame(uint8_t* buffer, uint32_t* payload_len) {
    uint8_t temp[MAX_BUFFER];
    size_t read_len = fread(temp, 1, MAX_BUFFER, stdin);

    if (read_len < 4) return false;

    uint8_t* stx = memchr(temp, STX, read_len);
    if (!stx) return false;

    uint8_t* etx = memchr(stx + 1, ETX, read_len - (stx - temp) - 1);
    if (!etx || etx <= stx) return false;

    if ((etx + 1 - temp) >= read_len) return false;

    uint8_t received_bcc = *(etx + 1);
    uint8_t calc_bcc = calculate_bcc(stx + 1, etx - stx);

    if (calc_bcc != received_bcc) return false;

    *payload_len = etx - stx - 1;
    if (*payload_len >= MAX_BUFFER) return false;

    memcpy(buffer, stx + 1, *payload_len);
    buffer[*payload_len] = '\0';

    return true;
}

/**
 * @brief Sends a BSC frame to stdout.
 *        The frame is constructed as: STX + payload + ETX + BCC.
 * 
 * @param payload Buffer containing the data to send.
 * @param length Payload length.
 * @return true If the frame was successfully sent.
 * @return false If there is a size error or write failure.
 */
bool send_response(uint8_t* payload, uint32_t length) {
    if (length + 3 > MAX_BUFFER) return false;

    uint8_t packet[MAX_BUFFER];
    uint32_t idx = 0;
    
    packet[idx++] = STX;
    memcpy(&packet[idx], payload, length);
    idx += length;
    packet[idx++] = ETX;

    uint8_t bcc = calculate_bcc(&packet[1], idx - 1);
    packet[idx++] = bcc;

    size_t written = fwrite(packet, 1, idx, stdout);
    fflush(stdout);

    return written == idx;
}
