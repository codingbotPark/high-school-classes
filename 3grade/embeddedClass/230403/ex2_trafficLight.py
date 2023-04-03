import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(2, GPIO.OUT)
GPIO.setup(3, GPIO.OUT)
GPIO.setup(4, GPIO.OUT)
GPIO.setup(20, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)

	

while True:
    GPIO.output(4, GPIO.HIGH) # LED 켜기
    GPIO.output(20, GPIO.HIGH)  # LED 켜기
    time.sleep(3)              # 0.1초 동안 대기
    
    GPIO.output(4, GPIO.LOW) # LED 켜기
    GPIO.output(20, GPIO.LOW)  # LED 켜기
    GPIO.output(3, GPIO.HIGH) # LED 켜기
    time.sleep(3)              # 0.1초 동안 대기
    
    GPIO.output(3, GPIO.LOW) # LED 켜기
    GPIO.output(2, GPIO.HIGH)  # LED 끄기
    GPIO.output(21, GPIO.HIGH)  # LED 끄기
    time.sleep(3)              # 0.1초 동안 대기
    
    GPIO.output(2, GPIO.LOW)  # LED 끄기
    GPIO.output(21, GPIO.LOW)  # LED 끄기

    GPIO.cleanup
