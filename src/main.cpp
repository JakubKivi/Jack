#include "header.h"

void setup() {

  displayTime=millis();

  if(!buzzSetup())error(1, STOP, "buzzSetup() returned 0");
  if(!faceSetup())error(1, STOP, "faceSetup() returned 0");
  if(!keypadSetup())error(1, STOP, "keypadSetup() returned 0");
  if(!lcdDisplaySetup())error(1, STOP, "lcdDisplaySetup() returned 0");
  if(!tempsensorSetup())error(1, STOP, "tempsensorSetup() returned 0");
  if(!rfidSetup())error(1, STOP, "rfidSetup() returned 0");
	if(!displaySetup())error(1, STOP, "isplaySetup() returned 0");
  if(!relaySetup())error(1, STOP, "relaySetup() returned 0");

  currentFace=bob;
  lcd.print("hejka");
  lastActivity=millis();
}

void loop() {

  currentTime=millis();

	if(systemMode=="logged")logged();
	else if(systemMode=="logged off")loggedOff();
  else error(2, STOP, "unknown systemMode");

  if(currentTime - displayTime>1000){
    dots?dots=0:dots=1;
    displayTime=millis();
  }
  //if(currentTime-lastActivity>10000)fallAsleep();

  face(currentFace.image, currentFace.time, currentFace.size);

}
