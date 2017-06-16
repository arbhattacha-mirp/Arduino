#include<Servo.h>
#include<TouchScreen.h>
#include<PID_v1.h>
float Kp=0.02,Ki=0,Kd=0.04;
#define XM A3
#define YM A2
#define XP A1
#define YP A0
//defining variables for use in PID()
double InputX,OutputX,SetpointX=550;
double InputY,OutputY,SetpointY=520;
//locating point xcoordinate =p.x,ycoordinate =p.y
TouchScreen ts=TouchScreen(XP,YP,XM,YM,711);
//attaching servo
int yServopin=2;
int xServopin=3;
Servo ServoX,ServoY;
//initialisng PID object
PID pidX(&InputX,&OutputX,&SetpointX,Kp,Ki,Kd,REVERSE);
PID pidY(&InputY,&OutputY,&SetpointY,Kp,Ki,Kd,DIRECT);
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
ServoX.attach(xServopin);
ServoY.attach(yServopin);
OutputX=90;
OutputY=90;
ServoX.write(OutputX);
ServoY.write(OutputY);
//PID
int st=40;
pidX.SetMode(AUTOMATIC);
pidX.SetOutputLimits(70,110);
pidX.SetSampleTime(st);
pidY.SetMode(AUTOMATIC);
pidY.SetOutputLimits(70,110);
pidY.SetSampleTime(st);
}
void loop() {
// put your main code here, to run repeatedly:
TSPoint p=ts.getPoint();
InputX=p.x;
InputY=p.y;
if(p.z>ts.pressureThreshhold){
pidX.Compute();
pidY.Compute();
Serial.println(OutputX);
ServoX.write(OutputX);
ServoY.write(OutputY);
}
//delay(200);
}
