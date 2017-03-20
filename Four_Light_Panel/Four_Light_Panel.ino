int switchState = 0;
int switchState2 = 0;
int switchState3 = 0;
int switchState4 = 0;

void setup(){
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  switchState = digitalRead(2);
  switchState2 = digitalRead(3);
  switchState3 = digitalRead(4);
  switchState4 = digitalRead(5);
  if (switchState == LOW) {
    digitalWrite(6, LOW);
  } else {
    digitalWrite(6, HIGH);
  }
  if (switchState2 == LOW) {
    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);
  }
  if (switchState3 == LOW) {
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
  }
  if (switchState4 == LOW) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, HIGH);
  }
}

