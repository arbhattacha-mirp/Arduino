void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // X coordinate

  //setting Y1 as input
  pinMode(A0,INPUT);
  //setting Y2 as low input
  pinMode(A2,INPUT);
  digitalWrite(A2,LOW);
  //setting X1 as high output
  pinMode(A1,OUTPUT);
  digitalWrite(A1,HIGH);
  //setting X2 as low output
  pinMode(A3,OUTPUT);
  digitalWrite(A3,LOW);
  int Y1=analogRead(A0);
  Serial.println(Y1);
  delay(1000);
  

}
