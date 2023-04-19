const express = require('express')
const PageController = require("../controller/index.controller")
const UserUseCase = require("../use-cases/user")

class IndexRouter{
    constructor(){
        this.router = express.Router()
        this.pageController = new PageController()
        this.userUseCase = new UserUseCase()
    }

    registerRoutes(){
        this.router.get('/',this.pageController.getMainPage.bind(this))

        return this.router
    }
}

module.exports = IndexRouter