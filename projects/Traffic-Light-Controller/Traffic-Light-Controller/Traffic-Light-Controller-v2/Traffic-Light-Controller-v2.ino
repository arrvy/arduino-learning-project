// Definisikan pin dengan const int
const int RED1_PIN = 2;   // Pin untuk RED 1
const int YELLOW1_PIN = 3; // Pin untuk YELLOW 1
const int GREEN1_PIN = 4;  // Pin untuk GREEN 1
const int RED2_PIN = 5;   // Pin untuk RED 2
const int YELLOW2_PIN = 6; // Pin untuk YELLOW 2
const int GREEN2_PIN = 7;  // Pin untuk GREEN 2
const int RED3_PIN = 8;   // Pin untuk RED 3
const int YELLOW3_PIN = 9; // Pin untuk YELLOW 3
const int GREEN3_PIN = 10; // Pin untuk GREEN 3

void setup() {
  // Konfigurasi pin output
  pinMode(RED1_PIN, OUTPUT);
  pinMode(YELLOW1_PIN, OUTPUT);
  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(RED2_PIN, OUTPUT);
  pinMode(YELLOW2_PIN, OUTPUT);
  pinMode(GREEN2_PIN, OUTPUT);
  pinMode(RED3_PIN, OUTPUT);
  pinMode(YELLOW3_PIN, OUTPUT);
  pinMode(GREEN3_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(RED1_PIN, 1); // Mengaktifkan set signal pertama
  digitalWrite(GREEN2_PIN, 1);
  digitalWrite(GREEN3_PIN, 1);
  digitalWrite(GREEN1_PIN, 0);
  digitalWrite(YELLOW1_PIN, 0);  
  digitalWrite(YELLOW2_PIN, 0);
  digitalWrite(RED2_PIN, 0);
  digitalWrite(YELLOW3_PIN, 0);
  digitalWrite(RED3_PIN, 0);
  delay(5000);
 
  digitalWrite(YELLOW1_PIN, 1); // Mengaktifkan lampu kuning
  digitalWrite(YELLOW2_PIN, 1);
  digitalWrite(RED1_PIN, 0); 
  digitalWrite(GREEN2_PIN, 0);
  delay(1000);
 
  digitalWrite(GREEN1_PIN, 1); // Mengaktifkan set signal kedua
  digitalWrite(RED2_PIN, 1);
  digitalWrite(GREEN3_PIN, 1);
  digitalWrite(RED1_PIN, 0);
  digitalWrite(YELLOW1_PIN, 0);  
  digitalWrite(YELLOW2_PIN, 0);
  digitalWrite(RED3_PIN, 0);
  digitalWrite(GREEN2_PIN, 0);
  delay(5000);
 
  digitalWrite(YELLOW3_PIN, 1); // Mengaktifkan lampu kuning
  digitalWrite(YELLOW2_PIN, 1);
  digitalWrite(GREEN3_PIN, 0);
  digitalWrite(RED2_PIN, 0);  
  digitalWrite(GREEN1_PIN, 0);
  delay(1000); 
   
  digitalWrite(RED3_PIN, 1); // Mengaktifkan set signal ketiga
  digitalWrite(GREEN1_PIN, 1);
  digitalWrite(GREEN2_PIN, 1);
  digitalWrite(RED1_PIN, 0);
  digitalWrite(YELLOW1_PIN, 0);  
  digitalWrite(RED2_PIN, 0);
  digitalWrite(YELLOW2_PIN, 0);
  digitalWrite(YELLOW3_PIN, 0);
  digitalWrite(GREEN3_PIN, 0);
  delay(5000);
 
  digitalWrite(YELLOW3_PIN, 1); // Mengaktifkan lampu kuning
  digitalWrite(YELLOW1_PIN, 1); 
  digitalWrite(GREEN2_PIN, 0);
  digitalWrite(RED3_PIN, 0);
  digitalWrite(GREEN1_PIN, 0);
  delay(1000);

     
}