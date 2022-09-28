const int trig = 7; 
const int echo = 6;
void setup () {
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW); 
  Serial.begin(9600);
}
void loop () {
//send an impulse to trigger the sensor start the measurement
digitalWrite(trig, HIGH);
delayMicroseconds(15); //minimum impulse width required by HC-SR4 sensor 
digitalWrite(trig, LOW);
long duration = pulseIn(echo, HIGH);
// this function waits for the pin to go HIGH ,
//starts timing, then waits for the pin to go LOW and stops timing.
//Returns the length of the pulse in microseconds
//’duration’ is the time it takes sound from the transmitter back //to the receiver after it bounces off an obstacle
const long vsound = 340; // [m/s]
long dist = (duration / 2) * vsound / 10000; // 10000 is just the scalingfactor to get the result in [cm]
if (dist > 500 || dist < 2) {
  Serial.print("duration:");
  Serial.print(duration); 
  Serial.print("            ");
  Serial.println("Invalid range!"); 
}
else
{
  Serial.print("duration:");
  Serial.print(duration); 
  Serial.print("            ");
  Serial.print("Distance: ");
  Serial.print(dist); 
  Serial.println(" cm");
}
delay(1000); } 
