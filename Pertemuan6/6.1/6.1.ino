// Program : membaca analog input A0
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup()
  {
    pinMode(A0,INPUT);
    lcd.begin(16, 2);
    lcd.print("ADC Channel 0");
    lcd.setCursor(0,1);
    lcd.print("ADC= ");
  }
void loop()
  {
int adc0 = analogRead(A0);
    lcd.setCursor(5,1);
    lcd.print(adc0);
    lcd.print( " ");
    delay(1000);
  }
