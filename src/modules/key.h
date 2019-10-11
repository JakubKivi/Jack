#include <SPI.h>
#include <MFRC522.h>

const byte Kivi[] = {0xF2, 0xE1, 0x2D, 0x83};
const byte Asia[] = {0xA9, 0x8B, 0x48, 0x59};
const byte Mama[] = {0x43, 0x7B, 0xB5, 0x63};
const byte Tata[] = {0x43, 0x65, 0xB4, 0x63};
const byte Skrytka[] = {0xCC, 0xFA, 0xB4, 0x63};

const byte Karta[] = {0x97, 0x5F, 0x6D, 0x11};

MFRC522 rfid(10, 9);
MFRC522::MIFARE_Key key;

void rfidSetup(){
  SPI.begin();
  rfid.PCD_Init();
}

int rfidRead(){
  if (rfid.uid.uidByte[0] == Kivi[0] &&
        rfid.uid.uidByte[1] == Kivi[1] &&
        rfid.uid.uidByte[2] == Kivi[2] &&
        rfid.uid.uidByte[3] == Kivi[3])

      return(1);

  else if (rfid.uid.uidByte[0] == Asia[0] &&
        rfid.uid.uidByte[1] == Asia[1] &&
        rfid.uid.uidByte[2] == Asia[2] &&
        rfid.uid.uidByte[3] == Asia[3])

    return(2);

  else if (rfid.uid.uidByte[0] == Mama[0] &&
        rfid.uid.uidByte[1] == Mama[1] &&
        rfid.uid.uidByte[2] == Mama[2] &&
        rfid.uid.uidByte[3] == Mama[3])

    return(3);

  else if (rfid.uid.uidByte[0] == Tata[0] &&
        rfid.uid.uidByte[1] == Tata[1] &&
        rfid.uid.uidByte[2] == Tata[2] &&
        rfid.uid.uidByte[3] == Tata[3])
  
    return(4);

  else if (rfid.uid.uidByte[0] == Skrytka[0] &&
        rfid.uid.uidByte[1] == Skrytka[1] &&
        rfid.uid.uidByte[2] == Skrytka[2] &&
        rfid.uid.uidByte[3] == Skrytka[3])

    return(5);

  else if (rfid.uid.uidByte[0] == Karta[0] &&
        rfid.uid.uidByte[1] == Karta[1] &&
        rfid.uid.uidByte[2] == Karta[2] &&
        rfid.uid.uidByte[3] == Karta[3])

    return(6);

}
