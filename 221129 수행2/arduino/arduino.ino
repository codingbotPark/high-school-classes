#include <Servo.h>
int servoPin = 3;
Servo servo;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.setTimeout(100);
  Serial.begin(9600);
  pinMode(5,OUTPUT); // led1
  pinMode(6,OUTPUT); // led2

  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
    servo.write(10); 
   


  if (Serial.available()){
    String getData = Serial.readString();
    
    if (getData == "1on") { // led1 on
      digitalWrite(5,HIGH);
    } else if (getData == "2on"){
      digitalWrite(6,HIGH);
    } else if (getData == "1off"){
      digitalWrite(5,LOW);
    } else if(getData == "2off"){
      digitalWrite(5,LOW);
    }

  }
}
