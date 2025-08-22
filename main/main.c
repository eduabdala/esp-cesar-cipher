#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "esp_log.h"
#include "cipher.h"

#define MAX_BUFFER 256
#define PREFIX_CIFRAR "cifrar:"
#define PREFIX_DECIFRAR "decifrar:"
#define SHIFT 3

void app_main(void) {
    static const char* TAG = "CIPHER";
    char buffer[MAX_BUFFER];

    while (true) {
        memset(buffer, 0, MAX_BUFFER);
        fgets(buffer, MAX_BUFFER, stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strncmp(buffer, PREFIX_CIFRAR, strlen(PREFIX_CIFRAR)) == 0) {
            char* message = buffer + strlen(PREFIX_CIFRAR);

            ESP_LOGI(TAG, "Mensagem original: %s", message);
            caesar_cipher(message, SHIFT);
            ESP_LOGI(TAG, "Mensagem criptografada: %s", message);

        } else if (strncmp(buffer, PREFIX_DECIFRAR, strlen(PREFIX_DECIFRAR)) == 0) {
            char* message = buffer + strlen(PREFIX_DECIFRAR);

            ESP_LOGI(TAG, "Mensagem criptografada: %s", message);
            caesar_decipher(message, SHIFT);
            ESP_LOGI(TAG, "Mensagem decifrada: %s", message);

        } else {
            ESP_LOGW(TAG, "Comando inválido. Use: cifrar:mensagem ou decifrar:mensagem");
        }
    }
}
