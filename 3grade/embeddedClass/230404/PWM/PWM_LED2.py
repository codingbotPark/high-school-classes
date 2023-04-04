import RPi.GPIO as GPIO
import time

button_pin = 18
led_pin = 17

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

GPIO.setup(led_pin,GPIO.OUT)
p = GPIO.PWM(led_pin,50) 
p.start(0)

flag = False
buttonFlag = True;

def buttonClick():
	

try:
	while True:
		if GPIO.input(button_pin) == GPIO.LOW and not flag:
			flag = True
			while True:
				if not flag:
					break
				for i in range(0,50):
					p.ChangeDutyCycle(i);	
					time.sleep(0.01);
				if not flag:
					break
				for i in range(50,0,-1):
					p.ChangeDutyCycle(i);
					time.sleep(0.01);
					if GPIO.input(button_pin) == GPIO.LOW:
						flag = False
				if not flag:
					break
		else:
			GPIO.output(led_pin, False)
			
except KeyboardInterrupt:
	GPIO.cleanup



					
