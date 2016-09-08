#include <Servo.h>

Servo motor1; //coxa esquerda
Servo motor2; //coxa direita  
Servo motor3; //pe esquerda
Servo motor4; //pe direito

int angleMotor1 = 60;
int angleMotor2 = 170;
int angleMotor3 = 70;
int angleMotor4 = 90;

void setup() {
  Serial.begin(9600); 

  // put your setup code here, to run once

  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
  motor4.attach(8);

  motor1.write(angleMotor1);
  motor2.write(angleMotor2);
  motor3.write(angleMotor3);  // intervalo 70 pe 20  curvado
  motor4.write(angleMotor4);

}

String readString;
int incomingByte = 0;  // for incoming serial data

void loop() {
  
   while (Serial.available()) {
   char inChar = Serial.read();
    //incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    //Serial.println(incomingByte, DEC);
    Serial.println(inChar);
    switch(inChar){
      case 'a':
        Serial.println("diminuindo 10 graus");
        angleMotor2 = angleMotor2 - 10;
        Serial.println(angleMotor2);
        motor2.write(angleMotor2);
        break;
      case 's':
        Serial.println("aumentando 10 graus");
        angleMotor2 = angleMotor2 + 10;
        Serial.println(angleMotor2);
        motor2.write(angleMotor2);
        break;
      case 'd':
        Serial.println("diminuindo 10 graus");
        angleMotor1 = angleMotor1 - 10;
        Serial.println(angleMotor1);
        motor1.write(angleMotor1);
        break;
      case 'f':
        Serial.println("aumentando 10 graus");
        angleMotor1 = angleMotor1 + 10;
        Serial.println(angleMotor1);
        motor1.write(angleMotor1);
        break;
      case 'w': 
        Serial.println("diminuindo 10 graus");
        angleMotor4 = angleMotor4 - 10;
        Serial.println(angleMotor4);
        motor4.write(angleMotor4);
        break;
      case 'q':
        Serial.println("aumentando 10 graus");
        angleMotor4 = angleMotor4 + 10;
        Serial.println(angleMotor4);
        motor4.write(angleMotor4);
        break;
      case 'e':
        Serial.println("aumentando 10 graus");
        angleMotor3 = angleMotor3 + 10;
        Serial.println(angleMotor3);
        motor3.write(angleMotor3);
        break;
      case 'r':
        Serial.println("diminuindo 10 graus");
        angleMotor3 = angleMotor3 - 10;
        Serial.println(angleMotor3);
        motor3.write(angleMotor3);
        break;
      default:
        Serial.println("nao reconhecido");
    }
  }
  
  
   for (int i=1; i<=7;i++){
     angleMotor3 = angleMotor3 - i;
     Serial.println(angleMotor3);
     motor3.write(angleMotor3);
   delay(100);
   }
   
   for (int i=1; i<=7;i++){
     angleMotor1 = angleMotor1 + i;
     Serial.println(angleMotor1);
     motor1.write(angleMotor1);
   delay(100);
   }
   
   for (int i=1; i<=7;i++){
     angleMotor3 = angleMotor3 + i;
     Serial.println(angleMotor3);
     motor3.write(angleMotor3);
   delay(100);
   }
   
    for (int i=1; i<=7;i++){
     angleMotor1 = angleMotor1 - i;
     Serial.println(angleMotor1);
     motor1.write(angleMotor1);
   delay(100);
   }
   
  
   
   
   

  // put your main code here, to run repeatedly
  //motor4.write(100);
  //for(int i = 20; i <=70; i++){

    //motor1.write(i);
   //motor3.write(i);
    //delay(10);

  //}

  //for(int i = 140; i >= 100; i--){

    //motor2.write(i);
    //motor4.write(i);
    //delay(10);

  //}

}
