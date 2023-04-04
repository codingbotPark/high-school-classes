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


levelLights = [0,10,30,50]
level = 0


try:
	p.ChangeDutyCycle(0)
	while True:
		if GPIO.input(button_pin) == GPIO.LOW:
			while True:
			if nGPIO.input(button_pin: # 달라질 때 실행
				level+=1
				if level >= len(levelLights):
					GPIO.output(led_pin,False)
					level = 0;
				p.ChangeDutyCycle(levelLights[level])
				time.sleep(0.5)
			
except KeyboardInterrupt:
	GPIO.cleanup



					
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


levelLights = [0,10,30,50]
level = 0


try:
	p.ChangeDutyCycle(0)
	while True:
		if GPIO.input(button_pin) == GPIO.LOW:
			if nGPIO.input(button_pin: # 달라질 때 실행
				level+=1
				if level >= len(levelLights):
					GPIO.output(led_pin,False)
					level = 0;
				p.ChangeDutyCycle(levelLights[level])
				time.sleep(0.5)
			
except KeyboardInterrupt:
	GPIO.cleanup



					
