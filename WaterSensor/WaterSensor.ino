   /* 
    *  The water sensor will turn on when water is detected.
    *  The LED and buzzer is turned ON when water is detected, 
    *  and switch OFF when no water is present 
   */


#define WaterSensor 8 // Water sensor to pin 8
#define Buzzer 9 // Buzzer(piezo) to arduino pin 9
#define LED 10 // LED to Digital pin 10 


void setup() {
   pinMode(WaterSensor, INPUT); // Water Sensor as input
   pinMode(Buzzer, OUTPUT); // buzzer is an Output
   pinMode(LED, OUTPUT); // LED is an Output
}

void loop() {
   
   if( digitalRead(WaterSensor) == HIGH) {
      digitalWrite(LED,HIGH);
      tone(Buzzer, 1000);
      
   }else {
      digitalWrite(LED,LOW);
      noTone(Buzzer);
   }
}
