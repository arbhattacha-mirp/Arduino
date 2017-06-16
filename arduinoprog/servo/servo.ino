#include<Servo.h>
int yServopin=2;
int xServopin=3;
Servo ServoX,ServoY;
int mn=60,mx=120;
void setup() {
  // put your setup code here, to run once:
  ServoX.attach(xServopin);
  ServoY.attach(yServopin);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=mn;i<mx;++i)
{
  ServoX.write(i);
  ServoY.write(i);
  delay(10);
}
for(int i=mx;i>mn;--i)
{
  ServoX.write(i);
  ServoY.write(i);
  delay(10);
}
}
