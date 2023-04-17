const express = require("express")
const userRouter = require("./routes/userRouter")
const morgan = require("morgan")
const path = require('path')
const nunjucks = require('nunjucks')
const dotenv = require('dotenv')
dotenv.config()

const app =express()

app.use('/users',userRouter)

app.set('port',process.env.PORT || 3000)
app.set('view engine','html')
nunjucks.configure('views',{
    express:app,
    watch:true,
})

app.use(morgan('dev'))
app.use(express.json())
app.use(express.urlencoded({extended:false}))

// 404페이지 구성
app.use((req,res,next) => {
    const error = new Error("존재하지 않는 주소입니다")
    error.status = 404
    next('error');
})
app.use((err,req,res,next) => {
    res.locals.message = err.message;
    res.status(err.status || 500)
    res.render('error')
})


app.listen(3000,() => {
    console.log("3000번 포트에서 대기중")
})