#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

RTC_DS1307 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Waktu alarm yang ditentukan
const int alarmHour = 12;
const int alarmMinute = 07;
const int alarmSecond = 0;
const int buzzerPin = 8;

bool alarmActive = false;
unsigned long alarmStartMillis = 0;

void setup() {
  lcd.begin(16, 2);
  Wire.begin();
  rtc.begin();
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  if (!rtc.isrunning()) {
    lcd.print("RTC Error!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();

  // Cek apakah waktu saat ini adalah waktu alarm
  if (now.hour() == alarmHour && now.minute() == alarmMinute && now.second() == alarmSecond && !alarmActive) {
    alarmActive = true;
    alarmStartMillis = millis();
  }

  // Jika alarm aktif dan belum 10 detik, tampilkan "ALARM"
  if (alarmActive) {
    if (millis() - alarmStartMillis <= 10000) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("!! ALARM !!");
      // Buzzer nyala-mati tiap 250ms
      // digitalWrite(buzzerPin, HIGH);
      // delay(100);
      // digitalWrite(buzzerPin, LOW);
      // delay(100);
    } else {
      alarmActive = false;
      digitalWrite(buzzerPin, LOW);
      lcd.clear();
    }
  } else {
    // Tampilkan tanggal dan waktu jika alarm tidak aktif
    lcd.setCursor(0, 0);
    lcd.print("Date: ");
    lcd.print(now.day());
    lcd.print("/");
    lcd.print(now.month());
    lcd.print("/");
    lcd.print(now.year());

    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    if (now.hour() < 10) lcd.print("0");
    lcd.print(now.hour());
    lcd.print(":");
    if (now.minute() < 10) lcd.print("0");
    lcd.print(now.minute());
    lcd.print(":");
    if (now.second() < 10) lcd.print("0");
    lcd.print(now.second());
  }

  delay(1000);
}
