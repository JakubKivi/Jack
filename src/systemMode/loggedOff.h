void loggedOff(){
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    if(rfidRead()<6 && rfidRead()>0 && rfidRead()!=5){
      lcd.clear();
      lcd.print("Logged as ");
      lcd.setCursor(0, 1);
      if(wasInSleep)awake();
    }
    switch(rfidRead()){
      case 1:
        systemUser = "Kivi";
        lcd.print(systemUser);
      break;
      case 2:
        systemUser = "Asiunia";
        lcd.print(systemUser);
      break;
      case 3:
        systemUser = "Mama";
        lcd.print(systemUser);
      break;
      case 4:
        systemUser = "Tata";
        lcd.print(systemUser);
      break;
      case 6:
        systemUser = "Admin";
        lcd.print(systemUser);
        systemMode = "Admin";
      break;
    }
    if(systemMode!="Admin")systemMode = "logged";
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  }
}
