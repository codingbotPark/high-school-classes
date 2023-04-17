import spidev
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
buzz_pin = 18
GPIO.setup(buzz_pin,GPIO.OUT)

delay = 0.5

pot_channel = 0

spi = spidev.SpiDev() # spi 인스턴스 spi 생성
spi.open(0,0) # spi 통신 시작하기

spi.max_speed_hz = 100000

def readadc(adcnum):
	if adcnum > 7 or adcnum < 0:
		return -1
	r = spi.xfer2([1,8 + adcnum << 4, 0])
	data = ((r[1] & 3) << 8) + r[2]
	return data

while True:
	pot_value = readadc(pot_channel)
	print("--------------")
	print("POT Value : %d" % pot_value)
	
	if pot_value > 310:
		GPIO.output(buzz_pin,True)
	else:
		GPIO.output(buzz_pin,False)
	
	time.sleep(delay)

