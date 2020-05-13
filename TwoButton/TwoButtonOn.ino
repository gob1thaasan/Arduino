/*

 Build a circuit that contains two pushbuttons, an LED, and any other basic components you think you need. 
 The LED should turn on when either the first button or the second button is pressed. 
 Only use your Arduino for power and ground.

two inputs: D2 and D7
two outputs: D13 and D9
 
 Gobithaasan 12/5/20
*/
const int buttonPinOne = 2;     // the number of the pushbutton one
const int buttonPinTwo = 7;     // the number of the pushbutton two
const int ledPin1 =  13;      // the builtin LED pin
const int ledPin2 =  9;     // external LED pin

// variable for reading the pushbutton status
int buttonStateOne = 0;         
int buttonStateTwo = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinOne, INPUT);
  pinMode(buttonPinTwo, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);

  // Print the state of the pushbutton value in serial window:
  Serial.print(buttonStateOne);
  Serial.print(buttonStateTwo);
  Serial.println();

  // check if either of the pushbutton is pressed. If it is, the buttonState is HIGH:
     if (buttonStateOne || buttonStateTwo) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
}
