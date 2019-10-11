#include <Arduino.h>

//rfid module
#include <SPI.h>
#include <MFRC522.h>

// 7 segment display module
#define segCLK 2
#define segDIO 3
#include "modules/display.h"

//face display module
#define faceDIN 6
#define faceCS 5
#define faceCLK 4
unsigned long currentTime;
unsigned long facePrevTime;
int faceFrame=0;
#include "modules/faceDisplay/faceDisplay.h"

//keypad modules
#include "modules/keypad.h"

//
#include "module/lcdDisplay.h"


void setup() {
  Serial.begin(9600);
  faceSetup();
  keypadSetup();
  lcdDisplaySetup();

}

void loop() {
  currentTime=millis();
  lcd.print("hejka");
  /*char customKey = customKeypad.getKey();

  if (customKey != NO_KEY){
    Serial.println(customKey);
  }*/

  //showFaceFrame(bob, 300, sizeof(bob)/8);


}
