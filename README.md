![Build](https://github.com/eduabdala/tool-cesar-cipher/actions/workflows/build.yml/badge.svg)
![Project Status](https://img.shields.io/badge/status-in%20development-yellow)
![Version](https://img.shields.io/github/v/release/eduabdala/tool-cesar-cipher?color=blue&label=version)
![License](https://img.shields.io/badge/license-MIT-green)
![Open Issues](https://img.shields.io/github/issues/eduabdala/tool-cesar-cipher)
![C++](https://img.shields.io/badge/C++-17.0-blue)
![ESP32](https://img.shields.io/badge/ESP32-OK-lightgrey)

# Caesar Cipher - ESP32

Simple ESP32 firmware that encrypts messages using the **Caesar Cipher** algorithm.

---

## ⚙️ Technologies & Tools

* **Languages:** C++17
* **Framework / SDK:** ESP-IDF
* **Hardware:** ESP32
* **Build Tools:** CMake, idf.py

---

## 🚀 How to Use

### 1. Set Up the ESP-IDF Environment

If you haven't set up the ESP-IDF yet, run:

```bash
cd ~/esp/esp-idf
./install.sh
. $HOME/esp/esp-idf/export.sh
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

```bash
idf.py set-target esp32
idf.py fullclean
idf.py build
idf.py flash -p /dev/ttyUSB0
```

---

### 4. Automated Command (Optional)

Create an alias to automate setup and build:

```bash
echo "alias idf_build='PROJECT_DIR=\$(pwd) && /home/<user>/esp/esp-idf/install.sh && . \$HOME/esp/esp-idf/export.sh && cd \"\$PROJECT_DIR\" && idf.py fullclean && idf.py build'" >> ~/.bashrc
source ~/.bashrc
```

Then, just run inside the project directory:

```bash
idf_build
```

---

## 📫 Contact / Contribute

* GitHub: [eduabdala](https://github.com/eduabdala)
* Issues: [Open Issues](https://github.com/eduabdala/tool-cesar-cipher/issues)
* License: MIT
