bool codeMode=0;

void logged(){
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY){
    if(wasInSleep)awake();
    lastActivity=millis();
    if(codeMode){
      if(customKey=='*'){
        if(!execute(int(code))){
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Enter Code");
          lcd.setCursor(2,1);
          lcd.print("Invalid Code");
          code=0;
          codeI=1000;
        }else{
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Enter Code");
          lcd.setCursor(6,1);
        }
      }else if(customKey=='#'){
        code=0;
        codeI=1000;
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("Enter Code");
        lcd.setCursor(6,1);
      }else{
        if(codeI>=1){
          code=code+((customKey-48)*codeI);
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Enter Code");
          lcd.setCursor(6,1);
          lcd.print( (int(code))/codeI );
          codeI=codeI/10;
        }else{
          /*code=0;
          codeI=1000;
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Enter Code");
          lcd.setCursor(6,1);/*
        }
      }
    }else{
      if (customKey != NO_KEY){
        if(customKey=='*'){
              codeMode=1;
              lcd.clear();
              lcd.setCursor(3,0);
              lcd.print("Enter Code");
              lcd.setCursor(6,1);
        }
      }
    }
  }
}

/*else if(customKey=='1'){
  lcd.clear();
  lcd.print(customKey);
  relay.toggle(socket);
}else if(customKey=='2'){
  lcd.clear();
  lcd.print(customKey);
  relay.toggle(lampManual);
}else if(customKey=='3'){
  lcd.clear();
  lcd.print(customKey);
  relay.toggle(lamp);
}else if(customKey=='4'){
  lcd.clear();
  lcd.print(customKey);
  relay.toggle(ironManual);
}else if(customKey=='5'){
  lcd.clear();
  lcd.print(customKey);
  relay.toggle(iron);
}else if(customKey=='6'){
  lcd.clear();
  lcd.print(customKey);
  lcd.clear();
  lcd.print(digitalRead(motionSensor));
}else{
  lcd.clear();
  lcd.print(customKey);
}
*/
