[back](DESCRIPTION.md)

### Algoritma jalnnya lampu-lampu

#### ✅ Step 1: Arah 1 Hijau
- GREEN1 = ON
- RED2, RED3 = ON
- Semua lainnya = OFF
- Delay: 5 detik

#### ⚠️ Step 2: Transisi Arah 1 ke Arah 2
- YELLOW1 = ON
- GREEN1 = OFF
- RED2 = OFF (persiapan hijau)
- Delay: 1 detik

#### ✅ Step 3: Arah 2 Hijau
- GREEN2 = ON
- RED1, RED3 = ON
- Semua lainnya = OFF
- Delay: 5 detik

#### ⚠️ Step 4: Transisi Arah 2 ke Arah 3
- YELLOW2 = ON
- GREEN2 = OFF
- RED3 = OFF
- Delay: 1 detik

#### ✅ Step 5: Arah 3 Hijau
- GREEN3 = ON
- RED1, RED2 = ON
- Semua lainnya = OFF
- Delay: 5 detik

#### ⚠️ Step 6: Transisi Arah 3 ke Arah 1
- YELLOW3 = ON
- GREEN3 = OFF
- RED1 = OFF
- Delay: 1 detik

#### 🔄 Kembali ke Step 1 (Loop)

	💡 Catatan Tambahan
	- Program menggunakan `digitalWrite()` untuk mengatur HIGH (1) dan LOW (0) pada setiap pin.
	- Gunakan `delay()` untuk mengatur waktu tiap siklus lampu.
	- Bisa dikembangkan lebih lanjut dengan sensor kendaraan, pedestrian, atau buzzer.
