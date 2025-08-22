#!/bin/bash
# build.sh - Build ESP32 Firmware e gera release
# Eduardo Silva Abdala

set -e  # Sai imediatamente se algum comando falhar

# ------------------------
# Configurações do projeto
# ------------------------
PROJECT_DIR="$(pwd)"
RELEASE_DIR="$PROJECT_DIR/releases"
PROJECT_NAME="esp_cesar_cipher"

# ------------------------
# Versão do build
# ------------------------
# Se for passada como argumento, usa argumento, senão lê version.txt, senão usa padrão
if [ -n "$1" ]; then
    PROJECT_VER="$1"
elif [ -f "$PROJECT_DIR/version.txt" ]; then
    PROJECT_VER=$(cat "$PROJECT_DIR/version.txt")
else
    PROJECT_VER="v0.0.0"
fi

BIN_NAME="${PROJECT_NAME}-${PROJECT_VER}.bin"

echo "Versão do build: $PROJECT_VER"
echo "Nome do binário: $BIN_NAME"

# ------------------------
# Configuração ESP-IDF
# ------------------------
ESP_IDF_PATH="$HOME/esp/esp-idf"
echo "Configurando ambiente ESP-IDF..."
source "$ESP_IDF_PATH/export.sh"

# ------------------------
# Build do projeto
# ------------------------
echo "Iniciando build..."
idf.py fullclean
idf.py build

# ------------------------
# Copiar firmware para release
# ------------------------
echo "Preparando pasta de releases..."
mkdir -p "$RELEASE_DIR"

SRC_BIN="$PROJECT_DIR/build/${PROJECT_NAME}.bin"
DEST_BIN="$RELEASE_DIR/$BIN_NAME"

if [ -f "$SRC_BIN" ]; then
    cp "$SRC_BIN" "$DEST_BIN"
    echo "Firmware copiado para releases: $DEST_BIN"
else
    echo "Erro: arquivo binário não encontrado: $SRC_BIN"
    exit 1
fi

echo "Build e release concluídos com sucesso!"
