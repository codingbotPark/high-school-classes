import tkinter as tk 
import os
import time


try:
	window = tk.Tk()
	window.title("CPU TEMPERATURE")
	window.geometry("480x200")
	window.resizable(False,False)
	
	i = 0
	while True:
		
		temp = os.popen(" vcgencmd measure_temp ").readline()
		i=i+1
		
		label =tk.Label(window,text='{}'.format(temp),font=("Helvetica",32))
		label.pack()
		window.update()
		label.config(text="")
		label.pack_forget()
		
		time.sleep(1.0)
		
except KeyboardInterrupt:
	pass



# while True:
#    label = tk.Label(window,text=os.popen(" vcgtencmd measure_temp ").readline())
#    label.pack()
#    time.sleep(1.0)
