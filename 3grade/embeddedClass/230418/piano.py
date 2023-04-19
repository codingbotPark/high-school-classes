

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

keys = [26,19,13,6,5]
for key in keys: # 초기화
	print(key)
	GPIO.setup(keys, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(keys[0], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(keys[1], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(keys[2], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(keys[3], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(keys[4], GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
	
buzz_pin = 21

# gpio 18번 핀을 출력으로 설정
GPIO.setup(buzz_pin,GPIO.OUT)

p = GPIO.PWM(buzz_pin,100)
Frq = [262,294,330,349,392]
speed = 0.005

p.start(10)


try:
	while True:
		if GPIO.input(keys[0]) == GPIO.HIGH:
			p.ChangeFrequency(Frq[0])
		elif GPIO.input(keys[1]) == GPIO.HIGH:
			p.ChangeFrequency(Frq[1])
		elif GPIO.input(keys[2]) == GPIO.HIGH:
			p.ChangeFrequency(Frq[2])
		elif GPIO.input(keys[3]) == GPIO.HIGH:
			p.ChangeFrequency(Frq[3])
		elif GPIO.input(keys[4]) == GPIO.HIGH:
			p.ChangeFrequency(Frq[4])
		else:
			p.ChangeFrequency(1)
finally:
	p.stop(0)
	GPIO.cleanup()

"""
try:
	while 1:
		for idx in range(len(keys)):
			if (GPIO.input(keys[idx])):
				p.ChangeFrequency(Frq[idx])
		
				
			else:
				p.ChangeFrequency(1)
				
			# p.ChangeFrequency(fr)

			
		
finally:
	p.stop()
	GPIO.cleanup()
"""
