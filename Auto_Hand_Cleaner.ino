#include  <Servo.h>

Servo myservo;

int angle = 130;
int echoPin = 2;
int trigPin = 3;
float duration;
float distance;

void setup() {
  myservo.attach(5);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  delay(100);

  if (distance < 10){
    angle = 30;
    myservo.write(angle);
    delay(1000);
  }
  else{
    angle = 130;
    myservo.write(angle);
  }
}
