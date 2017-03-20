const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if (switchState == HIGH){
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }
}
