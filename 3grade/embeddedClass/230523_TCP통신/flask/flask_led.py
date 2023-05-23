from flask import Flask,request, render_template
import RPi.GPIO as GPIO

app = Flask(__name__)

ledPin = 21

GPIO.setmode(GPIO.BCM)
GPIO.setup(ledPin,GPIO.OUT)
GPIO.output(ledPin,0)

@app.route('/')
def flask():
    return render_template('index.html')
@app.route('/data',methods = ['POST'])
def controllLED():
    ledValue = request.form['led']
    
    print(ledValue)

    if 'on' == ledValue:
        GPIO.output(ledPin,1)
    elif 'off' == ledValue:
        GPIO.output(ledPin,0)

    return render_template('index.html')


if __name__ == "__main__":
    app.run(host = "0.0.0.0", port="80")
