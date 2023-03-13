//String str = "";
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  if(Serial.available()) {
//    str = Serial.readString();
//    Serial.println(str);
//  }
//}


int servoPin = 10;
int angle = 0;

  int interval = 20000;
  
  void servo(int pin,int cycle){
    
     for (int i = 0;i<100;i++){
      digitalWrite(pin,HIGH);
      delayMicroseconds(cycle);
      digitalWrite(pin,LOW);
      delayMicroseconds(interval-cycle);
      }
    }

void setup() {
  // put your setup code here, to run once:
  Serial.setTimeout(100);
  Serial.begin(9600);
  pinMode(5,OUTPUT); // led1
  pinMode(6,OUTPUT); // led2
  pinMode(servoPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // servo.write(180);


  if (Serial.available()){
    String getData = Serial.readString();
    Serial.println(getData);
    if (getData == "led1on") { // led1 on
      digitalWrite(5,HIGH);
    } else if (getData == "led2on"){
      digitalWrite(6,HIGH);
    } else if (getData == "led1off"){
      digitalWrite(5,LOW);
    } else if(getData == "led2off"){
      digitalWrite(6,LOW);
    } else if (getData == "servoLeft"){
      servo(servoPin,2400);
    } else if (getData == "servoRight"){
      servo(servoPin,500);
    }

    Serial.flush();
  }


  }
