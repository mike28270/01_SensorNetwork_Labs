int piezo= 5;
int pir= 7;
int motion_status= 0;
void setup(){ 
  pinMode(piezo , OUTPUT); 
  pinMode(pir, INPUT);
  Serial.begin(9600);
}
void loop(){
  Serial.print("motion: ");
  Serial.println(motion_status);
  motion_status= digitalRead(pir); 
  if (motion_status == HIGH){
    digitalWrite(piezo, HIGH); 
    delay(500); 
    digitalWrite(piezo, LOW);
  }else{
  digitalWrite(piezo, LOW);
} }
