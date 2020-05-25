/*
 * EEPROM control via serial window
 *
 * Reads and stores values (val) from serial window for a given address (addr) input 0 into the EEPROM.
 * These values will stay in the EEPROM when the board is turned off and may be retrieved later by another sketch.
 * 
 * Gobithaasan 23/5/2020
 */
#include <EEPROM.h>

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
String inputRead, inputWrite; 
int addr = 0;
int val = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("Enter read add or write add val: ");
  Serial.println();
}

void loop() {

  // get any incoming bytes:
  if (Serial.available() > 0) {
    int input = Serial.read();

    // say what was sent:
    Serial.print("You sent me: \'");
    Serial.write(input);
    Serial.print("\'  ASCII Value: ");
    Serial.println(input);

        
        if (isAlpha(input)) {
          Serial.println("it's alphabetic");
        }
        
        if (isSpace(input)) {
          Serial.println("it's a space character");
        }

        if (isDigit(input)) {
          Serial.println("it's a numeric digit");
        }
  }

String input;

  if (input == "read") {
    Serial.println("input == \"read\"");
  }
  else if (input =="write") {
    Serial.println("input == \"write\"");
  }
  else { // input is neither read nor write:
    Serial.println("input == \"wrong command\"");
  }
 

/*

  EEPROM.update(addr, val); //Update the particular EEPROM addr with val
*/



  delay(100);
    // add some space and ask for another byte:
    Serial.println();
    Serial.println("Give me anotheer instruction:");
    Serial.println();
}
