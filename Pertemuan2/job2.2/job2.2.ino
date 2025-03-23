// Definisi pin untuk setiap segmen (A, B, C, D, E, F, G)
int segpin[] = {2, 3, 4, 5, 6, 7, 8};   // A, B, C, D, E, F, G
int digit[] = {9, 10};                  // Digit 1 (Puluhan), Digit 2 (Satuan)
int j;

// Array pola angka 0-9 untuk seven-segment common anode
int sevseg[10][7] = {
  {0, 0, 0, 0, 0, 0, 1},  // 0
  {1, 0, 0, 1, 1, 1, 1},  // 1
  {0, 0, 1, 0, 0, 1, 0},  // 2
  {0, 0, 0, 0, 1, 1, 0},  // 3
  {1, 0, 0, 1, 1, 0, 0},  // 4
  {0, 1, 0, 0, 1, 0, 0},  // 5
  {0, 1, 0, 0, 0, 0, 0},  // 6
  {0, 0, 0, 1, 1, 1, 1},  // 7
  {0, 0, 0, 0, 0, 0, 0},  // 8
  {0, 0, 0, 0, 1, 0, 0}   // 9
};

void setup() {
  // Atur semua pin segmen sebagai OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segpin[i], OUTPUT);
  }
  // Atur semua pin digit sebagai OUTPUT dan matikan awalnya (Common Anode)
  for (int i = 0; i < 2; i++) {
    pinMode(digit[i], OUTPUT);
    digitalWrite(digit[i], 1);
  }
  pinMode(11,OUTPUT);                 //Set pin 11 sebagai output
  pinMode(12,OUTPUT);                 //Set pin 12 sebagai output
}

// Fungsi untuk menampilkan angka pada digit tertentu
void Digittampil(int angka, int dig) {
  // Matikan semua digit terlebih dahulu
  for (int i = 0; i < 2; i++) {
    digitalWrite(digit[i], 1);
  }

  // Nyalakan segmen sesuai angka yang diinginkan
  for (int i = 0; i < 7; i++) {
    digitalWrite(segpin[i], sevseg[angka][i]);
  }

  // Aktifkan digit yang dipilih (0 untuk common anode)
  digitalWrite(digit[dig], 0);
  delay(5);                       // Delay kecil untuk multiplexing
  digitalWrite(digit[dig], 1);    // Matikan digit kembali
}

// Fungsi untuk menampilkan angka 2 digit (puluhan dan satuan)
void angkatampil(int bilangan) {
  int puluhan = bilangan / 10;    // Ambil digit puluhan
  int satuan = bilangan % 10;     // Ambil digit satuan

  for (int i = 0; i < 50; i++) {  // Refresh tampilan agar stabil
    Digittampil(puluhan, 0);      // Tampilkan puluhan
    Digittampil(satuan, 1);       // Tampilkan satuan
  }
}

void loop() {
  digitalWrite(11,HIGH);           //menyalakan LED
  digitalWrite(12,HIGH);           //Menyalakan LED
  for (int i = 0; i < 100; i++) {  // Hitung dari 00 sampai 99
    for (int j = 0; j < 2; j++) {  // Perulangan untuk mengatur counter setiap 1 detik
      angkatampil(i);
    }
  }
}
