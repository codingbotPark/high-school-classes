import serial
import time
import RPi.GPIO as GPIO
import serial

GPIO.setmode(GPIO.BCM)

redPin = 21
bluePin = 20
greenPin = 16

GPIO.setup(redPin,GPIO.OUT)
GPIO.setup(bluePin,GPIO.OUT)
GPIO.setup(greenPin,GPIO.OUT)

ser = serial.Serial("/dev/ttyS0", baudrate=9600,timeout=1.0)

try:
    while True:
        sendData="I am raspberry 3307\r\n"
        ser.write(sendData.encode())
        time.sleep(1.0)
        
        line = ser.readline().decode('utf-8').rstrip()
        if line == "red_on":
            GPIO.output(redPin,GPIO.HIGH)
        elif line == "red_off":
            GPIO.output(redPin,GIPIO.LOW)
        elif line == "blue_on":
            GPIO.output(bluePin,GPIO.HIGH)
        elif line == "blue_off":
            GPIO.output(bluePin,GPIO.LOW)
        elif line == "green_on":
            GPIO.output(greenPin,GPIO.HIGH)
        elif line == "green_off":
            GPIO.output(greenPin,GPIO.LOW)

except KeyboardInterrupt:
    pass

GPIO.cleanup

bleSerial.close()
