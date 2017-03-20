void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.write(analogRead(A0)/4);
  Serial.println(analogRead(A0));
  delay(1);
}
