int V=10;
int setpoint=1000;
int actual_position=0;
float constant=5.0;
float previous_error;
float integral;
float error;
int dt=500;
float derivative;
float Kp,Ki=0,Kd=0;
float output;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
previous_error=0;
integral=0;

error=setpoint-actual_position;
integral=integral+error*dt;
derivative=(error-previous_error)/dt;
output=Kp*error+Ki*integral+Kd*derivative;
previous_error=error;
delay(dt);

actual_position+=V;
V=output*constant;
Serial.println(actual_position);
}
