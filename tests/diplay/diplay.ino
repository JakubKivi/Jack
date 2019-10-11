#include <Arduino.h>
#include <TM1637Display.h>

TM1637Display display(0, 1);

void setup()
{
  display.setBrightness(0x0f);
  display.showNumberDecEx(13, (0x80 >> 1), true); // liczba, przesuniecie bitowe(kropki na srodku, czy pokazywac zera jesli liczba nie jest 4 cyfrowa)
}

void loop()
{
  
}
