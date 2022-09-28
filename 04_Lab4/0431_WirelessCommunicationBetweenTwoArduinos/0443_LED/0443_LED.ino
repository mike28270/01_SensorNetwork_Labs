#include <SoftwareSerial.h> 
char LEDstate;
short LED = 13; 
short xBeeTx = 11; 
short xBeeRx = 12;
SoftwareSerial xBeeSerial(xBeeRx, xBeeTx);
void setup(){ 
  Serial.begin(9600); 
  xBeeSerial.begin(9600); 
  pinMode(LED, OUTPUT);
}
void loop(){
  Serial.println("Please be working.");
  Serial.println(xBeeSerial.available());
if (xBeeSerial.available() > 0){
  Serial.println("I'm working");
LEDstate = xBeeSerial.read(); 
Serial.println(LEDstate);
if (LEDstate == 'H'){
digitalWrite(LED,HIGH); }
else { digitalWrite(LED,LOW);
} }
}
