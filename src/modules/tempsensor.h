#define DHT11_PIN 8
#include "DHT.h"

DHT dht;

int tempsensorSetup(){
  dht.setup(DHT11_PIN);
  return 1;
}
