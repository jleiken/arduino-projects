#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);
const int threshold = 400;
int onOff = 0;
const int ledPin = 12;
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop(){
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.print(sensorValue);
  if(sensorValue > threshold){
  //keeps the light on or off like a real lamp  
    if(onOff == 0){
      onOff = 1;
      //delay makes it function better (you don't have to touch and remove the material as fast as possible)
      delay(300);
    }else if(onOff == 1){
      onOff = 0;
      delay(300);
    }
  }
  if(onOff == 0){
    digitalWrite(ledPin, LOW);
  }else{
    digitalWrite(ledPin, HIGH);
  }
  Serial.print("  ");
  Serial.println(onOff);
  delay(10);
}
