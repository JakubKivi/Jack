#include <Arduino.h>

unsigned long currentTime;
char code[8];
int codeI=0;
int systemMode=0; //0 - woke up, 1 - logged, 2 - logged off, 3 - tests
int systemUser=0; //0 - no user, 1 - Admin , 2 - Asia      , 3 - Mama , 4 - Tata

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

int execute(char code[]){
	int nr=0;
	for(int i=0, i<8, i++){
		nr=(int(code[i])-48)*pow(10, i);
	}
	switch(nr){
		case(1)relay.digitalWrite(lampManual, 0);
		break;
		case(2)relay.digitalWrite(lampManual, 1);
		break;
		case(3)relay.digitalWrite(lamp, 0);
		break;
		case(4)relay.digitalWrite(lamp, 1);
		break;
		case(5)relay.digitalWrite(ironManual, 0);
		break;
		case(6)relay.digitalWrite(ironManual, 1);
		break;
		case(7)relay.digitalWrite(iron, 0);
		break;
		case(8)relay.digitalWrite(iron, 1);
		break;
	}
}


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
  
  currentTime=millis();

  if(currentTime - displayTime>1000){
    dots?dots=0:dots=1;
    displayTime=millis();
  }


	if(systemMode==1){
		if()
		  char customKey = customKeypad.getKey();
		  if (customKey != NO_KEY){
			if(customKey=='*'){
				lcd.clear();
				if(!execute(&code)){
					lcd.clear();
					lcd.print("Invalid Code");
				}
			}else if(customKey=='#'){
				code[codeI-1]=0;
				codeI--;
				lcd.clear();
				for(int i=0; i<codeI; i++){
					lcd.print(code[i]);
				}
			}else{
				if(codeI<8){
					code[codeI]=customKey;
					codeI++;
					lcd.print(customKey);
				}
			}
	  }
	}
	else if(systemMode=2){
	  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
		switch(rfidRead()){
		  case 1:
			lcd.clear();
			lcd.print("Logged as");
			lcd.setCursor(0, 1);
			lcd.print("Admin");
			systemUser = 1;
			systemMode = 1;
			break;
		  case 2:
			lcd.clear();
			lcd.print("Logged as");
			lcd.print("Asia");
			systemUser = 2;
			systemMode = 1;
			break;
		  case 3:
			lcd.clear();
			lcd.print("Logged as");
			lcd.setCursor(0, 1);
			lcd.print("Mama");
			systemUser = 3;
			systemMode = 1;
			break;
		  case 4:
			lcd.clear();
			lcd.print("Logged as");
			lcd.setCursor(0, 1);
			lcd.print("Tata");
			systemUser = 4;
			systemMode = 1;
			break;
		  case 6:
			lcd.clear();
			lcd.print("Logged as");
			lcd.setCursor(0, 1);
			lcd.print("Admin");
			systemUser = 1;
			systemMode = 1;
			break;
		}
		rfid.PICC_HaltA();
		rfid.PCD_StopCrypto1();
	  }
	}
}
