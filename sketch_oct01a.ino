String inString ;
int val ;

#include <SPI.h>
#include <LoRa.h>

int mcon1_1=3;
int mcon1_2=4;
int mcon2_1=5;
int mcon2_2=6;
int ledpin1 = 7;
int ledpin = 8;

void setup() {
  Serial.begin(9600);
  
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin1,OUTPUT);
  
  pinMode(mcon1_1,OUTPUT);
  pinMode(mcon1_2,OUTPUT);
  pinMode(mcon2_1,OUTPUT);
  pinMode(mcon2_2,OUTPUT);
   while (!Serial);  
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) { // or 915E6, the MHz speed of yout module
    Serial.println("Starting LoRa failed!");
    while (1);
  }

}
///კონტროლის პროტოკოლი
void win(){
  digitalWrite(mcon1_1,HIGH);
  digitalWrite(mcon1_2,LOW);
  digitalWrite(mcon2_1,HIGH);
  digitalWrite(mcon2_2,LOW);
 }
void ukan(){
  digitalWrite(mcon1_2,HIGH);
  digitalWrite(mcon1_1,LOW);
  digitalWrite(mcon2_2,HIGH);
  digitalWrite(mcon2_1,LOW);
  
 }

void stopp(){
  digitalWrite(mcon1_1,LOW);
  digitalWrite(mcon1_2,LOW);
  digitalWrite(mcon2_1,LOW);
  digitalWrite(mcon2_2,LOW);
 }

void marj(){
  digitalWrite(mcon1_1,HIGH);
  digitalWrite(mcon1_2,LOW);
  digitalWrite(mcon2_1,LOW);
  digitalWrite(mcon2_2,HIGH);
  
 }
void marcx(){
  digitalWrite(mcon1_1,LOW);
  digitalWrite(mcon1_2,HIGH);
  digitalWrite(mcon2_1,HIGH);
  digitalWrite(mcon2_2,LOW);
  
 }



///საბოლოო ციკლი
void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) { 
    // read packet    
    while (LoRa.available())
    {
      int inChar = LoRa.read();
      inString=(char)inChar;
      val = inString.toInt();
      delay(5);
      if(val==1){
        win();
        digitalWrite(ledpin1,HIGH);
        Serial.println(1);

      }else if(val==2){
        ukan();
        digitalWrite(ledpin1,HIGH);
        Serial.println(2);

      }else if(val==3){
        marj();
        digitalWrite(ledpin1,HIGH);
        Serial.println(3);
 
      }else if(val==4){
        marcx();
        digitalWrite(ledpin1,HIGH);
        Serial.println(4);
        
      }else if(val==7){
        digitalWrite(ledpin,HIGH);
        delay(45);
      }else if(val==8){
        digitalWrite(ledpin,LOW);
        delay(45);
      }else{
        stopp();
        digitalWrite(ledpin1,LOW);
        Serial.println(5);

      }



 
}
}else{

}
}





