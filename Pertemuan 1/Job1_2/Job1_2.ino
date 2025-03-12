void setup() {
  pinMode(2,OUTPUT);                                              //deklarasi PIN 2 sebagai OUTPUT
  pinMode(3,OUTPUT);                                              //deklarasi PIN 3 sebagai OUTPUT
  pinMode(4,OUTPUT);                                              //deklarasi PIN 4 sebagai OUTPUT
  pinMode(5,OUTPUT);                                              //deklarasi PIN 5 sebagai OUTPUT
  pinMode(6,OUTPUT);                                              //deklarasi PIN 6 sebagai OUTPUT
  pinMode(7,OUTPUT);                                              //deklarasi PIN 7 sebagai OUTPUT
  pinMode(8,OUTPUT);                                              //deklarasi PIN 8 sebagai OUTPUT
  pinMode(9,OUTPUT);                                              //deklarasi PIN 9 sebagai OUTPUT
}

void loop() {
    for (int pin = 2; pin <= 9; pin++) {                          //perulangan for untuk menyalakan LED
    digitalWrite(pin, HIGH);                                      //LED menyala sesuai indeks pin
    delay(200);                                                   //Jeda 200ms
    }
    for (int pin = 9; pin >= 2; pin--) {                          //perulangan for untuk Matikan LED
    digitalWrite(pin, LOW);                                       //LED mati sesuai indeks pin
    delay(200);                                                   //Jeda 200ms
  }
}


