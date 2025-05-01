
float suhu;
float tegangan;
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  lcd.begin(16,2);
  lcd.print("Tegangan =  ");
  lcd.setCursor(0,1);
  lcd.print("Suhu = ");
}

void loop() {
  int nilaiADC = analogRead(A0);
  suhu = (nilaiADC * 5.0 / 1023.0) * 100;
  tegangan = suhu/100;
  
  lcd.setCursor(11,0);
  lcd.println(tegangan);
  lcd.setCursor(7,1);
  lcd.print(suhu);
  lcd.println(" C  ");

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" °C");

  delay(1500);
}
  // Compare
//   if (suhu > 30.0) {
//     Serial.println("Suhu di atas 30°C");
    
//     // Bisa nyalakan kipas, buzzer, dsb
//   } else {
//     Serial.println("Suhu normal");
//   }

//   delay(1000); // delay 1 detik
// }

