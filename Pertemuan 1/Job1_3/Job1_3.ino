int state=0;                                                    //deklarasi state bernilai 0
int Button = 10;                                                //deklarasi pin 10 sebagai Button

void setup() {
  Serial.begin(9600);                                           //Menampilkan Serial Monitor
  pinMode(2,OUTPUT);                                            //Pin 2 sebagai OUTPUT
  pinMode(3,OUTPUT);                                            //Pin 3 sebagai OUTPUT
  pinMode(4,OUTPUT);                                            //Pin 4 sebagai OUTPUT
  pinMode(5,OUTPUT);                                            //Pin 5 sebagai OUTPUT
  pinMode(6,OUTPUT);                                            //Pin 6 sebagai OUTPUT
  pinMode(7,OUTPUT);                                            //Pin 7 sebagai OUTPUT
  pinMode(8,OUTPUT);                                            //Pin 8 sebagai OUTPUT
  pinMode(9,OUTPUT);                                            //Pin 9 sebagai OUTPUT
  pinMode(Button,INPUT_PULLUP);                                 //Pin 10 sebagai INPUT
}

void running(){                                                 //Fungsi Untuk menyalakan running LED
    for (int pin = 2; pin <= 9; pin++) {                        //perulangan for untuk mematikan LED
    digitalWrite(pin, LOW);                                     //LED mati sesuai indeks pin
    }
   for (int pin = 2; pin <= 9; pin++) {                         //perulangan for untuk menyalakan LED
    if (Button == LOW){                                         //Jika Button ditekan maka program akan keluar dari perulangan
      return;
    }
    digitalWrite(pin, HIGH);                                    //LED menyala sesuai indeks pin
    delay(200);                                                 //Jeda 200ms
    }
    for (int pin = 9; pin >= 2; pin--) {                        //perulangan for untuk Matikan LED
      if(Button == LOW){                                        //Jika Button ditekan maka program akan keluar dari perulangan
        return;
      }
    digitalWrite(pin, LOW);                                     //LED mati sesuai indeks pin
    delay(200);                                                 //Jeda 200ms
  }
}
void genap(){                                                   //Membuat Fungsi Genap
  digitalWrite(2,0);                                            //pin 2 Mati
  digitalWrite(3,1);                                            //pin 3 Nyala
  digitalWrite(4,0);                                            //pin 4 Mati
  digitalWrite(5,1);                                            //pin 5 Nyala
  digitalWrite(6,0);                                            //pin 6 Mati
  digitalWrite(7,1);                                            //pin 7 Nyala
  digitalWrite(8,0);                                            //pin 8 Mati
  digitalWrite(9,1);                                            //pin 9 Nyala
}
void ganjil(){                                                  //Membuat Fungsi ganjil
  digitalWrite(2,1);                                            //pin 2 Nyala
  digitalWrite(3,0);                                            //pin 3 Mati
  digitalWrite(4,1);                                            //pin 4 Nyala
  digitalWrite(5,0);                                            //pin 5 Mati
  digitalWrite(6,1);                                            //pin 6 Nyala    
  digitalWrite(7,0);                                            //pin 7 Mati
  digitalWrite(8,1);                                            //pin 8 Nyala  
  digitalWrite(9,0);                                            //pin 9 Mati
}
void loop() {
  bool Tombol = digitalRead(Button);                            //Deklarasi Tombol = Button
  if (Tombol == LOW){                                           //Jika Tombol mendeteksi LOW
    delay(250);                                                 //Debouncing 250
    state ++;                                                   //nilai state +1
  }
  if (state > 3){                                               //Jika state >3 maka state kembali ke nilai 0
    state = 0;
  }
   if (state == 0){                                             //Jika state bernilai 0 maka fungsi running berjalan
    running();
   }
   else if (state == 1){                                        //Jika state bernilai 1 maka fungsi ganjil berjalan
    ganjil();
   }
   else {                                                       //Jika tidak maka fungsi genap berjalan
    genap();
   }
   Serial.println(state);                                       //Menampilkan state pada serial monitor
}



