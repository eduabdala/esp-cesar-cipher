# Caesar Cipher - ESP32

This project implements a simple firmware for the ESP32 that encrypts messages using the Caesar cipher.

## How to Use

### 1. Set Up the ESP-IDF Environment

If you haven't set up the ESP-IDF yet, run:

```bash
cd ~/esp/esp-idf
./install.sh       # Installs required toolchains and dependencies
. $HOME/esp/esp-idf/export.sh  # Activates the ESP-IDF environment
```

> 💡 Tip: To avoid running these commands every time, see the **Automated Command** section below.

---

### 2. Clone the Repository

```bash
git clone https://github.com/eduabdala/tool-cesar-cipher
cd esp-cesar-cipher
```

---

### 3. Build and Flash to the ESP32

Set the ESP32 target, build, and flash the project:

```bash
idf.py set-target esp32
idf.py fullclean        # Cleans previous builds
idf.py build            # Compiles the project
idf.py flash -p /dev/ttyUSB0  # Uploads to the ESP32
```

---

### 4. Automated Command (Optional)

To simplify the process, you can create an alias that installs the tools, activates the environment, and builds the project with a single command:

```bash
echo "alias idf_build='PROJECT_DIR=\$(pwd) && /home/<user>/esp/esp-idf/install.sh && . \$HOME/esp/esp-idf/export.sh && cd \"\$PROJECT_DIR\" && idf.py fullclean && idf.py build'" >> ~/.bashrc
source ~/.bashrc
```

Now, inside the project directory, just run:

```bash
idf_build
```

> This takes care of all the setup and build automatically.
