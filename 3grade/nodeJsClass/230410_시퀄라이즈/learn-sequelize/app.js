const express = require('express')
const morgan = require('morgan')
const path = require('path')
const nunjucks = require('nunjucks')

const {sequelize} = require('./models');

const app  =express()
app.set('port',process.env.PORT||3000)
app.set('view engine','html')
nunjucks.configure('views',{
    express:app,
    watch:true
})

app.use(morgan('dev'))
app.use(express.static(path.join(__dirname,'public')))
app.use(express.json())
app.use(express.urlencoded({extended:false}))

// 실제 코드 들어갈 부분

app.use((req,res,next) => {
    const error = new Error('존재하지 않는 주소')
    error.status = 404
    next(error)
}) // 404
app.use((err,req,res,next) => {
    res.locals.message = err.message;
    res.status = err.status || 500
    res.render('error')
})
app.listen(app.get('port'), () => {
    console.log(app.get('port'),'번 포트에서 대기중');
})
