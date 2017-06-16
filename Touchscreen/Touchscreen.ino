#define XM A3
#define YM A2
#define XP A1
#define YP A0

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int X,Y;
pinMode(XP,INPUT);
pinMode(XM,INPUT);
digitalWrite(XM,LOW);
pinMode(YP,OUTPUT);
digitalWrite(YP,HIGH);
pinMode(YM,OUTPUT);
digitalWrite(YM,LOW);
Y=(analogRead(XP));
Serial.println(Y);

}
