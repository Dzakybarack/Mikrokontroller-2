const int colPins[5] = {9, 10, 11, 12, 13};  // Kolom (aktif LOW)
const int rowPins[7] = {2, 3, 4, 5, 6, 7, 8}; // Baris (aktif HIGH)

byte pattern[5][14] = {
  {1,0,0,1,0,0,1,  1,1,1,1,1,1,1,  },  // Kolom 1
  {1,0,0,1,0,0,1,  1,0,0,0,0,0,1,  }, // Kolom 2
  {1,0,0,1,0,0,1,  1,0,0,0,0,0,1,  },  // Kolom 3
  {1,0,0,1,0,0,1,  1,0,0,0,0,0,1,  },  // Kolom 4
  {0,1,1,1,1,1,0,  0,1,1,1,1,1,0,  }   // Kolom 5
};

void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int offset = 0; offset <= 7; offset++) { // 14-7 = 7 langkah scroll
    for (int t = 0; t < 25; t++) { // Tampilkan frame ini selama beberapa siklus
      for (int col = 0; col < 5; col++) {
        // Aktifkan hanya 1 kolom (LOW), lainnya HIGH
        for (int c = 0; c < 5; c++) {
          digitalWrite(colPins[c], HIGH);
        }
        digitalWrite(colPins[col], LOW);

        // Atur baris (7 baris per frame)
        for (int row = 0; row < 7; row++) {
          digitalWrite(rowPins[row], pattern[col][row + offset] ? HIGH : LOW);
        }
        delay(2);
      }
    }
  }
  for (int offset = 7; offset >= 0; offset--) { // 14-7 = 7 langkah scroll
    for (int t = 0; t < 25; t++) { // Tampilkan frame ini selama beberapa siklus
      for (int col = 0; col < 5; col++) {
        // Aktifkan hanya 1 kolom (LOW), lainnya HIGH
        for (int c = 0; c < 5; c++) {
          digitalWrite(colPins[c], HIGH);
        }
        digitalWrite(colPins[col], LOW);

        // Atur baris (7 baris per frame)
        for (int row = 0; row < 7; row++) {
          digitalWrite(rowPins[row], pattern[col][row + offset] ? HIGH : LOW);
        }
        delay(2);
      }
    }
  }
}