const express = require('express')
const UserController = require("../controller/user.controller")
const UserUseCase = require('../use-cases/user')

class UserRouter{

    constructor(){
        this.router = express.Router()
        this.userController = new UserController()
        this.userUseCase = new UserUseCase()
    }

    registerRoutes(){
        // this.router('/')
        // .get(this.userController.getAllUsers)
        // .post(this.userController.insertUser)

        // this.router('/:id/comments')
        // .get(this.userController.getComment)

        // this.router.get('/',this.userController.getAllUsers.bind(this.userController))
        // this.router.post('/',this.userController.insertUser.bind(this.userController))
        // this.router.get('/:id/comments',this.userController.getComment.bind(this.userController))

        this.router.get('/',this.userController.getAllUsers.bind(this))
        this.router.post('/',this.userController.insertUser.bind(this))
        this.router.delete('/',this.userController.deleteUser.bind(this))
        this.router.get('/:id/comments',this.userController.getCommentByUser.bind(this))

        return this.router
    }
}


module.exports = UserRouter