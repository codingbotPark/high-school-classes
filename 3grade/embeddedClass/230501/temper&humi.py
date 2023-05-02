import time
import Adafruit_DHT
import RPi.GPIO as GPIO
import datetime

redPin = 21
bluePin = 20
greenPin = 16

GPIO.setmode(GPIO.BCM)
GPIO.setup(redPin,GPIO.OUT)
GPIO.setup(bluePin, GPIO.OUT)
GPIO.setup(greenPin,GPIO.OUT)

sensor = Adafruit_DHT.DHT11
pin = 4


def writeRecord(value):
	now = datetime.datetime.now()
	f = open('temphumi.txt','a')
	string = str(now) + " " + str(round(value)) + '\r\n'
	print(string)
	f.write(string)
	f.close()


try:
	while True:
		h, t = Adafruit_DHT.read_retry(sensor,pin)
		if (h is not None) and (t is not None):
			print("Temperature = {0:0.1f}*C Humidity = {1:0.1f}%".format(t,h))
			
			value = (1.8 * t) - (0.55*(1 - (h / 100)) * (1.8 * t - 26)) + 32
			print("value",value)
			
			writeRecord(value)
			
			if value < 70:
				GPIO.output(greenPin,True)
				GPIO.output(bluePin,False)
				GPIO.output(redPin,False)
			elif value < 76:
				GPIO.output(greenPin,False)
				GPIO.output(bluePin,True)
				GPIO.output(redPin,False)
			else:
				GPIO.output(greenPin,False)
				GPIO.output(bluePin,False)
				GPIO.output(redPin,True)
			
		else:
			print('Read error')
		time.sleep(1)
except KeyboardInterrupt:
	print("Terminated by Keyboard")
finally:
	print("End of Program")
