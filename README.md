# Criptografia de César - ESP32

Este projeto implementa um firmware simples para o ESP32 que criptografa uma mensagem usando a cifra de César.

## Como usar

1. Clone o repositório.
2. Conecte o ESP32 ao computador.
3. Compile e faça o upload do código para o dispositivo com:

   ```bash
   idf.py set-target esp32
   idf.py build
   idf.py flash -p /dev/ttyUSB0
