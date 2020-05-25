/*
  Character analysis operators

  Examples using the character analysis operators.
  Send any byte and the sketch will tell you about it.

  created 29 Nov 2010
  modified 2 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/CharacterAnalysis
*/

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("send any byte and I'll tell you everything I can about it");
  Serial.println();
}

void loop() {
  // get any incoming bytes:
  if (Serial.available() > 0) {
    /*
    int thisChar = Serial.read();

    // say what was sent:
    Serial.print("You sent me: \'");
    Serial.write(thisChar);
    Serial.print("\'  ASCII Value: ");
    Serial.println(thisChar);

    // analyze what was sent:
  
    if (isAlpha(thisChar)) {
      Serial.println("it's alphabetic");
    }
    
    if (isDigit(thisChar)) {
      Serial.println("it's a numeric digit");
    }
    
    if (isSpace(thisChar)) {
      Serial.println("it's a space character");
    }
*/

    String s1 = Serial.readString();// s1 is String type variable.
    Serial.print("Received Data => ");
    Serial.println(s1);//display same received Data back in serial monitor.
    if(s1.indexOf("on")>=0)
    {
        digitalWrite(13,HIGH);
    }
    if(s1.indexOf("off")>=0){
        digitalWrite(13,LOW);
    }
    delay(100);
    // add some space and ask for another byte:
    Serial.println();
    Serial.println("Give me input byte:");
    Serial.println();
  }
}
