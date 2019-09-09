#include <Arduino.h>

//rfid module
#include <SPI.h>
#include <MFRC522.h>

// 7 segment display module
#define segCLK 2
#define segDIO 3
#include "modules\\display.h"

//face display module
#define faceDIN 6
#define faceCS 5
#define faceCLK 4
#include "modules\\faceDisplay.h"

//keypad modules
#include "modules\\keypad.h"

void setup() {
  faceSetup();
  keypadBegin();
  Serial.begin(9600);
}

void loop() {
  /*char customKey = customKeypad.getKey();

  if (customKey != NO_KEY){
    Serial.println(customKey);
  }*/
}
