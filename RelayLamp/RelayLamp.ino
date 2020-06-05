/*
A circuit that lights an LED when it is sufficiently dark in a room. 
I demonstrate the circuit by covering the photoresistor to simulate darkness.

Gobithaasan 17/5/2020

*/

int sensorPin = A0;    // pin for the photoresistor
int ledPin = 7;      // pin for the LED
int sensorValue = 0;  // variable to store the value coming from photoresistor
int outputValue = 0;        // value output adjusted using map function to control intensity

void setup() {
  pinMode(ledPin, OUTPUT); 
 // Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);   // read the value from photoresistor:
  outputValue = map(sensorValue, 0, 50, 0, 100); // map the sensorValue to the output you want

  //for debugging
 // Serial.print("sensor = "); // printout the value in serial window for debugging
 // Serial.print(sensorValue);
 // Serial.print("\t output = ");
 // Serial.println(outputValue);


  if (outputValue < 10){ //light intensity is low
  digitalWrite(ledPin, LOW); // turn on the relay
 // Serial.println(" on ");
  }
  else //light intensity is high
  digitalWrite(ledPin, HIGH); // turn off the relay
 // Serial.println(" off ");
}
