/*
Reading a serial ASCII-encoded string.
This sketch demonstrates the Serial parseInt() function.
It looks for an ASCII string of comma-separated values.
It parses them into ints, and uses those to fade an RGB LED.
Circuit: Common-anode RGB LED wired like so: * Blue cathode: digital pin 9
* Red cathode: digital pin 11
* Green cathode: digital pin 10
* anode: +5V
This example code is in the public domain. */
// pins for the LEDs:
const int redPin = 11; 
const int greenPin = 10; 
const int bluePin = 9;

void setup () {
  // initialize serial: 
  Serial.begin(9600);
  // make the pins outputs: 
  pinMode(redPin , OUTPUT); 
  pinMode(greenPin , OUTPUT); 
  pinMode(bluePin , OUTPUT);
}

void loop () {
// if there’s any serial available, read it: 
  while (Serial.available()) {
    Serial.println("Serial is ready!"); 
    // look for the next valid integer in the incoming serial stream:
    Serial.print("Input is ");
    int red = Serial.parseInt(); // do it again:
    int green = Serial.parseInt(); // do it again:
    int blue = Serial.parseInt();
    Serial.print("red: "); 
    Serial.print(red);
    Serial.print(" "); 
    Serial.print("green: "); 
    Serial.print(green);
    Serial.print(" "); 
    Serial.print("blue: "); 
    Serial.println(blue);
    
    // look for the newline. That’s the end of your sentence:
    //if (Serial.read() == "\n" or Serial.read() == "\r") {
    if (blue == 70) {
      Serial.println("Change color"); 
      // constrain the values to 0 - 255 and invert
      // if you’re using a common-cathode LED, just use "constrain(color, 0, 255) ;"
      //red = 255 - constrain(red, 0, 255); 
      //green = 255 - constrain(green, 0, 255); 
      //blue = 255 - constrain(blue, 0, 255);
      red = 255 - constrain(red, 0, 255); 
      green = 255 - constrain(green, 0, 255); 
      blue = 255 - constrain(blue, 0, 255);

       // print the three numbers in one string as hexadecimal:
      Serial.print(red, HEX); 
      Serial.print(green , HEX); 
      Serial.println(blue, HEX);
      
      // fade the red, green, and blue legs of the LED:
      analogWrite(redPin , red); 
      analogWrite(greenPin , green); 
      analogWrite(bluePin , blue);
    } 
  }
}
