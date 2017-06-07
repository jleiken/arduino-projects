//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void loop() { 
  /* here is the data for the characters */
  byte h[8]={B00000000,B00000000,B01111110,B00001000,B00001000,B01111110,B00000000,B00000000};
  byte e[8]={B00000000,B00000000,B00011000,B00100100,B00100100,B00011000,B00000000,B00000000};

  /* now display them one by one with a small delay */
  for (int i = 0; sizeof(h); i++) {
    lc.setRow(0,i,h[i]);
  }
  Serial.println("h");
  delay(delaytime);
  for (int i = 0; sizeof(e); i++) {
    lc.setRow(0,i,e[i]);
  }
  delay(delaytime);
  Serial.println("done");
}
