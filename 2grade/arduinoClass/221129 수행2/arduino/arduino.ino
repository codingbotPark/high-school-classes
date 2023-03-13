#include <Servo.h>
Servo servo;
int servoPin = 10;
int angle = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.setTimeout(100);
  Serial.begin(9600);
  pinMode(5,OUTPUT); // led1
  pinMode(6,OUTPUT); // led2
  pinMode(servoPin,OUTPUT);

  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  // servo.write(180);


  if (Serial.available()){
    String getData = Serial.readString();
    Serial.println(getData);
    if (getData == "1on") { // led1 on
      digitalWrite(5,HIGH);
    } else if (getData == "2on"){
      digitalWrite(6,HIGH);
    } else if (getData == "1off"){
      digitalWrite(5,LOW);
    } else if(getData == "2off"){
      digitalWrite(6,LOW);
    } else if (getData == "3left"){
      servo.write(10);
    } else if (getData == "3right"){
      servo.write(170);
    }

    Serial.flush();
  }
}
