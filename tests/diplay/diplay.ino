#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 0
#define DIO 1


TM1637Display display(CLK, DIO);

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
    display.showNumberDecEx(123, (0x80 >> 1), true); // liczba, przesuniecie bitowe(kropki na srodku, czy pokazywac zera jesli liczba nie jest 4 cyfrowa)
  }else{
    display.showNumberDecEx(123, (0x80 >> 0), true);
  }
}
