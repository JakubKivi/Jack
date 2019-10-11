#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27,20,4);

void lcdDisplaySetup(){
  lcd.begin(16,2);   // Inicjalizacja LCD 2x16

  lcd.backlight(); // zalaczenie podwietlenia
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
}
