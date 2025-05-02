//SINGLE TRAFFIC LIGHT ONLY
//Program hanya menghidupkan lampu secara sekuensial

void setup() {
  // RED pins
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  
  // YELLOW pins
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  
  // GREEN pins
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // === SET 1: Merah Menyala ===
  digitalWrite(2, HIGH); // RED1 ON
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);
  digitalWrite(3, LOW); // YELLOWs OFF
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(4, LOW); // GREENs OFF
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  delay(5000);

  // === SET 1: Kuning Menyala ===
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH); // YELLOW1 ON
  delay(1000);
  digitalWrite(3, LOW);

  // === SET 1: Hijau Menyala ===
  digitalWrite(4, HIGH); // GREEN1 ON
  delay(5000);
  digitalWrite(4, LOW);

  // === SET 1: Kuning Menyala Lagi ===
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);

  // === SET 2: Merah Menyala ===
  digitalWrite(5, HIGH); // RED2 ON
  delay(5000);

  // === SET 2: Kuning Menyala ===
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH); // YELLOW2 ON
  delay(1000);
  digitalWrite(6, LOW);

  // === SET 2: Hijau Menyala ===
  digitalWrite(7, HIGH); // GREEN2 ON
  delay(5000);
  digitalWrite(7, LOW);

  // === SET 2: Kuning Menyala Lagi ===
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);

  // === SET 3: Merah Menyala ===
  digitalWrite(8, HIGH); // RED3 ON
  delay(5000);

  // === SET 3: Kuning Menyala ===
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH); // YELLOW3 ON
  delay(1000);
  digitalWrite(9, LOW);

  // === SET 3: Hijau Menyala ===
  digitalWrite(10, HIGH); // GREEN3 ON
  delay(5000);
  digitalWrite(10, LOW);

  // === SET 3: Kuning Menyala Lagi ===
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);

  // Loop kembali ke awal (SET 1)
}
