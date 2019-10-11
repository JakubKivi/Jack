#include <Arduino.h>

unsigned long currentTime;

//============ 7 SEG DISPLAY========//
#define segCLK 0
#define segDIO 1
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
#include "modules/keypad.h"

//==========LCD DISPLAY=============//
#include "modules/lcdDisplay.h"

//================RFID======================//
#include "modules/key.h"

void setup() {
  pinMode(13, OUTPUT);
  faceSetup();
  keypadSetup();
  lcdDisplaySetup();
  lcd.print("hejka");
  rfidSetup();
  display.setBrightness(0x0f);
  showNumber(123);
  showFace(*zgon);
  //lcd.clear();

}
void loop() {
  currentTime=millis();

  if(currentTime - displayTime>1000){
    dots?dots=0:dots=1;
    displayTime=millis();
  }


  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY){
    lcd.print(customKey);
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
