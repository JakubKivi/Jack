#include <PCF8574.H>
PCF8574 relay;

#define socketON relay.digitalWrite(socket, 1)
#define ironON relay.digitalWrite(iron, 0)
#define ironManualON relay.digitalWrite(ironManual, 1)
#define lampON relay.digitalWrite(lamp, 0)
#define lampManualON relay.digitalWrite(lampManual, 1)

#define socketOFF relay.digitalWrite(socket, 0)
#define ironOFF relay.digitalWrite(iron, 1)
#define ironManualOFF relay.digitalWrite(ironManual, 0)
#define lampOFF relay.digitalWrite(lamp, 1)
#define lampManualOFF relay.digitalWrite(lampManual, 0)

int relaySetup(){
  relay.begin(0x3F);
  relay.pinMode(socket, OUTPUT);
  relay.pinMode(iron, OUTPUT);
  relay.pinMode(ironManual, OUTPUT);
  relay.pinMode(lamp, OUTPUT);
  relay.pinMode(lampManual, OUTPUT);
  socketON;
  lampManualOFF;
  lampOFF;
  ironManualOFF;
  ironOFF;
  return 1;
}
