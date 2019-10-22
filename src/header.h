#include <Arduino.h>

#define STOP 1
#define NOSTOP 0

unsigned long currentTime;
char code[8];
int codeI=0;
String systemMode="logged off"; //logged, logged off, headadmin
String systemUser="no user"; //0 - no user, 1 - Admin , 2 - Asia, 3 - Mama , 4 - Tata

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
byte currentFace;
unsigned long facePrevTime;
int faceFrame=0;
#include "modules/faceDisplay/faceDisplay.h"

//==========KEYPAD=================//
#include "modules/keypad.h"

//==========LCD DISPLAY=============//
#include "modules/lcdDisplay.h"

//================RFID======================//
#include "modules/key.h"

//==========DHT11 tempsensor==================//
#include "modules/tempsensor.h"

#include "modules/relay.h"
#include "modules/buzz.h"

#include "functions.h"
#include "systemMode/logged.h"
#include "systemMode/loggedOff.h"
