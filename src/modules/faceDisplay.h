#include "LedControl.h"

LedControl lc=LedControl(faceDIN, faceCLK, faceCS,2);  // Pins: DIN,CLK,CS, # of Display connected

byte fun1[] =
{
    B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B10000001,
  B01000010,
  B00111100
};

byte fun2[] =
{
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B00000000,
  B11111111,
  B01111110,
  B00111100
};

void faceSetup(){
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
}

void showFace(byte face[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,face[i]);
  }
}
