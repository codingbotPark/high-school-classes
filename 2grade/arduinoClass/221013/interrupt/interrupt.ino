void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB |= (0x01 << 5);
attachInterrupt(1,myISR,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void myISR(){
  int in_value = digitalRead(3);
  if (in_value == 1){
    PORTB |= (0x01 << 5);
  } else {
    PORTB &= ~(0x01 << 5);
  }
}
