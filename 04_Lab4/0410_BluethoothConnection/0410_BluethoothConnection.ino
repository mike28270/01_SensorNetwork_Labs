char value ; // Value sent over serrial port
char lastValue = 'f'; // Stores last state of LED 
int ledPin = 13 ; // Output LED pin

void setup ( ) {
  Serial.begin (9600) ; // Baud rate set to 9600
  pinMode ( ledPin ,OUTPUT) ; // Set l edPin to output 
}

void loop ( ) {
  if ( Serial.available( ) ) // if there is data
  {
    value = Serial.read ( ) ; // Store read value
    //Serial.write ( value ) ; 
  }
  
  if ( value == 'n' && lastValue != 'n' ) // if value from serialis’n ’ and current state is not ’n ’
  {
    digitalWrite (13 , HIGH) ; // switch on LED
    Serial.println ( "LED is on" ) ; // print LED is on for debugging 
    lastValue=value ; // save current state of LED
  }
  else if (value=='f' && lastValue != 'f') 
  {
    digitalWrite(13, LOW); 
    Serial.println("LED is off"); 
    lastValue = value;
  }
  else if (value =='b') 
  {
    if (lastValue !='b') {
      Serial.println("Blinking LED");
      lastValue = value; 
      }
    digitalWrite(13, HIGH); 
    delay(1000); 
    digitalWrite(13, LOW); 
    delay(500);
  }
  delay(500); 
}
