#include <PCF8574.H>
PCF8574 relay;

int relaySetup(){
  relay.begin(0x3F);
  relay.pinMode(socket, OUTPUT);
  relay.pinMode(iron, OUTPUT);
  relay.pinMode(ironManual, OUTPUT);
  relay.pinMode(lamp, OUTPUT);
  relay.pinMode(lampManual, OUTPUT);
  return 1;
}
