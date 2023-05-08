import picamera
import time
import datetime

with picamera.PiCamera() as camera:
    camera.resolution = (1024, 768)
    camera.start_preview()
    time.sleep(2)
    camera.capture('/home/codingbotpark/high-school-classes/3grade/embeddedClass/230508/'+str(datetime.datetime.now())+'.jpg')

