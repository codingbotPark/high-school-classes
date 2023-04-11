
# 필요 라이브러리
import RPi.GPIO as GPIO
import spidev
import time 

delay = 0.5

# MCP3008채널 중 센서에 연결한 채널 설정
ldr_channel = 0

#SPI인스턴스 spi생성
spi = spidev.SpiDev()

#SPI통신 시작하기
spi.open(0,0)

#SPI 통신 속도 설정
spi.max_speed_hz = 1000

GPIO.setmode(GPIO.BCM)
led_pin = 13
GPIO.setup(led_pin,GPIO.OUT)

def readadc(adcnum):
	if adcnum > 7 or adcnum < 0:
		return -1
	r = spi.xfer2([6 + ((adcnum&0x4) >> 2),(adcnum&0x3) << 6,0])

	data = ((r[1] & 15) << 8) + r[2]
	return data
		
while True:
	ldr_value = readadc(ldr_channel)
	print("-------")
	print("LDR Value: %d" % ldr_value)
	if (ldr_value < 3000):
		GPIO.output(led_pin,True)
	else:
		GPIO.output(led_pin,False)
		                                                                                                                   
	time.sleep(delay)
