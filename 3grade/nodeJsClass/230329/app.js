const express = require("express")
const morgan = require("morgan")
const path = require('path')

// index파일은 폴더 이름만 적어도 불러온다
const indexRouter = require('./routes');
const userRouter = require("./routes/user");

const app = express()

app.set('views',path.join(__dirname,'views'))
app.set('view engine','pug')

app.use(morgan('dev'))
// 이미지 형식으로 요구시 public에서 이미지를 찾는다
app.use(express.static(path.join(__dirname, 'public')))
// 객체가 오면 json으로 만든다
app.use(express.json())
app.use(express.urlencoded({extended:false}))

app.set('port',process.env.PORT || 3000)

// 주소만 명시 = use
app.use('/',indexRouter)
app.use('/users',userRouter)

app.listen(3000,() => {
    console.log("3000번 포트에서 대기중")
})
