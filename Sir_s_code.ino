#include<Servo.h>
#include<TouchScreen.h>
#include<PID_v1.h>

double inputX, inputY, outputX, outputY, setPointX = 518, setPointY = 560;
Servo ServoX, ServoY;
int ServoYpin = 2, ServoXpin = 3, mn = 60, mx = 120; 
int YP = A0, XP = A1, YM = A2, XM = A3;
double Kp=0.08;
double Ki=0.008 ;
double Kd=0.003; 
//double Kp=0.05; 
//double Ki=0.0;
//double Kd=0.09;

PID pidX(&inputX, &outputX, &setPointX, Kp, Ki, Kd, REVERSE);
PID pidY(&inputY, &outputY, &setPointY, Kp, Ki, Kd, DIRECT);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 711);

void setup() {
  Serial.begin(9600);
  int sampleTime = 40;
  ServoX.attach(ServoXpin);
  ServoY.attach(ServoYpin);
  ServoX.write(90);
  ServoY.write(90);
  pidX.SetMode(AUTOMATIC);
  pidY.SetMode(AUTOMATIC);
  pidX.SetOutputLimits(mn, mx);
  pidY.SetOutputLimits(mn, mx);
  pidX.SetSampleTime(sampleTime);
   pidY.SetSampleTime(sampleTime);
  

   
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  TSPoint p = ts.getPoint();
  inputX = p.x;
  inputY = p.y;
  Serial.print("X= ");
  Serial.print(p.x);
  Serial.print("Y= ");
  Serial.println(p.y);
 
  if(p.z > ts.pressureThreshhold) {
    pidX.Compute();
    pidY.Compute();
    ServoX.write(outputX);
    ServoY.write(outputY);
    
//    Serial.print("Servo angles: ");
//    Serial.print(outputX);
//    Serial.print(" ");
//    Serial.println(outputY);
//    delay(1000);
  }
    
    
  
}
