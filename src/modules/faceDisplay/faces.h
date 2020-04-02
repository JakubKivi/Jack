struct face{
  byte image[8][8];
  int size;
  int time;
};

face currentFace;

face sleepy, dead, happy, wink, szok, bob, piggy, menRun;


void facesInit(){
  sleepy.size=2;
  sleepy.time=1600;

  sleepy.image[0][0]=  B01100110;
  sleepy.image[0][1]=  B10000001;
  sleepy.image[0][2]=  B00000000;
  sleepy.image[0][3]=  B01100110;
  sleepy.image[0][4]=  B00000000;
  sleepy.image[0][5]=  B00000000;
  sleepy.image[0][6]=  B00011000;
  sleepy.image[0][7]=  B00000000;

  sleepy.image[1][0]=B01100110;
  sleepy.image[1][1]=B10000001;
  sleepy.image[1][2]=B00000000;
  sleepy.image[1][3]=B01100110;
  sleepy.image[1][4]=B00000000;
  sleepy.image[1][5]=B00011000;
  sleepy.image[1][6]=B00011000;
  sleepy.image[1][7]=B00000000;

  dead.size=1;
  dead.time=100000;

  dead.image[0][0]=B01100110;
  dead.image[0][1]=B10000001;
  dead.image[0][2]=B00000000;
  dead.image[0][3]=B01100110;
  dead.image[0][4]=B00000000;
  dead.image[0][5]=B00000000;
  dead.image[0][6]=B00011000;
  dead.image[0][7]=B00000000;

  happy.size=5;
  happy.time=300;

  happy.image[0][0]=B00000000;
  happy.image[0][1]=B01100110;
  happy.image[0][2]=B01100110;
  happy.image[0][3]=B00000000;
  happy.image[0][4]=B00000000;
  happy.image[0][5]=B01000010;
  happy.image[0][6]=B00111100;
  happy.image[0][7]=B00000000;

  happy.image[1][0]=B00000000;
  happy.image[1][1]=B01100110;
  happy.image[1][2]=B01100110;
  happy.image[1][3]=B00000000;
  happy.image[1][4]=B01000010;
  happy.image[1][5]=B01111110;
  happy.image[1][6]=B00111100;
  happy.image[1][7]=B00000000;

  happy.image[2][0]=B00000000;
  happy.image[2][1]=B01000010;
  happy.image[2][2]=B10100101;
  happy.image[2][3]=B00000000;
  happy.image[2][4]=B01111110;
  happy.image[2][5]=B01111110;
  happy.image[2][6]=B00111100;
  happy.image[2][7]=B00000000;

  happy.image[3][0]=B00000000;
  happy.image[3][1]=B01000010;
  happy.image[3][2]=B10100101;
  happy.image[3][3]=B00000000;
  happy.image[3][4]=B00100100;
  happy.image[3][5]=B00111100;
  happy.image[3][6]=B00011000;
  happy.image[3][7]=B00000000;

  happy.image[4][0]=B00000000;
  happy.image[4][1]=B01100110;
  happy.image[4][2]=B01100110;
  happy.image[4][3]=B00000000;
  happy.image[4][4]=B00100100;
  happy.image[4][5]=B00100100;
  happy.image[4][6]=B00011000;
  happy.image[4][7]=B00000000;

  wink.size=4;
  wink.time=300;

  wink.image[0][0]=B01100000;
  wink.image[0][1]=B10000110;
  wink.image[0][2]=B01100001;
  wink.image[0][3]=B01100110;
  wink.image[0][4]=B00000000;
  wink.image[0][5]=B00100100;
  wink.image[0][6]=B00011000;
  wink.image[0][7]=B00011000;

  wink.image[1][0]=B01100110;
  wink.image[1][1]=B10000001;
  wink.image[1][2]=B01100110;
  wink.image[1][3]=B01100110;
  wink.image[1][4]=B00000000;
  wink.image[1][5]=B00100100;
  wink.image[1][6]=B00011000;
  wink.image[1][7]=B00000000;

  wink.image[2][0]=B01100110;
  wink.image[2][1]=B10000001;
  wink.image[2][2]=B01100110;
  wink.image[2][3]=B01100110;
  wink.image[2][4]=B00000000;
  wink.image[2][5]=B00100100;
  wink.image[2][6]=B00011000;
  wink.image[2][7]=B00000000;

  wink.image[3][0]=B01100110;
  wink.image[3][1]=B10000001;
  wink.image[3][2]=B01100110;
  wink.image[3][3]=B01100110;
  wink.image[3][4]=B00000000;
  wink.image[3][5]=B00100100;
  wink.image[3][6]=B00011000;
  wink.image[3][7]=B00000000;



szok={
  {
    {
      B01100110,
      B10000001,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00011000,
      B00011000
    },{
      B00000000,
      B01100110,
      B10000001,
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B00011000
    }
  },
  2,
  800
};

bob = {
  {
    {
      B01100110,
      B10000001,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00100100,
      B00011000
    },{
      B00000000,
      B01100110,
      B10000001,
      B01100110,
      B01100110,
      B00000000,
      B00100100,
      B00011000
    }
  },
  2,
  500
};

piggy= {
  {
    {
      B01100110,
      B01100110,
      B00000000,
      B01111110,
      B10000001,
      B10100101,
      B10000001,
      B01111110
    },{
      B01100110,
      B01100110,
      B01111110,
      B10000001,
      B10100101,
      B10000001,
      B01111110,
      B00000000
    },{
      B01100110,
      B01100110,
      B00000000,
      B01111110,
      B10000001,
      B10100101,
      B10000001,
      B01111110
    },{
      B01000010,
      B10100101,
      B00000000,
      B01111110,
      B10000001,
      B10100101,
      B10000001,
      B01111110
    }
  },
  4,
  300
};

menRun = {
  {
    {
      B00011000,
      B00011000,
      B01110010,
      B10011100,
      B00010000,
      B00101000,
      B11000100,
      B00000010
    },{
      B00011000,
      B00011000,
      B00110000,
      B01011100,
      B01010000,
      B00011000,
      B01111000,
      B00010000
    },{
      B00011000,
      B00011000,
      B00010000,
      B00110000,
      B00111000,
      B00010000,
      B00110000,
      B00010000
    },{
      B00011000,
      B00011000,
      B00110000,
      B01011100,
      B00010000,
      B00011000,
      B01101000,
      B00010000
    },{
      B00011000,
      B00011000,
      B00110100,
      B01011100,
      B01010000,
      B00101000,
      B11001000,
      B00001000
    }
  },
  5,
  50
};

}
