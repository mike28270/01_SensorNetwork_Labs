int a = 11; 
int b = 12; 
int c = 13;

void setup () { 
    Serial.begin(9600);
}
void loop () { 
    Serial.print(a); 
    Serial.print(','); 
    Serial.print(b); 
    Serial.print(','); 
    Serial.println(c);
}
