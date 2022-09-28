const int buttonPin = 11;
const int led1 = 12;
const int led2 = 13;
int button = LOW;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  //millis(1000);                       // wait for a second
  //digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  //millis(1000);                       // wait for a second
  
  button = digitalRead(buttonPin);
  if (button == HIGH and digitalRead(led1) == LOW) {
    digitalWrite(led1, HIGH);
  }
  else if (button == HIGH and digitalRead(led1) == HIGH){
    digitalWrite(led1, LOW);
  }
}
