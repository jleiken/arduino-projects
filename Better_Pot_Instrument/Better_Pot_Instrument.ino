int pot = A0;
int speaker = 3;
int toggleB = 4;
int rightB = 5;
int leftB = 6;
int on;

void setup() {
  pinMode(toggleB, INPUT);
  pinMode(rightB, INPUT);
  pinMode(leftB, INPUT);
  pinMode(pot, INPUT);
  on = 0;
}

void loop() {
  if (digitalRead(toggleB) == HIGH) {
    on = !on;
  }
  if (on) {
    int potVal = analogRead(pot);
    tone(speaker, map(potVal, 0, 1023, 50, 4000), 20);
  } else {
    noTone;
  }
  delay(10);
}
