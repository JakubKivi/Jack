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


void setup() {
  faceSetup();
}

void loop() {
  showFace(fun1);
  delay(500);
  showFace(fun2);
  delay(500);
}
