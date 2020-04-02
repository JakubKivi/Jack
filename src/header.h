#include <Arduino.h>

#define STOP 1
#define NOSTOP 0

unsigned long currentTime;
unsigned long lastActivity;
bool wasInSleep=0;

float code=0;
int codeI=1;
String systemMode="logged off"; //logged, logged off, headadmin
String systemUser="no user"; //0 - no user, 1 - Admin , 2 - Asia, 3 - Mama , 4 - Tata

#define motionSensor 48

#define ironManual 5
#define iron 6
#define lampManual 7
#define lamp 3
#define socket 4

//============ 7 SEG DISPLAY========//
#define segCLK 46// uno 6
#define segDIO 44//uno 7
unsigned long displayTime=0;
bool dots=0;
int actualNumber=8888;
#include "modules/display.h"

//============FACE DISPLAY==========//
#define faceDIN 38   //uno 3  //brazowy
#define faceCS 40   //uno 2   //czerwony        >te takie 3 razem
#define faceCLK 42  //uno 4  //pomaranczowy   /42 40 38
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
