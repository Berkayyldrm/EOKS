#include "DHT.h"


 
#define DHTPIN 2  
#define DHTTYPE DHT11
#define MotorPin 5 
int MotorDurum = LOW;
const int RELAY=3;

DHT dht(DHTPIN, DHTTYPE);

int SetPoint=25;

void setup()
{
  Serial.begin(9600); // Seri iletişimi başlatıyoruz.
  Serial.println(F("DHTxx test!"));
  pinMode(RELAY,OUTPUT);
  pinMode(MotorPin,OUTPUT);

  digitalWrite(RELAY,LOW);

  dht.begin();
}
 
void loop()
{
  float t = dht.readTemperature();


  Serial.println(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println();
  
  if(t > SetPoint){
   digitalWrite(RELAY,LOW);    //Turn off heater
   Serial.println(F("Relay OFF"));
   if (MotorDurum==LOW){
    MotorDurum = HIGH;
   }
   

   }
  else{
    digitalWrite(RELAY,HIGH);
    Serial.println(F("Relay ON"));
    MotorDurum = LOW;
  }
  
  digitalWrite(MotorPin,MotorDurum);
  delay(1000);
 
}
