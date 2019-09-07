#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000


TM1637Display display(CLK, DIO);

unsigned long lTime;
unsigned long cTime;
bool dots=1;

void setup()
{
  cTime=millis();
  
}

void loop()
{
  display.setBrightness(0x0f);
  cTime=millis();
  if(cTime - lTime>1000){
    dots?dots=0:dots=1;
    lTime=millis();
  }/*
  if(dots){
    uint8_t data[] = { 0x00, 0x80, 0x00, 0x00 };
    display.setSegments(data);
  }else{
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00 };
    display.setSegments(data);
  }*/
  
  display.showNumberDec(8853);
}
