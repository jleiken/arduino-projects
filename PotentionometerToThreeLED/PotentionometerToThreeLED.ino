const int greenPin = 9;
const int redPin = 11;
const int bluePin = 10;
const int potPin = A0;
int greenVal = 0;
int blueVal = 0;
int redVal = 0;
int potValue = 0;
int blueOpp = 0;

void setup(){
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  potValue = analogRead(A0);
  greenVal = map(potValue, 250, 750, 0, 255);
  blueVal = map(potValue, 0, 500, 1, 255);
  redVal = map(potValue, 500, 1023, 0, 255);
  if(blueVal > 255){
    while(blueVal > 255){
      blueVal -= potValue;
    }
  }
  else{  
    analogWrite(bluePin, constrain(blueVal, 0, 255));
  }
  if(greenPin > 255){
    analogWrite(greenPin, 25);
  }
  else{  
    analogWrite(greenPin, constrain(greenVal, 0, 255));
  }
  analogWrite(redPin, constrain(redVal, 0, 255));
  Serial.print(greenVal);
  Serial.print("     ");
  Serial.print(blueVal - potValue);
  Serial.print("     ");
  Serial.println(redVal);
}
