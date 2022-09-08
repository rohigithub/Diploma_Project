//Code for base node arduino uno controller:
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3);
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
const byte address1[6] = "00002";
#include <LiquidCrystal.h>
String RFIDS, myName;
String inChar;
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
RFID.begin(9600);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.openWritingPipe(address1);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("TRAFFIC LOAD");
lcd.setCursor(0, 1);
lcd.print("MINIMIZATION");
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("USING IOT");
lcd.setCursor(0, 1);
lcd.print("BASE NODE");
delay(1000);
lcd.clear();
}

void loop()
{
radio.stopListening();
delay(2000);
char text1 = '1';
radio.write(&text1, sizeof(text1));
radio.startListening();
while (!radio.available());
char text2;
radio.read(&text2, sizeof(text2));
lcd.setCursor(0, 0);
lcd.clear();
lcd.print("SENSOR NODE 1");
lcd.setCursor(0, 1);
lcd.print(text2);
delay(2000);
lcd.clear();
radio.stopListening();
delay(2000);
char text3 = '2';
radio.write(&text3, sizeof(text3));
radio.startListening();
while (!radio.available());
char text4;
radio.read(&text4, sizeof(text4));
lcd.setCursor(0, 0);
lcd.print("SENSOR NODE 2");
lcd.setCursor(0, 1);
lcd.print(text4);
delay(2000);
lcd.clear();
radio.stopListening();
delay(1000);
if (text2 == '1')
{
for (int i = 0; i < 11; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE A");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
if (text2 == '2')
{
for (int i = 0; i < 21; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE A");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
if (text2 == '3')
{
for (int i = 0; i < 31; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE A");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
if (text4 == '1')
{
for (int i = 0; i < 11; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE B");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
if (text4 == '2')
{
for (int i = 0; i < 21; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE B");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
if (text4 == '3')
{
for (int i = 0; i < 31; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE B");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
for (int i = 0; i < 11; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE C");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
for (int i = 0; i < 11; i++)
{
lcd.setCursor(0, 0);
lcd.print("LANE D");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
if (Serial.available() > 0)
{
Event();
}
if (RFID.available() > 0)
{
RFIDCHECK();
}
}
}
void RFIDCHECK()
{
myName = RFID.readString();
lcd.setCursor(0, 0);
lcd.print("RFID TAG");
lcd.setCursor(0, 1);
lcd.print(myName);
delay(2000);
lcd.clear();
if (myName.equals(RFIDS))
{
lcd.setCursor(0, 0);
lcd.print("STLONE CAR DETECTED");
lcd.setCursor(0, 1);
lcd.print("........");
delay(3000);
lcd.clear();
Serial.print(RFIDS);
}
}
void Event()
{
lcd.setCursor(0, 0);
lcd.print("IN SERIAL EVENT");
{
inChar = Serial.readString();
lcd.setCursor(0, 0);
lcd.print("IN SERIAL EVENT");
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print(inChar);
delay(2000);
if (inChar.equals("A"))
{
for (int i = 0; i < 21; i++)
{
lcd.setCursor(0, 0);
lcd.print("EMEGR LANE A");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
}
}
else if (inChar.equals("B"))
{
for (int i = 0; i < 21; i++)
{
lcd.setCursor(0, 0);
lcd.print("EMEGR LANE B");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
}
}
else if (inChar.equals("C"))
{
for (int i = 0; i < 21; i++)
{
lcd.setCursor(0, 0);
lcd.print("EMEGR LANE C");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
}
}
else if (inChar.equals("D"))
{
for (int i = 0; i < 21; i++)
{
lcd.setCursor(0, 0);
lcd.print("EMEGR LANE D");
lcd.setCursor(0, 1);
lcd.print(i);
delay(300);
lcd.clear();
}
}
else
{
RFIDS = inChar;
lcd.setCursor(0, 0);
lcd.print(RFIDS);
lcd.setCursor(0, 1);
lcd.print("RFID STRING");
delay(2000);
lcd.clear();
}
}
lcd.clear();
