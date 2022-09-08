//Code for sensor node Arduino uno controller:
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00002";
const byte address1[6] = "00001"; //writing address
int ir1=A0;
int ir2=A1;
int ir3=A2;
void setup()
{
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ir3,INPUT);
Serial.begin(9600);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
radio.openWritingPipe(address1);
}
void loop()
{
char text;
radio.startListening();
if ( radio.available())
{
radio.read(&text, sizeof(text));
Serial.println("text");
Serial.println(text);
}
while (text=='3')
{
radio.stopListening();
char text1;
int a,b,c;
a=digitalRead(ir1);
b=digitalRead(ir2);
c=digitalRead(ir3);
Serial.println(a);
Serial.println(b);
Serial.println(c);
delay(1000);
if(a==0&&b==1&&c==1)
{
Serial.println("LOW TRAFFIC");
text1='1';
}
else if(a==0&&b==0&&c==1)
{
text1='2';
Serial.println("MEDIUM TRAFFIC");
}
else if(a==0&&b==0&&c==0)
{
Serial.println("HIGH TRAFFIC");
text1='3';
}
else
{
text1='0';
}
if(text=='3')
{
radio.write(&text1, sizeof(text1));
Serial.println("SNT TO BASE NODE");
}
text='a';
}
}
