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
  digitalWrite(2,0);                                              //pin 2 Mati
  digitalWrite(3,1);                                              //pin 3 Nyala
  digitalWrite(4,0);                                              //pin 4 Mati
  digitalWrite(5,1);                                              //pin 5 Nyala
  digitalWrite(6,0);                                              //pin 6 Mati
  digitalWrite(7,1);                                              //pin 7 Nyala
  digitalWrite(8,0);                                              //pin 8 Mati
  digitalWrite(9,1);                                              //pin 9 Nyala
}

