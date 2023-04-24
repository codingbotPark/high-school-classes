import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

TRIG = 16
ECHO = 20

print("Distance measurement in progress")

GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)

# Trig 핀의 신호를 0으로 출력
GPIO.output(TRIG,False)
print("Waiting for sensor to settle")
time.sleep(2)

buzz_pin = 21
GPIO.setup(buzz_pin,GPIO.OUT)
p = GPIO.PWM(buzz_pin,100)
frq = [262,294,330,349,392]
p.start(10)

def buzzOn(dt):
	value = (round(dt)+10) // 10
	print(value)
	if (value > 0 and value < len(frq) + 1):
		print("on")
		p.ChangeFrequency(frq[value-1])
	else:
		print("off")
		p.ChangeFrequency(1)

try:
	while True:
		# Triger 핀에 펄스신호를 만들기 위해 1 출력
		GPIO.output(TRIG, True)
		time.sleep(0.00001) # 10μs 딜레이
		GPIO.output(TRIG, False)
		# start time
		while GPIO.input(ECHO)==0:
			start = time.time()
		while GPIO.input(ECHO)==1:
			stop= time.time() # Echo 핀 하강 시간
			
		check_time = stop - start
		distance = check_time * 34300 / 2
		print("Distance : %.1f cm" % distance)
		buzzOn(distance)
		time.sleep(0.4) # 0.4초 간격으로 센서 측정
except KeyboardInterrupt:
	print("Measurement stopped by User")
	GPIO.cleanup()


