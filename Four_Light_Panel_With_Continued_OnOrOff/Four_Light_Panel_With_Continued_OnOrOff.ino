int switchState = 0;
boolean onOff = false;
int switchState2 = 0;
boolean onOff2 = false;
int switchState3 = 0;
boolean onOff3 = false;
int switchState4 = 0;
boolean onOff4 = false;

void setup(){
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  switchState = digitalRead(2);
  switchState2 = digitalRead(3);
  switchState3 = digitalRead(4);
  switchState4 = digitalRead(5);
  if (onOff == false) {
    digitalWrite(6, LOW);
  } else {
    digitalWrite(6, HIGH);
  }
  if (switchState == 1 && onOff == false) {
    onOff = true;
  } else if (switchState == 1 && onOff == true) {
    onOff = false;
  }
  if (onOff2 == false) {
    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);
  }
  if (switchState2 == 1 && onOff2 == false) {
    onOff2 = true;
  } else if (switchState2 == 1 && onOff2 == true) {
    onOff2 = false;
  }
  if (onOff3 == false) {
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
  }
  if (switchState3 == 1 && onOff3 == false) {
    onOff3 = true;
  } else if (switchState3 == 1 && onOff3 == true) {
    onOff3 = false;
  }
  if (onOff4 == false) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, HIGH);
  }
  if (switchState4 == 1 && onOff4 == false) {
    onOff4 = true;
  } else if (switchState4 == 1 && onOff4 == true) {
    onOff4 = false;
  }
  delay(300);
  Serial.print(switchState);
  Serial.print(switchState2);
  Serial.print(switchState3);
  Serial.println(switchState4);
}
