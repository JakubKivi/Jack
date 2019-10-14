#include <Arduino.h>

unsigned long currentTime;
#define buzz 5
#define motionSensor A3
#define ironManual 5
#define iron 6
#define lampManual 7
#define lamp 3
#define socket 4

//============ 7 SEG DISPLAY========//
#define segCLK 6
#define segDIO 7
unsigned long displayTime=0;
bool dots=0;
#include "modules/display.h"

//============FACE DISPLAY==========//
#define faceDIN 3
#define faceCS 2
#define faceCLK 4
unsigned long facePrevTime;
int faceFrame=0;
#include "modules/faceDisplay/faceDisplay.h"

//==========KEYPAD=================//
/*
I2C device found at address 0x27  !
I2C device found at address 0x38  !
I2C device found at address 0x3F  !
*/
#include "modules/keypad.h"

//==========LCD DISPLAY=============//
#include "modules/lcdDisplay.h"

//================RFID======================//
#include "modules/key.h"

//==========DHT11 tempsensor==================//
#define DHT11_PIN 8
#include "modules/tempsensor.h"

#include <PCF8574.H>
PCF8574 relay;

void setup() {
  displayTime=millis();

  pinMode(buzz, OUTPUT);
  analogWrite(buzz, 100);
  delay(500);
  digitalWrite(buzz, 0);
  analogWrite(buzz, 150);
  delay(500);
  digitalWrite(buzz, 0);
  analogWrite(buzz, 50);
  delay(500);
  digitalWrite(buzz, 0);

  faceSetup();
  keypadSetup();
  lcdDisplaySetup();
  tempsensorSetup();
  rfidSetup();
  display.setBrightness(0x0f);
  showNumber(143);
  showFace(*szok);
  lcd.print("hejka");
  //lcd.clear()
  relay.begin(0x3F);
  relay.pinMode(socket, OUTPUT);
  relay.pinMode(iron, OUTPUT);
  relay.pinMode(ironManual, OUTPUT);
  relay.pinMode(lamp, OUTPUT);
  relay.pinMode(lampManual, OUTPUT);
}
void loop() {
  //relay.toggle(socket);
  //relay.toggle(lamp);
  //relay.toggle(lampManual);
  //relay.toggle(ironManual);

  currentTime=millis();

  if(currentTime - displayTime>1000){
    dots?dots=0:dots=1;
    displayTime=millis();
  }



  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY){
    if(customKey=='*'){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(int(dht.getHumidity()));
      lcd.print("%RH | ");
      lcd.setCursor(0,1);
      lcd.print(int(dht.getTemperature()));
      lcd.println("*C");
    }else   if(customKey=='#'){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(digitalRead(motionSensor));
    }else   if(customKey=='9'){
      relay.toggle(lamp);
    }else   if(customKey=='8'){
      relay.toggle(iron);
    }else   if(customKey=='7'){
      relay.toggle(socket);
    }else{
    lcd.print(customKey);
    }
  }

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    switch(rfidRead()){
      case 1:
        lcd.clear();
        lcd.print("Kivi");
        break;
      case 2:
        lcd.clear();
        lcd.print("Asia");
        break;
      case 3:
        lcd.clear();
        lcd.print("Mama");
        break;
      case 4:
        lcd.clear();
        lcd.print("Tata");
        break;
      case 5:
        lcd.clear();
        lcd.print("Skrytka");
        break;
      case 6:
        lcd.clear();
        lcd.print("Karta");
        break;
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

}
