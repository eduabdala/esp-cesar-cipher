#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "bscProtocol.h"
#include "cipher.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define SHIFT 3

// Buffer for incoming BSC frames
static uint8_t buffer[MAX_BUFFER];
static uint32_t payload_len = 0;
static bool nak_sent = false;

// Application states
typedef enum {
    STATE_IDLE,          // Waiting for incoming frame
    STATE_PROCESSING,    // Processing received frame
    STATE_SEND_RESPONSE  // Sending response back
} app_state_t;

// Buffer to store processed response
static char response[MAX_BUFFER];

/**
 * @brief Main application task.
 * 
 * Implements a simple BSC-based protocol to encrypt/decrypt messages using
 * a Caesar cipher. Supports commands:
 *  - "cifrar:<message>" -> encrypts the message
 *  - "decifrar:<message>" -> decrypts the message
 * 
 * If a frame is invalid, sends "NAK" once until a valid frame is received.
 */
void app_main(void) {
    app_state_t state = STATE_IDLE;

    while (1) {
        switch (state) {

        case STATE_IDLE:
            // Check for incoming BSC frame
            if (read_frame(buffer, &payload_len)) {
                state = STATE_PROCESSING;
            } else {
                // Send NAK only once for invalid frame
                if (!nak_sent) {
                    const char* nak = "NAK";
                    send_response((uint8_t*)nak, strlen(nak));
                    nak_sent = true;
                }
                vTaskDelay(pdMS_TO_TICKS(10));
            }
            break;

        case STATE_PROCESSING:
            // Reset NAK flag
            nak_sent = false;

            if (payload_len >= MAX_BUFFER) payload_len = MAX_BUFFER - 1;
            buffer[payload_len] = '\0';

            // Process command
            if (strncmp((char*)buffer, "cifrar:", 7) == 0) {
                char* msg = (char*)buffer + 7;
                caesar_cipher(msg, SHIFT);
                strncpy(response, msg, MAX_BUFFER);
            } else if (strncmp((char*)buffer, "decifrar:", 9) == 0) {
                char* msg = (char*)buffer + 9;
                caesar_decipher(msg, SHIFT);
                strncpy(response, msg, MAX_BUFFER);
            } else {
                // Unknown command
                strncpy(response, "NAK", MAX_BUFFER);
            }

            state = STATE_SEND_RESPONSE;
            break;

        case STATE_SEND_RESPONSE:
            // Send response back via BSC protocol
            send_response((uint8_t*)response, strlen(response));

            // Clear buffers for next frame
            memset(buffer, 0, MAX_BUFFER);
            payload_len = 0;
            memset(response, 0, MAX_BUFFER);

            state = STATE_IDLE;
            vTaskDelay(pdMS_TO_TICKS(5));
            break;

        default:
            state = STATE_IDLE;
            break;
        }
    }
}
