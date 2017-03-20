const int sensorPin = A0;
const int gpin = 9;
const int bpin = 10;
const int rpin = 11;

void setup(){
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(rpin, OUTPUT);
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  temperature = temperature*9/5+32;
  if(temperature <= 65){
    analogWrite(bpin, 255);
  } else if (temperature > 65 && temperature <= 75){
    analogWrite(bpin, 255/3);
  } else {
    analogWrite(bpin, 0);
  }
  if(temperature <= 65){
    analogWrite(rpin, 0);
  } else if (temperature > 65 && temperature <= 75){
    analogWrite(rpin, 255/3);
  } else {
    analogWrite(rpin, 255);
  }
  if(temperature <= 65){
    analogWrite(gpin, 255/2);
  } else if (temperature > 65 && temperature <= 75){
    analogWrite(gpin, 255);
  } else if (temperature > 75 && temperature <= 90){
    analogWrite(gpin, 255/3);
  } else {
    analogWrite(gpin, 0);
  }
  Serial.println(temperature);
  delay(100);
}
