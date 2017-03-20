int sensorValue;
const int onOffSwitch = 2;

void setup(){
  pinMode(onOffSwitch, INPUT);
}

void loop(){
  sensorValue = analogRead(A0);
  if(digitalRead(onOffSwitch) == LOW){
    int pitch = map(sensorValue, 0, 1023, 50, 4000);
    tone(8, pitch, 20);
    delay(10);
  }
  else{
    noTone;
  }
}
