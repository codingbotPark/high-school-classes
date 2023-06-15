const express = require("express")
const cookieParser = require("cookie-parser")
const morgan = require("morgan")
const path = require("path")
const session = require("express-session")
const nunjucks = require("nunjucks")
const dotenv = require("dotenv")
const methodOverride = require("method-override")

const pageRouter = require('./routes/page')
const authRouter = require('./routes/auth')
const postRouter = require("./routes/post")
const userRouter = require("./routes/user")
const { sequelize } = require("./models")
const passport = require("passport")
const passportConfig = require("./passport/index")


dotenv.config()


// 세팅
const app = express()
app.set('port', process.env.PORT || 8001)
app.set('view engine', 'html');
nunjucks.configure('views', {
  express: app,
  watch: true,
});
sequelize.sync({ force: false })
  .then(() => {
    console.log('데이터베이스 연결 성공');
  })
  .catch((err) => {
    console.error(err);
});

passportConfig()
// 미들웨어 세팅
app.use(morgan('dev'))
app.use(express.static(path.join(__dirname,'public')))
app.use('/img', express.static(path.join(__dirname,'uploads')));

app.use(express.json())
app.use(express.urlencoded({extended:false}))
app.use(methodOverride())
app.use(cookieParser(process.env.COOKIE_SECRET))
// 인메모리세션 = 서버를 껏다 키면 안됨
// 파일 세션 = 서버를 껏다 켜도 됨, 속도가 느림
// DB 세션 = 서버를 껏다 켜도 됨, DB IO가 일어남
app.use(session({
    resave:false,
    saveUninitialized:false,
    secret:process.env.COOKIE_SECRET,
    cookie:{
        httpOnly:true,
        secure:false, // true를 하면 https만 사용할 수 있다
    }
}))

app.use(passport.initialize())
app.use(passport.session())

// router세팅
app.use('/',pageRouter)
app.use('/auth',authRouter)
app.use('/post',postRouter)
app.use('/user',userRouter)


// 404에러 핸들링
app.use((req,res,next) => {
    const error = new Error(`${req.url}라우터가 없습니다`)
    error.status = 404
    next(error)
})

// 에러핸들링
app.use((err,req,res,next) => {
    res.locals.message = err.message;
    // 배포중일 땐 에러 객체를 숨겨서 메시지만 출력한다
    res.locals.error = process.env.NODE_ENV !== 'production' ? err: {};
    res.status(err.status || 500)
    res.render('error')
})


module.exports = app