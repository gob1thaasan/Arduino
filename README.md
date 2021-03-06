# Arduino
Simple weekend Arduino UNO project. Each project folder contains a breadboard picture, code and a short video. Below is the list:
---
1.  TwoButton: adding first project which involves two buttons to control a LED. This project involves two inputs from the buttons to correspond to two outputs, one builtin LED connected to D13 and another LED connected to D9 directly. The demo video available at [Youtube](https://youtu.be/2UX8akIyRBY)

2.  Photoresister: or also known as Light-Dependent Resistor (LDR) is a resistor which varies the resistance based on the amount of light. This project involves a circuit that lights an LED when it is sufficiently dark in a room. I demonstrate the circuit by covering the photoresistor to simulate darkness, available at [Youtube](https://www.youtube.com/watch?v=hIxY1L2sM7U)

3. EEPROM: A sketch that allows a user to access data in (built-in) EEPROM using the serial monitor. In the serial monitor the user type one of two commands: `read` and `write`. 
    - "read" takes one argument, an EEPROM address. "For example, if the user types  `read 3` then the contents of EEPROM address 3 should be printed to the serial monitor. 

    - "write" takes two arguments, an EEPROM address and a value.  If the user types `write 3 10` then the value 10 should be written into address 3 of the EEPROM.
 
4. WaterSensor: A sketch where the water sensor will turn on when water is detected.  We have two outputs; the LED and buzzer is turned ON when water is detected and switch OFF when no water is present. Demo available at [Youtube](https://youtu.be/OcxmGYR4IWU)

5. Ultrasonic Sensor: This sketch show the usage of ultrasonic sensor which is a non-contact range detection tool with capability from 2 cm to 400 cm. A buzzer is added to this project, where when the obstacle is between 9cm-11cm, the buzzer is turned on. Demo available at [Youtube](https://youtu.be/QoMn5BVaquU)

6. RelayLamp: to turn on room lamp based on light intensity. This Arduino uno project uses LDR and relay module to control room lamp connected to AC power 240V.  Make sure the Photo-resister is away from the lamp. You can change the LDR with PIR. [Youtube](https://youtu.be/Pyk36gJZEBo) 

## References
- [Arduino Uno Board Details](https://store.arduino.cc/usa/arduino-uno-rev3)
- [Arduino Due Board Details](https://store.arduino.cc/usa/due)
1. [Arduino Laguage Reference](https://www.arduino.cc/reference/en)
2. [Arduino Libraries](https://www.arduino.cc/en/Reference/Libraries) 
3. [Arduino Shields](https://learn.sparkfun.com/tutorials/arduino-shields)
4. [List of Shields](http://playground.arduino.cc/Main/SimilarBoards)
5. [EEPROM Library](https://www.arduino.cc/en/Reference/EEPROM)
6. [SPI Library](https://www.arduino.cc/en/Reference/SPI)
7. [Servo Library](https://www.arduino.cc/en/Reference/Servo)
8. [Ethernet Shield](https://www.arduino.cc/en/Main/ArduinoEthernetShield)
9. [WiFi Shield](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoWiFiShield)
10. [Blynk](http://docs.blynk.cc/)
11. [Relay](https://www.circuitbasics.com/setting-up-a-5v-relay-on-the-arduino/) 
