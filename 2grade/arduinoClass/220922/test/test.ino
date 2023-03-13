/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("haha");

  pinMode(13, OUTPUT);
  pinMode(9,OUTPUT);

}

// the loop function runs over and over again forever
int count = 0;
int count_100ms = 0;
int duty = 0;

int rgbCount = 0;
int duty200 = 0;

void loop() {

  // // 10 단계로 밝기 변화
  // for (int i = 1; i <= 10; i++) {
  //   for (int j = 0; j < 100; j++) {
  //     digitalWrite(13, HIGH);
  //     delay(i);
  //     digitalWrite(13, LOW);
  //     delay(10 - i);
  //   }
  // }



  //// 껏다켰다
  // for (int i = 0; i < 100; i++) {

  //   digitalWrite(13, HIGH);
  //   delay(9);
  //   digitalWrite(13, LOW);
  //   delay(1);
  // }

  // for (int i = 0; i < 100; i++) {

  //   digitalWrite(13, HIGH);
  //   delay(1);
  //   digitalWrite(13, LOW);
  //   delay(9);
  // }

  // ===========


  if (count == 100){
    count = 0;
    digitalWrite(13,HIGH);
  } else if (count == duty){
    digitalWrite(13,LOW);
  }

  if (rgbCount == 200){
    rgbCount = 0;
    digitalWrite(9,HIGH);
  } else if (rgbCount == duty200){
    digitalWrite(9,LOW);  
  }

  // ===========

  // 100ms마다 실행된다
  if (count_100ms == 100){
    count_100ms = 0;
    duty++;
    duty200++;
    if (duty == 99) duty = 1;
    if (duty200 == 199) duty200 = 1;
  }

  // ===========
  count++;
  count_100ms++;
  rgbCount++;
  // delay(1);
  delayMicroseconds(100);

}



  // start = clock이 하이일 때 데이터는 로우로 떨어진다 datariding (SDA, SCL = 핀 이름)
  // end = clock이 하이일 때 데이터는 하이로 올라간다
  // start -> 1010000디바이스add -> wirte bit 0 -> ack를 받고 -> memadd 0x50 -> ack받고 -> data0x80 -> ack받고 -> end



