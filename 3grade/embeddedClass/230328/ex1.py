import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)

while True:
    GPIO.output(17, GPIO.HIGH) # LED 켜기
    time.sleep(1)              # 1초 동안 대기
    GPIO.output(17, GPIO.LOW)  # LED 끄기
    time.sleep(1)              # 1초 동안 대기
