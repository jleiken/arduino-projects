#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorPin = A0;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop(){
  lcd.clear();
  lcd.setCursor(0, 0);
  int ar = analogRead(sensorPin);
  Serial.println(ar);
  lcd.print(ar);
  delay(200);
}
  
