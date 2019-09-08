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
  }
  if(dots){
    display.showNumberDecEx(8888, (0x80 >> 1), true); // liczba, przesuniecie bitowe(kropki na srodku, czy pokazywac zera jesli liczba nie jest 4 cyfrowa)
  }else{
    display.showNumberDecEx(8888, true);
  }
}
