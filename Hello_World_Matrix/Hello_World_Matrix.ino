  //We always have to include the library
#include "LedControl.h"

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single matrix
 */
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=500;

void setup() {
  lc.shutdown(0,false);
  /* Set the brightness */
  lc.setIntensity(0,1);
  /* clear the display */
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void loop() { 
  /* here is the data for the characters */
  // It's left to right and then bottom up
  byte h[8]={B00000000,B00000000,B01111110,B00001000,B00001000,B01111110,B00000000,B00000000};
  byte e[8]={B00000000,B00000000,B00111100,B01010010,B01010010,B01001100,B00000000,B00000000};
  byte l[8]={B00000000,B00000000,B00000000,B01111110,B01000000,B00000000,B00000000,B00000000};
  byte o[8]={B00000000,B00000000,B00110000,B01001000,B01001000,B00110000,B00000000,B00000000};
  byte space[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte w[8]={B00000000,B00000000,B00111000,B01000000,B00110000,B01000000,B00111000,B00000000};
  byte r[8]={B00000000,B00000000,B01111110,B00000100,B00000100,B00001000,B00000000,B00000000};
  byte d[8]={B00000000,B00000000,B00110000,B01001000,B01001000,B01111110,B00000000,B00000000};

  /* now display them one by one with a small delay */
  //hello
  for (int i = 0; i < sizeof(h); i++) {
    lc.setRow(0,i,h[i]);
  }
  Serial.println("h");
  delay(delaytime);
  for (int i = 0; i < sizeof(e); i++) {
    lc.setRow(0,i,e[i]);
  }
  delay(delaytime);
  Serial.println("e");
  for (int i = 0; i < sizeof(l); i++) {
    lc.setRow(0,i,l[i]);
  }
  delay(delaytime);
  Serial.println("l");
  for (int i = 0; i < sizeof(l); i++) {
    lc.setRow(0,i,l[i]);
  }
  delay(delaytime);
  Serial.println("l");
  for (int i = 0; i < sizeof(o); i++) {
    lc.setRow(0,i,o[i]);
  }
  delay(delaytime);
  Serial.println("o");

  
  for (int i = 0; i < sizeof(space); i++) {
    lc.setRow(0,i,space[i]);
  }
  delay(delaytime);
  Serial.println("space");


  //world
  for (int i = 0; i < sizeof(w); i++) {
    lc.setRow(0,i,w[i]);
  }
  delay(delaytime);
  Serial.println("w");
  for (int i = 0; i < sizeof(o); i++) {
    lc.setRow(0,i,o[i]);
  }
  delay(delaytime);
  Serial.println("o");
  for (int i = 0; i < sizeof(r); i++) {
    lc.setRow(0,i,r[i]);
  }
  delay(delaytime);
  Serial.println("r");
  for (int i = 0; i < sizeof(l); i++) {
    lc.setRow(0,i,l[i]);
  }
  delay(delaytime);
  Serial.println("l");
  for (int i = 0; i < sizeof(d); i++) {
    lc.setRow(0,i,d[i]);
  }
  delay(delaytime);
  Serial.println("d");

  
  for (int i = 0; i < sizeof(space); i++) {
    lc.setRow(0,i,space[i]);
  }
  delay(delaytime);
  Serial.println("space");
}
