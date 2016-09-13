

 int s4 = 2;
 int s2 = 4;

 int oila;
 int ola;
 
void setup() {
  
  pinMode(s4,OUTPUT);
  digitalWrite(s4, HIGH);
  pinMode(s2,INPUT);
  Serial.begin(9600);
}

void loop() {


  oila = digitalRead(s4);
   //ola =  digitalRead(s2);
 Serial.println(oila);
 //Serial.println(ola);
 delay(1000);
 

}
