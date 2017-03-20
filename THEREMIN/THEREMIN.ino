int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int onOffSwitch = 2;
boolean onOff = true;
const int ledPin = 13;
void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(onOffSwitch, INPUT);
  digitalWrite(ledPin, HIGH);
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorHigh < sensorValue){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}
void loop(){
  sensorValue = analogRead(A0);
  if (digitalRead(onOffSwitch) == LOW){
    onOff = false;
  } else {
    onOff = true;
  }
  if (onOff == false){  
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    tone(8, pitch, 20);
    delay(10);
  }
  else{
    noTone;
  }
}
