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
