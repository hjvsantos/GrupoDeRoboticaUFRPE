#include<Servo.h>


Servo motor;
void setup() {
  // put your setup code here, to run once:
  motor.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.write(160);
  delay(1000);
  motor.write(16);
  delay(1000);
}
