void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(3,INPUT);

}


char btn_flag= 0;

void loop() {
  // put your main code here, to run repeatedly:
  int in_value = digitalRead(3);

  // if (in_value == 1){
  //   if (btn_flag == 0){
  //     btn_flag = 1;
  //     Serial.println("Down");
  //   }
  // }else{
  //   if (btn_flag == 1) {
  //     btn_flag = 0;
  //     Serial.println("Up");
  //   }
  // }

  if (in_value == 1 && btn_flag = 0){
    btn_flag = 1;
    Serial.println("Down");
  } else if (inP_value == 0 && btn_flag == 1){
    btn_flag = 0;
  }

  delay(10);
}

// 누르면 1, 안 누르면 0 이기 때문에
