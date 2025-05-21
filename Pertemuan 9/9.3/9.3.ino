int LED = PC13;
 
void setup() {
  pinMode(LED, OUTPUT);
}
 
void loop() {
  // --- S: 3x beep 1 detik ---
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH); // buzzer ON
    delay(300);                   // 1 detik
    digitalWrite(LED, LOW);  // buzzer OFF
    delay(200);                    // jeda antar beep
  }
 
  delay(2000); // jeda antar pola
 
  // --- O: 3x beep 300 ms ---
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH); // buzzer ON
    delay(1000);                    // 300 ms
    digitalWrite(LED, LOW);  // buzzer OFF
    delay(1000);                    // jeda antar beep
  }
 
  delay(2000); // jeda antar pola 
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH); // buzzer ON
    delay(300);                   // 1 detik
    digitalWrite(LED, LOW);  // buzzer OFF
    delay(200);                    // jeda antar beep
  }
 
  delay(2000); // jeda antara SOS
}