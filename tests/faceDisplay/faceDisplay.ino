#include "LedControl.h"

LedControl lc=LedControl(4,3,2,2);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long currentTime;
unsigned long facePrevTime;
int faceFrame=0;
#include "faces.h"
#include "faceFunctions.h"

void setup()
{
  currentTime=millis();
  facePrevTime=millis();
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
}

void loop()
{
  currentTime=millis();
  showFaceFrame(bob, 300, sizeof(bob)/8);
}
