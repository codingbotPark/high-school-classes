const express = require('express');
const path = require('path')
const morgan = require('morgan');
const nunjucks = require('nunjucks');
const methodOverride = require('method-override')
const db = require('./models/index')
const cors = require('cors')

const {sequelize} = require('./models');

require('dotenv').config()

const router = require("./routes")

class App{
    constructor(){
        this.app = express()
        this.setSequelize();
        this.setting()
        this.setMiddleWare();
        this.getRouting();
        this.errorHadnling();
    }

    setSequelize(){
        db.sequelize.sync({force:false})
        .then(() => {
            console.log("✅ DB Connected")
        })
        .catch((err) => {
            console.error("❌ DB error")
            throw err
        })
    }

    setting(){
        this.app.set('view engine', 'html');
        nunjucks.configure('views', {
            express: this.app,
            watch: true,
        });
    }

    setMiddleWare(){
        this.app.use(cors())
        this.app.use(express.json())
        this.app.use(express.urlencoded({extended:false}))
        this.app.use(methodOverride());
        this.app.use(morgan('dev'))
        this.app.use(express.static(path.join(__dirname,'public')))
    }

    getRouting(){
        const indexRouter = new router.IndexRouter()
        this.app.use('/',indexRouter.registerRoutes())

        const userRouter = new router.UserRouter()
        this.app.use('/users',userRouter.registerRoutes())

        const commentRouter = new router.CommentRouter()
        this.app.use('/comments', commentRouter.registerRoutes())
    }

    errorHadnling(){
        this.app.use((req,res,next) => {
            console.log("에러로 들어옴")
            const error = new Error(`${req.method} ${req,url} 라우터가 없습니다`);
            next(error)
        })

        this.app.use((err,req,res,next) => {
            res.locals.message = err.message;
            res.locals.error = process.envNODE_ENV !== 'production' ? err : {};
            res.status(err.status || 500);
            // res.send("hi")
            res.render('error');
        })
    }
}

const app = new App()
module.exports = app.app