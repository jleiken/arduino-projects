const int ledPin = 13;
const int onBut = 4;
boolean on = false;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(onBut, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  if(digitalRead(onBut) == HIGH)
  {
    if(on == true)
      digitalWrite(ledPin, LOW);
    else
      digitalWrite(ledPin, HIGH);
    on = !on;  
  }
}
