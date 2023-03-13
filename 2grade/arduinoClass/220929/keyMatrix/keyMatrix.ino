
// 버튼 네 개로 upDown
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  // Row
  pinMode(12, INPUT);
  pinMode(6, INPUT);
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);


  // Col
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
}

char flag_row1 = 0;
char flag_row2 = 0;
int row_port[2] = { 12, 6 };
char row_flag[2][2] = { { 0, 0 }, { 0, 0 } };
char col_port[2] = { 3, 11 };

void loop() {


  for (int j = 0; j < 2; j++) {
    // column off
    for (int i = 0; i < 2; i++) {
      digitalWrite(col_port[i], LOW);
    }

    // Col 1 HIGH
    // digitalWrite(3,HIGH);
    digitalWrite(col_port[j], HIGH);

    //Row
    for (int i = 0; i < 2; i++) {
      int row = digitalRead(row_port[i]);
      if (row == 0 && row_flag[i][j] == 0) {
        row_flag[i][j] = 1;
        Serial.println("button" + String(i * 2 + 1 * j) + "down");
      } else if (row == 1 && row_flag[i][j] == 1) {
        row_flag[i][j] = 0;
        Serial.println("button" + String(i * 2 + 1 * j) + "up");
      }
    }

    // 키보드는 아무리 빨리 눌러도 30ml안에 두 개 이상 안 들어간다
    delay(10);
  }
}
