/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
    Use with I2C i/o G. D. (Joe) Young Feb 28/12
*/
#include <Keypad_I2C.h>
#include <Keypad.h>        // GDY120705
#include <Wire.h>

#define I2CADDR 0x38

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 5}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad_I2C customKeypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS, I2CADDR); 

void setup(){
//  Wire.begin( );
  customKeypad.begin( );        // GDY120705
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
      if (customKey != NO_KEY){
       Serial.print(customKey);
      }
}
