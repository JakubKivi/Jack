#include "LedControl.h"
#include "faces.h"

LedControl lc=LedControl(faceDIN, faceCLK, faceCS,2);  // Pins: DIN,CLK,CS, # of Display connected

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

void showFaceFrame(const byte face[][8], int frameDelay, int x){
  showFace(face[faceFrame]);
  if(currentTime-facePrevTime>frameDelay){
      faceFrame+1 < x ? faceFrame++ : faceFrame=0;
      facePrevTime=millis();
  }
}
