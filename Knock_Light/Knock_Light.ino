const int piezo = A0;
const int ledPin = 2;
int on = 0;
void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (analogRead(piezo) > 10 && on == 0){
    on = 1;
  } else if (analogRead(piezo) > 10 && on == 1){
    on = 0;
  }
  if (on == 1){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  Serial.print(on);
  Serial.print("  ");
  Serial.println(analogRead(piezo));
  delay(100);
}

