// 인터럽트

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);

  // 눌렀을 때 1이 되기 때문에 인터럽트를 rising으로 설정
  attachInterrupt(1,myISR,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:

}

// // rising falling 테스트
// // 버튼이 눌렸을 때 실행
// void myISR(){
//   int in_value = digitalRead(3);
//   if(in_value == 1){
//     Serial.println("Rising");
//   } else {
//     Serial.println("Falling");
//   }
// }


// 눌렀을 때, 뗏을 때의 차이 시간 구하기
unsigned long first_time = 0;
unsigned long second_time = 0;
int diff_time = 0;

void myISR(){
  int in_value = digitalRead(3);
  if(in_value == 1){
    first_time = millis();
  } else {
    second_time = millis();
    diff_time = second_time - first_time;
    Serial.println(diff_time);
  }
}
