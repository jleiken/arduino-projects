#include <IRremote.h>
#include <LiquidCrystal.h>

IRsend irsend;
LiquidCrystal lcd(12, 11, 5, 4, 10, 2);
int blueVals[] = {0xF7609F, 0xF750AF, 0xF7708F, 0xF748B7, 0xF76897};
int greenVals[] ={0xF7A05F, 0xF7906F, 0xF7B04F, 0xF78877, 0xF7A857};
int redVals[] =  {0xF720DF, 0xF710EF, 0xF730CF, 0xF708F7, 0xF728D7};
int specVals[] = {0xF7E01F, 0xF7D02F, 0xF7F00F, 0xF7C837, 0xF7E817};
String specNames[] = {"white", "flash", "strobe", "fade", "smooth"};
//buttons
int up = 7;
int down = 6;
int left =9;
int right = 8;
bool isOn = false;
int location = 1;
int colLoc = 1;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  //Make the button pins input
  for(int i=6;i<10;i++)
    pinMode(i, INPUT); 
}

void loop() {
  if(!isOn)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Up to turn on");
    delay(200);
    if(digitalRead(up) == HIGH)
    {
      for(int i =1;i<4;i++)
      {
          irsend.sendNEC(0xF7C03F,32);
          delay(100); 
      }
     isOn = true;
    }
  }
  else
  {
    switch(location){
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Up for on");
      lcd.setCursor(0,1);
      lcd.print("Down for off");
      delay(200);
      if(digitalRead(up))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(0xF7C03F,32);
          delay(100); 
        }
      }
      if(digitalRead(down))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(0xF740BF,32);
          delay(100); 
        }
      }
      if(digitalRead(left))
      {
        location=5;
        colLoc=1;
      }
      if(digitalRead(right))
      {
        location=1;
        colLoc=1;
      }
    break;    
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Up for brighter");
      lcd.setCursor(0,1);
      lcd.print("Down for darker");
      delay(200);
      if(digitalRead(up))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(0xF700FF,32);
          delay(100); 
        }
      }
      if(digitalRead(down))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(0xF7807F,32);
          delay(100); 
        }
      }
      if(digitalRead(left))
      {
        location=0;
        colLoc=1;
      }
      if(digitalRead(right))
      {
        location=2;
        colLoc=1;
      }
    break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Up for red " + String(colLoc));
      lcd.setCursor(0,1);
      lcd.print("Down for red " + String(colLoc+1));
      delay(200);
      if(digitalRead(up))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(redVals[colLoc-1],32);
          delay(100); 
        }
        if(colLoc != 1)
          colLoc-=1;
      }
      if(digitalRead(down))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(redVals[colLoc],32);
          delay(100); 
        }
        if(colLoc != 4)
          colLoc+=1;
      }
      if(digitalRead(left))
      {
        location=1;
        colLoc=1;
      }
      if(digitalRead(right))
      {
        location=3;
        colLoc=1;
      }
    break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Up for green " + String(colLoc));
      lcd.setCursor(0,1);
      lcd.print("Down for green " + String(colLoc+1));
      delay(200);
      if(digitalRead(up))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(greenVals[colLoc-1],32);
          delay(100); 
        }
        if(colLoc != 1)
          colLoc-=1;
      }
      if(digitalRead(down))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(greenVals[colLoc],32);
          delay(100); 
        }
        if(colLoc != 4)
          colLoc+=1;
      }
      if(digitalRead(left))
      {
        location=2;
        colLoc=1;
      }
      if(digitalRead(right))
      {
        location=4;
        colLoc=1;
      }
    break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Up for blue " + String(colLoc));
      lcd.setCursor(0,1);
      lcd.print("Down for blue " + String(colLoc+1));
      delay(200);
      if(digitalRead(up))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(blueVals[colLoc-1],32);
          delay(100); 
        }
        if(colLoc != 1)
          colLoc-=1;
      }
      if(digitalRead(down))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(blueVals[colLoc],32);
          delay(100); 
        }
        if(colLoc != 4)
          colLoc+=1;
      }
      if(digitalRead(left))
      {
        location=3;
        colLoc=1;
      }
      if(digitalRead(right))
      {
        location=5;
        colLoc=1;
      }
    break;
    case 5:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Up for " + specNames[colLoc-1]);
      lcd.setCursor(0,1);
      lcd.print("Down for " + specNames[colLoc]);
      delay(200);
      if(digitalRead(up))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(specVals[colLoc-1],32);
          delay(100); 
        }
        if(colLoc != 1)
          colLoc-=1;
      }
      if(digitalRead(down))
      {
        for(int i =1;i<4;i++)
        {
          irsend.sendNEC(specVals[colLoc],32);
          delay(100); 
        }
        if(colLoc != 4)
          colLoc+=1;
      }
      if(digitalRead(left))
      {
        location=4;
        colLoc=1;
      }
      if(digitalRead(right))
      {
        location=0;
        colLoc=1;
      }
    break;
    default:
      location = 0;
      colLoc=1;
    break;  
    }
  }
}
