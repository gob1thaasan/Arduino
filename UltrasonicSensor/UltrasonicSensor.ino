/*
 * It offers non-contact range detection from 2 cm to 400 cm 
 */

#define Buzzer 7 // Buzzer Pin is pin 7
#define TriggerPin 8 // Trigger Pin of Ultrasonic Sensor
#define EchoPin 9 // Echo Pin of Ultrasonic Sensor


void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(Buzzer, OUTPUT);
}

void loop() {
   long TravelTime, cm;

   //clear trigger pin
   digitalWrite(TriggerPin, LOW);
   delayMicroseconds(1);
   
   //set trigger pin HIGH for 5 microseconds
   digitalWrite(TriggerPin, HIGH);
   delayMicroseconds(5);
   digitalWrite(TriggerPin, LOW);

   // Read the echo pin, return the travel time in microseconds
   TravelTime = pulseIn(EchoPin, HIGH);
   cm = TravelTime / 29 / 2;

   Serial.print("Distance(cm):");
   Serial.print(cm);
   Serial.println();

   if (9 < cm && cm < 11 ){
    tone(Buzzer, 1000);
   }
   else 
   noTone(Buzzer);
   
   //delay(500);
}
