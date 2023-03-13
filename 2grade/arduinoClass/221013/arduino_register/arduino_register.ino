void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(13,OUTPUT);
  // 7 6 5 4 / 3 2 1 0
  // 0 0 0 1 / 0 0 0 0
  DDRB |= (0x01 << 5);
  // ddrb의 5번 = 13
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWritE(13,HIGH);
  PORTB |= (0x01 << 5);
  delay(1000);
  // digitalWrite(13,LOW);
  PORTB &= ~(0x01 << 5);
  delay(1000);
}
