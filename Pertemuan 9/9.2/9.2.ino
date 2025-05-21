int Led[] = {PB12, PB13, PB14, PB15};


void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(Led[i], OUTPUT);
  } 
}

void loop() {
    for(int k = 0; k < 4; k++) {
      digitalWrite(Led[k], HIGH);
      delay(200);
      digitalWrite(Led[k], LOW);
      // delay(500);
      
    }
    for(int k=2; k >= 0; k--){
      digitalWrite(Led[k], HIGH);
      delay(200);
      digitalWrite(Led[k], LOW); 
    }
    
  
}
