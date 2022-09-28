#include <SoftwareSerial.h> #include <string.h>
short LED1 = 13; // LED1 is controlled by a remote button
short LED2 = 4; // LED2 is controlled by a remote potentialmeter
char LEDstate1; //store the LED1 state (’H’ or ’L’) 
int LEDstate2; // store the LED2 brightness (0 ~ 255)
short xBeeTx = 11;
short xBeeRx = 12;
SoftwareSerial xBeeSerial(xBeeRx, xBeeTx); 

void setup () {
Serial.begin(9600); 
xBeeSerial.begin(9600); 
Serial.println("Starting.."); 
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT); }

void loop () {
  char *first ,*second , *third; 
  String serialResponse;
  int len;
  if ( xBeeSerial.available()>0) {
    serialResponse = xBeeSerial.readStringUntil('\n'); //read data into a String object serialRespons
    Serial.println(serialResponse);
    len = serialResponse.length(); // get the length of the String 
    char buf[len+1];
    serialResponse.toCharArray(buf, sizeof(buf)); // convert a String object to char *buf;
    // split buf by comma 
    first = strtok(buf,","); 
    LEDstate1 = first[0]; 
    Serial.println(LEDstate1); 
    if (LEDstate1 == 'H') {
    //get the first CharArray splitted by comma //get the LED1 state
    // if the LED1 state is ’H’, turn on LED1
    digitalWrite(LED1,HIGH); 
  }
  else { 
    digitalWrite(LED1,LOW);
    }
  second = strtok(NULL,","); //get the second CharArray splitted by comma, NULL means continue processing the previous buffer
  LEDstate2 = atoi(second); // convert a CharArray to an integer Serial.println(LEDstate2);
  analogWrite(LED2,LEDstate2); //
  // third = strtok(NULL,","); //get the third CharArray splitted by comma
  } 
}
