import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)
GPIO.setup(21, GPIO.IN, pull_up_down=GPIO.PUD_UP)

try:
	while True:
		if  GPIO.input(21) == GPIO.LOW:
			GPIO.output(23, True) # LED 켜기
			GPIO.output(24, False)  # LED 켜기
			time.sleep(0.1)              # 0.1초 동안 대기
			GPIO.output(23, False)  # LED 끄기
			GPIO.output(24, True)  # LED 끄기
			time.sleep(0.1)              # 0.1초 동안 대기
		else:
			GPIO.output(23, False)  # LED 끄기
			GPIO.output(24, False)  # LED 끄기
		
except KeyboardInterrupt:
	GPIO.cleanup
	
