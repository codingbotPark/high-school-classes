import tkinter as tk 
import os
import time
import requests
import re

url="http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=2771038000"

window = tk.Tk()
window.title("TEMP HUMI DISPLAY")
window.geometry("480x200")
window.resizable(False,False)

response = requests.get(url)

temp = re.findall(r'<temp>(.+)</temp>',response.text)
humi = re.findall(r'<reh>(.+)</reh>',response.text)

print(temp[0] + ' ' + humi[0])

label = tk.Label(window,text='{}C {}%'.format(temp[0],humi[0]),font=("Helvetica",32))
label.pack(pady=50)

window.mainloop()

# while True:
#    label = tk.Label(window,text=os.popen(" vcgtencmd measure_temp ").readline())
#    label.pack()
#    time.sleep(1.0)
