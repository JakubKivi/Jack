void loggedOff(){
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    switch(rfidRead()){
      case 1:
        lcd.clear();
        lcd.print("Logged as");
        lcd.setCursor(0, 1);
        systemUser = "Admin";
        lcd.print(systemUser);
        systemMode = "logged";
      break;
      case 2:
        lcd.clear();
        lcd.print("Logged as");
        systemUser = "Asia";
        lcd.print(systemUser);
        systemMode = "logged";
      break;
      case 3:
        lcd.clear();
        lcd.print("Logged as");
        lcd.setCursor(0, 1);
        systemUser = "Mama";
        lcd.print(systemUser);
        systemMode = "logged";
      break;
      case 4:
        lcd.clear();
        lcd.print("Logged as");
        lcd.setCursor(0, 1);
        systemUser = "Tata";
        lcd.print(systemUser);
        systemMode = "logged";
      break;
      case 6:
        lcd.clear();
        lcd.print("Logged as");
        lcd.setCursor(0, 1);
        systemUser = "Admin";
        lcd.print(systemUser);
        systemMode = "Admin";
      break;
    }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  }
}
