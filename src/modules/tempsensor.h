#include "DHT.h"

DHT dht;

tempsensorSetup(){
  dht.setup(DHT11_PIN);
}
