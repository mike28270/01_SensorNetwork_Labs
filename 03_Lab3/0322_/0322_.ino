#include <string.h>
short LED1 = 9; 
short LED2 = 10; 
short LED3 = 11;

void setup () {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT);
}

void loop () {
  char *first ,*second, *third;
  int data1 ,data2 ,data3;
  String serialResponse;
  int len;
  if ( Serial.available()) {
    serialResponse = Serial.readStringUntil('\n'); //read data into a String object serialRespons
    len = serialResponse.length(); // get the length of the String 
    char buf[len+1];
    serialResponse.toCharArray(buf, sizeof(buf)); // convert a String object to char *buf
    
    // split buf by comma
    first = strtok(buf,","); //get the first CharArray splitted by comma 
    data1 = atoi(first); // convert CharArray to integer
    if (data1 == 11)
      digitalWrite(LED1, HIGH); 
    // Second strtok iteration 
    second = strtok(NULL,","); 
    data2 = atoi(second);
    if (data2 == 12)
      digitalWrite(LED2, HIGH);
    third = strtok(NULL,","); 
    data3 = atoi(third);
    if (data3 == 13)
      digitalWrite(LED3, HIGH); }
}
