const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int drawerOutPin = 7;
const int drawerInPin = 4;
int motorEnable = 0;
int motorSpeed = 400;
int motorDirection = 1;

void setup(){
  pinMode(drawerOutPin, INPUT);
  pinMode(drawerInPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);  
  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(drawerOutPin) == HIGH){
    analogWrite(enablePin, motorSpeed);
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    delay(3000);
    analogWrite(enablePin, 0);
  } else if(digitalRead(drawerInPin) == HIGH){
    analogWrite(enablePin, motorSpeed + 100);
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    delay(3000);
    analogWrite(enablePin, 0);
  }
  delay(5);
}
