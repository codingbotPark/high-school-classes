from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
    return "hello"
@app.route('/page/<uid>')
def page_route(uid):
    return uid+"page ok"

if __name__ == '__main__':
    app.run(debug=True, port=80, host='0.0.0.0')
