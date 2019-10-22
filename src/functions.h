void error(int errorNr, bool stop, String errorM){
  showFace(*szok);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Error: ");
  lcd.print(errorNr);
  lcd.setCursor(0,1);
  lcd.print(errorM);
  Serial.println("Error: ");
  Serial.print(errorNr);
  Serial.println(errorM);
  while(stop){
    for(int i=0; i<errorNr; i++)
      analogWrite(buzz, 50);
      delay(300);
      analogWrite(buzz, 0);
      delay(300);
  }
  delay(3000);
}

int execute(char code[]){
	int nr=0;
	for(int i=0; i<8; i++){
		nr+=(int(code[i])-48)*pow(10, i);
	}
	switch(nr){
		case(1): relay.digitalWrite(lampManual, 0);
		break;
		case(2): relay.digitalWrite(lampManual, 1);
		break;
		case(3): relay.digitalWrite(lamp, 0);
		break;
		case(4): relay.digitalWrite(lamp, 1);
		break;
		case(5): relay.digitalWrite(ironManual, 0);
		break;
		case(6): relay.digitalWrite(ironManual, 1);
		break;
		case(7): relay.digitalWrite(iron, 0);
		break;
		case(8): relay.digitalWrite(iron, 1);
		break;
	}
  return 0;
}
