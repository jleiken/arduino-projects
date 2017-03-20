int notes[] = {262, 294, 330, 349, 96, 415};
int compVals[30];
int index = 0;
const int greenBut = 8;
const int yellowBut = 6;
const int blueBut = 4;
const int redBut = 2;
const int greenLed = 12;
const int yellowLed = 7;
const int blueLed = 5;
const int redLed = 3;
const int multiRed = 9;
const int multiBlue = 10;
const int multiGreen = 11;
const int piezo = 13;



void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A5));
  pinMode(greenBut, INPUT);
  pinMode(yellowBut, INPUT);
  pinMode(blueBut, INPUT);
  pinMode(redBut, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(multiRed, OUTPUT);
  pinMode(multiBlue, OUTPUT);
  pinMode(multiGreen, OUTPUT);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(multiGreen, HIGH);
  while (digitalRead(greenBut) != HIGH)
  {
    delay(10);
  }
  digitalWrite(greenLed, LOW);
  digitalWrite(multiGreen, LOW);
}



void loop()
{
  //add step from computer, play the computer sequence
  compVals[index] = random(4);
  for (int i = 0; i <= index; i++) {
    delay(10);
    if (compVals[i] == 0) {
      digitalWrite(redLed, HIGH);
      tone(piezo, notes[compVals[i]]);
    }
    else if (compVals[i] == 1) {
      digitalWrite(blueLed, HIGH);
      tone(piezo, notes[compVals[i]]);
    }
    else if (compVals[i] == 2) {
      digitalWrite(yellowLed, HIGH);
      tone(piezo, notes[compVals[i]]);
    }
    else if (compVals[i] == 3) {
      digitalWrite(greenLed, HIGH);
      tone(piezo, notes[compVals[i]]);
    }
    delay(1000);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    noTone(piezo);
  }
  //ask for the human input
  input();
  delay(1000);
  //if the person made it to 29, they're past the (programmer imposed
  //for practicality) computer memory length- play the win process
  if (index == 29) {
    winProcess();
  }
  index++;
}



void winProcess()
{
  tone(piezo, notes[5]);
  digitalWrite(greenLed, HIGH);
  delay(100);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(100);
  digitalWrite(yellowLed, LOW);
  digitalWrite(blueLed, HIGH);
  delay(100);
  digitalWrite(blueLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(300);
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, HIGH);
  delay(100);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(100);
  digitalWrite(yellowLed, LOW);
  noTone(piezo);
  digitalWrite(multiRed, HIGH);
  digitalWrite(multiBlue, HIGH);
  digitalWrite(multiGreen, HIGH);
  shutdown();
}



void input()
{
  for (int i = 0; i <= index; i++) {
    int input = -1;
    while (input == -1)
    {
      if (digitalRead(redBut) == HIGH) {
        input = 0;
        Serial.println("HIGH0");
        delay(10);
      }
      else if (digitalRead(blueBut) == HIGH) {
        input = 1;
        Serial.println("HIGH1");
        delay(10);
      }
      else if (digitalRead(yellowBut) == HIGH) {
        input = 2;
        Serial.println("HIGH2");
        delay(10);
      }
      else if (digitalRead(greenBut) == HIGH) {
        input = 3;
        Serial.println("HIGH3");
        delay(10);
      }
    }

    delay(10);

    //play the tone and flash the lights for the button they pressed
    if (input == 0) {
      delay(100);
      digitalWrite(redLed, HIGH);
      tone(piezo, notes[0]);
    }
    else if (input == 1) {
      digitalWrite(blueLed, HIGH);
      tone(piezo, notes[1]);
    }
    else if (input == 2) {
      digitalWrite(yellowLed, HIGH);
      tone(piezo, notes[2]);
    }
    else if (input == 3) {
      digitalWrite(greenLed, HIGH);
      tone(piezo, notes[3]);
    }

    delay(500);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    noTone(piezo);
    
    //if the person is wrong, shutdown
    if (input != compVals[i])
      shutdown();
  }
}



//makes the program quit (return; doesn't cut it for some reason)
void shutdown()
{
  digitalWrite(yellowLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  for (int i = 9; i < 12; i++)
    digitalWrite(i, HIGH);
  tone(piezo, notes[4]);
  delay(2000);
  noTone(piezo);
  Serial.println("stopped");
  while (1);
}
