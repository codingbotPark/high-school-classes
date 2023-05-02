import time
import datetime

try:
	while True:
		now = datetime.datetime.now()
		print(now)
		time.sleep(1.0)
except KeyboardInterrupt:
	pass
