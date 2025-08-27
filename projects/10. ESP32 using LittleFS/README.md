# Using SPIFFS on ESP32

---
In this project, I will explore how to use SPIFFS (SPI Flash File System) on the ESP32.
SPIFFS allows us to store files (text, HTML, CSS, images, JSON, configuration, etc.) directly in the ESP32 flash memory. These files can later be accessed by the program, for example to serve a web page, store configuration parameters, or log sensor data.

I will recreate basic examples from Random Nerd Tutorials and add my own notes to understand how ESP32 handles filesystem operations.

---

## Dasar Teori

### Apa itu SPIFFS?

SPIFFS (SPI Flash File System) adalah sistem file ringan yang digunakan untuk menyimpan data di memori flash internal ESP32.
Dengan SPIFFS, kita bisa menyimpan file seperti .txt, .html, .css, .json di dalam board, lalu membacanya dalam program.
**Keunggulan**:

- Tidak butuh SD Card eksternal
- Praktis untuk menyimpan file statis (webpage, konfigurasi)
- Mendukung operasi baca, tulis, hapus

**Keterbatasan**:

- Tidak mendukung direktori bertingkat (hanya flat structure)
- Tidak cocok untuk menulis berulang dalam jumlah besar (flash bisa aus)
  
**Kapan Menggunakan SPIFFS**:

- Saat membuat web server ESP32 dengan HTML/CSS/JS yang disimpan langsung di board
- Saat menyimpan konfigurasi (misalnya WiFi SSID & Password)
- Saat membuat data logger sederhana

---

## Cara Kerja

- File disimpan ke flash ESP32 menggunakan Arduino IDE melalui plugin ESP32 Sketch Data Upload
- File tersebut bisa dibuka dari kode dengan fungsi SPIFFS.open()
- Program ESP32 bisa membaca isi file (misalnya index.html) lalu mengirimkan ke client lewat web server
- Program juga bisa menulis file baru (misalnya menyimpan data sensor ke data.txt)

---

## Alat dan Bahan

- ESP32 Dev Module
- Kabel USB
- Arduino IDE dengan ESP32 Core
- Plugin ESP32FS (SPIFFS Upload Tool) untuk Arduino IDE, di VSCode sudah tersedia langsung
- File sederhana: index.html, style.css, atau data.txt

---

## Langkah Kerja

1. Install SPIFFS Plugin
   - Download ESP32FS-1.0.zip dan install ke folder tools Arduino IDE
   - Restart Arduino IDE → Tools → ESP32 Sketch Data Upload
2. Buat Folder data/ dalam Sketch
   - Simpan file yang ingin diupload (misalnya index.html, style.css, test.txt)
3. Upload File ke SPIFFS
   - Arduino IDE → Tools → ESP32 Sketch Data Upload
   - File akan disimpan di flash ESP32
4. Gunakan Kode untuk Membaca File

```C
if(!SPIFFS.begin(true)){
Serial.println("An Error has occurred while mounting SPIFFS");
return;
}

File file = SPIFFS.open("/test.txt");
if(!file){
    Serial.println("Failed to open file");
    return;
}

while(file.available()){
    Serial.write(file.read());
}
file.close();
 ```

5. Tambahkan File Web
    - Buat index.html di folder data → isi dengan HTML sederhana
    - Upload lagi ke SPIFFS → buka lewat webserver ESP32

---
## Wiring

Tidak ada wiring khusus, hanya ESP32 + USB (untuk programming & debugging).

---

## Code

[Go to Code](./src/main.cpp)

---

## Hasil

- File test.txt berhasil disimpan dan dibaca dari flash.
- Web server ESP32 bisa melayani index.html langsung dari SPIFFS.
- Konfigurasi (misalnya WiFi SSID dan Password) bisa disimpan di file .txt dan dibaca saat startup.

---

## Kesimpulan

- SPIFFS pada ESP32 memudahkan kita untuk menyimpan file statis langsung ke flash memory.
- Sangat cocok digunakan untuk proyek web server IoT karena HTML/JS/CSS bisa dipanggil langsung dari ESP32.
- Kekurangannya: tidak mendukung folder bertingkat dan ada keterbatasan jumlah tulis.
- Untuk logging berat, sebaiknya gunakan microSD; untuk file konfigurasi/webpage, cukup SPIFFS.

### Future Ideas

- Coba ganti ke LittleFS (lebih modern daripada SPIFFS).

- Membuat config manager (menyimpan WiFi SSID, MQTT, API key) di file JSON.

- Integrasi dengan OTA (Over The Air update) untuk update firmware & file HTML.

---
## Source

1. [Random Nerd Tutorials: ESP32 with VS Code and PlatformIO: Upload Files to Filesystem (SPIFFS)](https://randomnerdtutorials.com/esp32-vs-code-platformio-spiffs/)

2. [Espressif Docs: SPIFFS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/storage/spiffs.html)

3. [GitHub: ESP32FS Tool](https://github.com/me-no-dev/arduino-esp32fs-plugin)