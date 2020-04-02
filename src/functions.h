void error(int errorNr, bool stop, String errorM){
  currentFace=dead;
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

void fallAsleep(){
  wasInSleep=1;
  currentFace=sleepy;
  //lcd.noBacklight();
}

void awake(){
  //lcd.backlight();
  currentFace=bob;
  wasInSleep=0;
  lastActivity=millis();
}

int execute(int code){
	switch(code){
		case(1): lampON;
    return 1;
		break;
    case(2): lampOFF;
    return 1;
		break;
    case(3): lampManualON;
    return 1;
		break;
    case(4): lampManualOFF;
    return 1;
		break;
	}
  return 0;
}
