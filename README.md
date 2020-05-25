# Arduino
Simple weekend Arduino UNO project. Each project folder contains a breadboard picture, code and a short video. Below is the list:
---
1.  TwoButton: adding first project which involves two buttons to control a LED. This project involves two inputs from the buttons to correspond to two outputs, one builtin LED connected to D13 and another LED connected to D9 directly. The demo video available at [Youtube](https://youtu.be/2UX8akIyRBY)

2.  Photoresister: or also known as Light-Dependent Resistor (LDR) is a resistor which varies the resistance based on the amount of light. This project involves a circuit that lights an LED when it is sufficiently dark in a room. I demonstrate the circuit by covering the photoresistor to simulate darkness, available at [Youtube](https://www.youtube.com/watch?v=hIxY1L2sM7U)

3. EEPROM: A sketch that allows a user to access data in built-in EEPROM using the serial monitor. In the serial monitor the user type one of two commands: “read” and “write”. 
    - "read" takes one argument, an EEPROM address. "Write" takes two arguments, an EEPROM address and a value. For example, if the user types “read 3” then the contents of EEPROM address 3 should be printed to the serial monitor. 

    - If the user types “write 3 10” then the value 10 should be written into address 3 of the EEPROM.
