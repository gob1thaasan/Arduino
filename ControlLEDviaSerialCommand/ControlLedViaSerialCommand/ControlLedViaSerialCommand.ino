/*
A sketch that allows a user to access data in built-in EEPROM using the serial monitor. 
In the serial monitor the user should be able to type one of two commands: “read” and “write”. 
"read" takes one argument, an EEPROM address. "Write" takes two arguments, an EEPROM address and a value.

For example, if the user types “read 3” then the contents of EEPROM address 3 should be printed to the serial monitor. 
If the user types “write 3 10” then the value 10 should be written into address 3 of the EEPROM.

 Gobithaasan 24/5/2020
 
*/
#include <EEPROM.h>

  int data;   //to read data from EEPROM.
  int addrToRead, addrToWrite; //EEPROM address to start reading / writing
  int dataToStore; //to write data in EEPROM.


//warning message for wrong commands
void warning(){
  //Serial.println();
  Serial.println("Wrong command! try again");
}


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  //pinMode(13,OUTPUT); //uncomment if want to on the builtin LED when writing
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // An intro message:
    Serial.print("You have from 1 to ");
    Serial.print(EEPROM.length());
    Serial.println(" addresses to read and write.");
    Serial.println(" ==> to read: read address");
    Serial.println(" ==> to write: write address value");
    Serial.println("Do you want to read  or write?");
}

void loop() {
  // get any incoming bytes:
  if (Serial.available() > 0) {

    String command = Serial.readString();// command is string type variable.
    Serial.println();
    Serial.print("Received command => ");
    Serial.println(command);//display the string on serial monitor.

    /* 
     //Use for loop to read/print each the character in the string on Serial monitor
     Serial.print("The chars are: ");
     for (int i=0;i<command.length();i++){
        Serial.print(command[i]);
      }

     */
    
    if(command.indexOf("write")>=0) {
        //digitalWrite(13,HIGH); //uncomment if want to on the builtin LED when writing

          if (isSpace(command[5])) {
            //Serial.println("6th is a space character"); //uncomment if want to check if the char after read is a space
            
            if (isDigit(command[6])) {
            addrToWrite = command.substring(6).toInt();
            Serial.print("The address to write is: ");
            //Serial.println(addr);

             //check the built-in EEPROM size using pre-provided length function
              if (addrToWrite <= EEPROM.length()) {
                  //detect the position of second spacing after 6th position
                  int SecondSpacing = command.indexOf(' ',6);
                  //Serial.print(SecondSpacing);
                  //Serial.println(" <--- is the position of second spacing ");

                  dataToStore = command.substring(SecondSpacing+1).toInt();
                  
                  if (dataToStore <= 255){
                  Serial.print(" and the data to store is:");
                  Serial.println(dataToStore);

                  //write EEPROM addr with dataToStore: if similar data already available, then will not be written 
                  EEPROM.update(addrToWrite, dataToStore);   
                  }

                  else //cannot hold data beyond a byte; 255.
                  {
                  Serial.println();
                  warning();
                  Serial.println("data beyond 255.");
                  }
            }
              
              else //if (addr > EEPROM.length()) 
              {
                Serial.println();
                warning();
                Serial.println("Incorrect address.");
              }
            }
          

              else //if (!(isDigit(command[5]))) 
              {
              Serial.println();
              warning();
              }
            
            }
      
      else if (!isSpace(command[4])) {
      warning();
      }

    }
      
    
    else if(command.indexOf("read")>=0){
      if (isSpace(command[4])) {
      //Serial.println("5th is a space character"); //uncomment if want to check if the char after read is a space
            
            if (isDigit(command[5])) {
            addrToRead = command.substring(5).toInt();
            Serial.print("The address to read is: ");
            Serial.print(addrToRead);
            
              if (addrToRead <= EEPROM.length()) {
                  //Get the data from the EEPROM at position 'addrToRead'
                  data=EEPROM.read(addrToRead);
                  Serial.print(" and the value stored at this address is "); 
                  Serial.println(data);
              }
              
              else //if (addr > EEPROM.length()) 
              {
                Serial.println();
                warning();
                Serial.println("Incorrect address.");
              }
            }

              else //if (!(isDigit(command[5]))) 
              {
              Serial.println();
              warning();
              }
       }
     
      else if (!isSpace(command[4])) 
      {
      warning();
      }   
    }
    
    else{
       //junk command
       warning();
      Serial.println("Command neither read nor write!");
    }

    // add some space and ask for another read/write command:
    Serial.println("Do you want to read or write?");
    Serial.println();
  }
}
