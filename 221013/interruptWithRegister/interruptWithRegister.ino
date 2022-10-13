void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB |= (0x01 << 5);
  DDRD &= ~(0x01 << 3);
  EICRA = 0x04;
  EIMSK = 0x02;
}

void loop() {
  // put your main code here, to run repeatedly:

}


SIGNAL(INT1_vect){
  int in_value = digitalRead(3);
  if(in_value == 1){
    PORTB |= (0x01 << 5);
  } else {
    PORTB &= ~(0x01 <<5);
  }
}