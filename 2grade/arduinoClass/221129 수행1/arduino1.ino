String str = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    str = Serial.readString();
    Serial.println(str);
  }
}
