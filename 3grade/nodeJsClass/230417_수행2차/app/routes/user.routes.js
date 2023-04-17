const express = require('express')
const UserController = require("../controller/user.controller")

class UserRoutes{

    constructor(){
        this.router = express.Router
        this.userController = new UserController()
    }

    registerRoutes(){
        this.router('/')
        .get(this.userController.getAllUsers)
        .post(this.userController.insertUser)

        this.router('/:id/comments')
        .get(this.userController.getComment)

        return this.router
    }
}


module.exports = UserRoutes