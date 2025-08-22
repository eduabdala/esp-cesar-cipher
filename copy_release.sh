#!/bin/bash
# Caminho do build do ESP-IDF
BUILD_DIR="./build"
# Pasta de releases
RELEASE_DIR="./releases"
# Versão do firmware
PROJECT_VER="v1.0.0"
BIN_NAME="esp-cesar-cipher-${PROJECT_VER}.bin"

# Cria a pasta de releases se não existir
mkdir -p "$RELEASE_DIR"

# Caminho do bin final
BIN_PATH="$BUILD_DIR/esp_cesar_cipher.bin"

if [ -f "$BIN_PATH" ]; then
    cp "$BIN_PATH" "$RELEASE_DIR/$BIN_NAME"
    echo "Firmware copiado para $RELEASE_DIR/$BIN_NAME"
else
    echo "Arquivo $BIN_PATH não encontrado. Compile o projeto antes."
    exit 1
fi
