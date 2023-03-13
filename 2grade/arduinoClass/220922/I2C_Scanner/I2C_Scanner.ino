#define SCL 19
#define SDA 18

#define SCL_HIGH() digitalWrite(SCL, HIGH)
#define SCL_LOW() digitalWrite(SCL, LOW)
#define SDA_HIGH() digitalWrite(SDA, HIGH)
#define SDA_LOW() digitalWrite(SDA, LOW)

void setup() {
  Serial.begin(9600);
    // 로우를 떨어질 때 시간차가 있어야 하는데,
    // 아두이노는 함수 자체가 시간 자체를 까먹어서 delay가 필요없다
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);
}

void loop() {
  PCF8574_set(0xff);
    delay(1000);
  PCF8574_set(0x00);
  delay(1000);
}

void i2c_start() {
  // Start Condition
  SCL_HIGH();
  SDA_HIGH();
  SDA_LOW();
}

void i2c_8bit_set(unsigned char data) {
  // for문을 사용해서 8번 돌린다
  for (int i = 0; i < 8; i++) {

    // Device Address
    if (data & 0x80 >> i) {
      SDA_HIGH();
    } else {
      SDA_LOW();
    }
    SCL_HIGH();
    SCL_LOW();
  }
}

void i2c_ack() {
  // ACK for Device Address
  pinMode(SDA, INPUT);
  SCL_HIGH();
  int ack_value = digitalRead(SDA);
  Serial.println(ack_value);
  pinMode(SDA, OUTPUT);
  SCL_LOW();
}

void i2c_stop() {
  // Stop
  SDA_LOW();
  SCL_HIGH();
  SDA_HIGH();
}

void PCF8574_set(unsigned char data) {
  // Start Condition
  i2c_start();

  // device address 설정
  i2c_8bit_set(0x27 << 1);

  // ack
  i2c_ack();

  // Data
  i2c_8bit_set(0xff);

  // ack
  i2c_ack();

  // stop
  i2c_stop();
}

// #include <Wire.h>


// void setup()
// {
//   Wire.begin();

//   Serial.begin(9600);
//   while (!Serial);             // Leonardo: wait for serial monitor
//   Serial.println("\nI2C Scanner");
// }


// void loop()
// {
//   byte error, address;
//   int nDevices;

//   Serial.println("Scanning...");

//   nDevices = 0;
//   for(address = 1; address < 127; address++ )
//   {
//     // The i2c_scanner uses the return value of
//     // the Write.endTransmisstion to see if
//     // a device did acknowledge to the address.
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0)
//     {
//       Serial.print("I2C device found at address 0x");
//       if (address<16)
//         Serial.print("0");
//       Serial.print(address,HEX);
//       Serial.println("  !");

//       nDevices++;
//     }
//     else if (error==4)
//     {
//       Serial.print("Unknown error at address 0x");
//       if (address<16)
//         Serial.print("0");
//       Serial.println(address,HEX);
//     }
//   }
//   if (nDevices == 0)
//     Serial.println("No I2C devices found\n");
//   else
//     Serial.println("done\n");

//   delay(5000);           // wait 5 seconds for next scan
// }