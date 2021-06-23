#include <SPI.h>
#include <LoRa.h>

int t=0;

int x;
int y;
int z;
#define joyX A0
#define joyY A1

int xValue;
int yValue;

int counter = 0;

void setup() {
  Serial.begin(9600);
 while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setPins(10, 9, 2);
}
void win(){
  LoRa.beginPacket();
  LoRa.print(1);
  LoRa.endPacket();
}

void ukan(){
  LoRa.beginPacket();
  LoRa.print(2);
  LoRa.endPacket();
}

void marj(){
  LoRa.beginPacket();
  LoRa.print(3);
  LoRa.endPacket();
}

void marc(){
  LoRa.beginPacket();
  LoRa.print(4);
  LoRa.endPacket();
}

void stp(){
  LoRa.beginPacket();
  LoRa.print(0);
  LoRa.endPacket();

}
void On(){
  LoRa.beginPacket();
  LoRa.print(7);
  LoRa.endPacket();
}
void Off(){
  LoRa.beginPacket();
  LoRa.print(8);
  LoRa.endPacket();
}

void loop() {
  if (Serial.available() > 0) {
    z =Serial.read()- '0';
    t=1;
  }else{
    z=5;
    t=0;
  }
 
 
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
 



  if(xValue>600 && yValue<600){
    win();
    Serial.println("win");
  }else if(z==1){
    win();
  }else if(xValue<200 & yValue<600 & yValue>400){
    ukan();
    Serial.println("ukan");
  }else if(z==2){
    ukan();
  }else if(xValue<600 & yValue>600){
    marj();
    Serial.println("marjvniv");
  }else if(z==3){
    marj();
  }else if(xValue<600 & xValue>400 & yValue<100){
    marc();
    Serial.println("marcxniv");
  }else if(z==4){
    marc();
  }else if(z==7){
    On();
    delay(50);
  }else if(z==8){
    Off();
    delay(50);   
  }else{
    stp();
  }

delay(5);















  
}
