// librarys
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// wiring Pi
#include <wiringPi.h>
#include <wiringSerial.h>

#include <pthread.h>
#include <softPwm.h>

#define LED_PIN 1
#define SERVO_PIN 0 	


char device[] = "/dev/ttyACM0";
// fileDescriptor
int fd;

unsigned long baud = 9600;

// prototypes
int main(void);
void loop(void);
void setup(void);

// pwm
int bright = 0;
// servo var
int grade = 0;

int pwmFlag = 0;
int servoFlag = 0;


void LEDOn(){
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,HIGH);
}
void LEDOff(){
	pinMode(LED_PIN,OUTPUT);
	digitalWrite(LED_PIN,LOW);
}
void LEDPWM(){ // thread
	pinMode(LED_PIN, PWM_OUTPUT);
	pwmFlag	= 1;
}
void ServoLeft(){
	softPwmCreate(SERVO_PIN,0,200);
	softPwmWrite(SERVO_PIN,24);
}
void ServoRight(){
	softPwmCreate(SERVO_PIN,0,200);
	softPwmWrite(SERVO_PIN,5);
}
void ServoVar(){
	softPwmCreate(SERVO_PIN,0,200);
	servoFlag = 1;
}
void All(){
	pwmFlag = 1;
	servoFlag = 1;
}

// --

void* threadLEDPWM(void* arg){// thread

	while(1){
	for(bright;bright < 1024;bright++){delay(1);}
	for(bright;bright >= 0; bright--){delay(1);}
	}
	 
	

}
void* threadServoVar(void* arg){ // thread
	while(1){
		for (grade;grade < 25;grade++){delay(20);}
		for (grade;grade > 5;grade--){delay(20);}
		
		
		/*
		ServoLeft();
		delay(1000);
		ServoRight();
		* */
	}
}


void clenUpFlag(){
	pwmFlag = 0;
	servoFlag = 0;
}



void setup(){
	printf("%s \n","Rasberry Start");
	fflush(stdout);
	
	// get filedescriptor
	if ((fd = serialOpen (device,baud)) < 0){
		fprintf(stderr,"Unable to open serial device : %s \n",strerror (errno));
		exit(1);
	}
	
	if (wiringPiSetup() == -1){
		fprintf(stdout,"Unable to start wiringPi : %s\n",strerror(errno));
		exit(1);
	}
	
	pthread_t threadLED, threadServo;
	pthread_create(&threadLED, NULL,threadLEDPWM,NULL);
	pthread_create(&threadServo, NULL, threadServoVar, NULL);
	
}

void loop(){
	
	  // flags
  if (pwmFlag == 1){
	pwmWrite(LED_PIN,bright);
	}
	if (servoFlag == 1){
		softPwmWrite(SERVO_PIN,grade);
	}
	
 
  // read signal
  if(serialDataAvail (fd)){
    char newChar = serialGetchar(fd);
    
    printf("%c",newChar);
   
    switch(newChar){
		case '1':
			clenUpFlag();
			LEDOn();
			break;
		case '2':
			clenUpFlag();
			LEDOff();
			break;
		case '3':
			clenUpFlag();
			LEDPWM();
			break;
		case '4':
			clenUpFlag();
			ServoLeft();
			break;
		case '5':
			clenUpFlag();
			ServoRight();
			break;
		case '6':
			clenUpFlag();
			ServoVar();
			break;
		case '7':
			clenUpFlag();
			ServoVar();
			LEDPWM();
			break;
	}
    
    fflush(stdout);
  } 
  

 
}
 
// main function for normal c++ programs on Raspberry
int main(){
  setup();
  while(1) loop();
  return 0;
}









