void logged(){
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY){
  if(customKey=='*'){
    lcd.clear();
    if(!execute(*code)){
      lcd.clear();
      lcd.print("Invalid Code");
    }
  }else if(customKey=='#'){
    code[codeI-1]=0;
    codeI--;
    lcd.clear();
    for(int i=0; i<codeI; i++){
      lcd.print(code[i]);
    }
  }else{
    if(codeI<8){
      code[codeI]=customKey;
      codeI++;
      lcd.print(customKey);
    }
  }
}
}
