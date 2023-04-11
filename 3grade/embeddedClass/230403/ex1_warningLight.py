import RPi.GPIO as GPIO
import timefxg
GPIO.setmode(GPIO.BCM)
GPIO.setup(16, GPIO.OUT)
GPIO.setup(20, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)

# def execut(port):
	

while True:
    GPIO.output(16, GPIO.HIGH) # LED 켜기
    GPIO.output(20, GPIO.HIGH)  # LED 켜기
    GPIO.output(21, GPIO.HIGH)  # LED 켜기
    time.sleep(0.1)              # 0.1초 동안 대기
    GPIO.output(16, GPIO.LOW)  # LED 끄기
    GPIO.output(20, GPIO.LOW)  # LED 끄기
    GPIO.output(21, GPIO.LOW)  # LED 끄기
    time.sleep(0.1)              # 0.1초 동안 대기
    GPIO.cleanup

