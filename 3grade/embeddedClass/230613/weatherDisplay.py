import tkinter as tk 
import os
import time
import requests
import re

import RPi.GPIO as GPIO

green_pin = 21
blue_pin = 20
red_pin = 16
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(green_pin,GPIO.OUT)
GPIO.setup(blue_pin,GPIO.OUT)
GPIO.setup(red_pin,GPIO.OUT)

url="https://apis.data.go.kr/B552584/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty?serviceKey=ii5UxsUSVnzOjxGH0M5qCHuUC24d02h6HIKw7bd3Zo9wlW%2BkS6i%2BojgN2maQ56KExD%2B7i6PqmQpiTI13yinOOg%3D%3D&returnType=xml&numOfRows=100&pageNo=1&sidoName=%EB%8C%80%EA%B5%AC&ver=1.0"
response = requests.get(url)

pm10 = re.findall(r'<pm25Value>(.+)</pm25Value>',response.text)
stationName = re.findall(r'<stationName>(.+)</stationName>',response.text)


dust = int(pm10[stationName.index('화원읍')])
print('dust' + str(dust))

def clearPins():
	GPIO.output(green_pin,False)
	GPIO.output(blue_pin,False)
	GPIO.output(red_pin,False)

if dust <= 30:
	clearPins()
	GPIO.output(green_pin,True)
elif dust < 80:
	clearPins()
	GPIO.output(blue_pin,True)
elif dust < 150:
	clearPins()
	GPIO.output(red_pin,True)
else:
	GPIO.output(green_pin,True)
	GPIO.output(blue_pin,True)
	GPIO.output(red_pin,True)
