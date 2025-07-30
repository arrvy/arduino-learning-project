

# Hand Gesture With ESP32 and PlatfromIO 🐜

> <p style="color:red;"> Still Under Progress </p>

Proyek ini menggunakan kamera laptop + Python + MediaPipe untuk mengenali gesture tangan dan mengontrol LED di ESP32 melalui jaringan WiFi. Jadi, bukan memakai kabel serial (UART), tapi komunikasi lewat HTTP request ke ESP32.

## Dasar Teori

### Apa itu PlatfromIO

PlatfromIO adalah IDE atau Extension IDE yang sangat berguna bagi pengembangan sistem benam (IoT) seperti Arduino,ESP, dll.

Keunggulan menggunakan PlatfromIO dibandingkan Arduino IDE adalah **kebebasan kita dalam mengatur projek** sehingga projek lebih profesional. Dengan menggunakan IDE PlatfromIO, kita bisa **memanfaatkan fitur-fitur yang ada di VSCode** (Syntax Highlighting, Intellisense, Debugging, Versio`nControl, File Management) yang tidak ada di Arduino IDE. Selain itu, kita juga bisa mengatur libarary/dependency yang digunakan di projek kita dengan lebih bebas dan lebih terstruktur, sehingga membuat projek kita lebih scalable.

### Apa itu MediaPipe

MediaPipe adalah framework open-source dari Google untuk membangun pipeline pemrosesan multimedia, terutama untuk visi komputer (computer vision). Salah satu fitur unggulannya adalah Hand Tracking yang mampu mendeteksi dan mengenali landmark dari tangan secara real-time.

Dalam proyek ini, MediaPipe digunakan untuk mendeteksi gestur tangan menggunakan webcam laptop, lalu gestur tersebut akan diterjemahkan ke dalam perintah untuk menyalakan atau mematikan LED di ESP32.

### Apa itu OpenCV

OpenCV (Open Source Computer Vision Library) adalah pustaka open-source untuk visi komputer dan pembelajaran mesin. Di proyek ini, OpenCV digunakan untuk menangkap video dari webcam dan menampilkan visualisasi deteksi tangan yang dilakukan oleh MediaPipe.

### Cara Kerja

1. Python (dengan MediaPipe + OpenCV) mendeteksi gesture tangan (jari terbuka/tertutup).
2. Berdasarkan posisi jari, Python mengirimkan HTTP request ke IP ESP32 (misalnya: `http://192.168.0.x/led/index/on` ).
3. ESP32 menerima request dan mengaktifkan LED sesuai dengan endpoint.
4. Hasil bisa dilihat secara real-time (LED menyala sesuai gesture).

## Alat dan Bahan

ESP32 Dev Board
5x LED + 5x resistor
Kabel jumper + Breadboard
Laptop dengan **Python 3.12**
Koneksi WiFi (yang sama untuk laptop dan ESP32)

## Langkah Kerja

1. Rangkai Skematik yang Telah Tersedia

2. Setup Python Environment

        python -m venv myenv
        myenv\Scripts\activate  # Window
    Dan jangan lupa untuk menginstall library yang diperlukan

        Di Python
        py -3.12 -m pip install requests
        py -3.12 -m pip install opencv-python
        py -3.12 -m pip install mediapipe

        Di PlatfromIO cukup add library

        <Wifi.h>
        <ESPAsyncWebServer.h>
        <AsyncTCP.h>

    Pastikan kita memakai ```AsyncTCP.h``` dan bukan ```ESPAsyncTCP.h``` . HANYA 2 itu yang kita perlukan untuk menambah dan downlaod secara manual/cari

> mungkin kamu juga harus mengkonfigurasi powershell mu agar bisa menjalankan activate
> Perintah untuk MacOS / Linux berbeda

1. Jalankan Python (gesture to HTTP)

        python cam.py

    atau

        python -3.12 -m cam.py

2. Upload kode ke ESP32 via PlatfromIO

        WiFi.begin(ssid, password);
        server.on("/led/thumb/on", ...) // dst...
    Lihat IP di Serial Monitor → http://<ip_address>/led/...

## Wiring


![wiring1](./assets/image.png)


## Code

ESP32 (C++ via PlatformIO) menangani server HTTP:

    /led/thumb/on → Nyalakan LED ibu jari

    /led/thumb/off → Matikan LED ibu jari

(dan seterusnya untuk jari lain)

Python (cam.py) mendeteksi gesture dan mengirim HTTP request berdasarkan jari yang terbuka.


## Hasil

- Ketika kamu menunjukkan gesture "jempol", maka LED thumb akan menyala.
- Semua kontrol terjadi secara wireless melalui jaringan WiFi lokal.

## Kesimpulan

### Permasalahan

- Frame kamera delay: MediaPipe bisa berat tergantung performa laptop.
- MediaPipe tidak bisa diinstall di Python 3.13: Solusi → Gunakan di 3.12 karena versi python terakhir yang mendukung mediapipe
- Kalau WiFi lambat, respon ke LED delay.
- Hand Gesture kurang responsive dan tidak akurat

### Kekurangan
- Tidak ada autentikasi HTTP → rawan jika jaringan tidak aman.
- Deteksi jari kadang miss (terutama jika tangan tidak jelas terlihat).
- Hanya berjalan di jaringan lokal, belum via Internet.

### Future Ideas

- Tambahkan autentikasi (token API / password).
- Optimasi gesture agar lebih responsif dan minim false positive.
- Buat dashboard web untuk kontrol manual.
- Bisa koneksi via MQTT selain HTTP.

