const express = require('express');
const path = require('path')
const morgan = require('morgan');
const nunjucks = require('nunjucks');
const methodOverride = require('method-override')
const db = require('models/index')

const {sequelize} = require('./models');

require('dotenv').config()

export class App{
    constructor(){
        this.app = express()
        this.setSequelize();
        this.setMiddleWare();
        this.getRouting();
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

    setMiddleWare(){
        this.app.use(cors())
        this.app.use(express.json())
        this.app.use(express.urlencoded({extended:false}))
        this.app.use(methodOverride());
    }

    getRouting(){

    }
}
