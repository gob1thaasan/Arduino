/*
 * This sketch show the usage of ultrasonic sensor which is a non-contact range detection tool with capability from 2 cm to 400 cm.
 * A buzzer is added to this code, where when the obstacle is between 9-11cm, the buzzer is turned on.
 */

#define Buzzer 7 // Buzzer Pin is pin 7
#define TriggerPin 8 // Trigger Pin of Ultrasonic Sensor
#define EchoPin 9 // Echo Pin of Ultrasonic Sensor


void setup() {
   Serial.begin(9600); // Starting Serial Terminal for reading the distance of the object
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(Buzzer, OUTPUT);
}

void loop() {
   long TravelTime, cm;

   //clear trigger pin for trigger to occur
   digitalWrite(TriggerPin, LOW);
   delayMicroseconds(1);
   
   //set trigger pin HIGH for 5 microseconds, then turn off
   digitalWrite(TriggerPin, HIGH);
   delayMicroseconds(5);
   digitalWrite(TriggerPin, LOW);

   // Read the echo pin, return the travel time of echo in microseconds
   TravelTime = pulseIn(EchoPin, HIGH);
   
   //convert the travel time in cm
   cm = TravelTime / 29 / 2;

  //display in serial monitor
   Serial.print("Distance(cm):");
   Serial.print(cm);
   Serial.println();

// setting buzzer on when the object is between 9cm to 11cm
   if (9 < cm && cm < 11 ){
    tone(Buzzer, 1000);
   }
   else 
   noTone(Buzzer);

}
