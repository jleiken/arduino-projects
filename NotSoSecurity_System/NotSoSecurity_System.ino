#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int piezo = A0;
const int ledPin = 8;
boolean alarmState = false;

void setup(){
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  lcd.clear();
  lcd.setCursor(0, 0);
  if(analogRead(piezo) >= 1 || alarmState == true){
    digitalWrite(ledPin, HIGH);
    lcd.print("Alarm activated");
    alarmState = true;
  } else {
   digitalWrite(ledPin, LOW);
   lcd.print("Security sytem");
   lcd.setCursor(0, 1);
   lcd.print("armed");
  }
  Serial.println(analogRead(piezo));
  delay(500);
}  
