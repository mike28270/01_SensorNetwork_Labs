#include <SoftwareSerial.h>
short button1 = 2;
short xBeeTx = 11; 
short xBeeRx = 12;
char LEDstate1; // state of the button
int LEDstate2; // state of the potentiometer

SoftwareSerial xBeeSerial(xBeeRx, xBeeTx);

void setup(){ 
  Serial.begin(9600);
  xBeeSerial.begin(9600); 
  pinMode(button1 , INPUT); 
  }

void loop(){
  int temp = analogRead(A0); 
  LEDstate2 = map(temp,0,1023,0,255);
  //read in value from the potentiometer
  // map temp from the range (0,1023) to
  if (digitalRead(button1) == HIGH) { 
    LEDstate1 = 'H';
  }
  else {
    LEDstate1 = 'L';
    }
  xBeeSerial.print(LEDstate1); //transmit the state of the button 
  xBeeSerial.print(','); // seperate two data by a comma 
  xBeeSerial.print(LEDstate2); //transmit the state of the potentiometer 
  xBeeSerial.println();
  Serial.println(LEDstate1);
  Serial.println(LEDstate2);
  delay(1000); 
}
