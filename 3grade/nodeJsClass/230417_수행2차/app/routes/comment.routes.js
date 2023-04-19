const express = require("express")
const CommentController = require("../controller/comment.controller")
const CommentUseCase = require("../use-cases/comment")

class CommentRouter{
    constructor(){
        this.router = express.Router()
        this.commentController = new CommentController()
        this.commentUseCase = new CommentUseCase()
    }

    registerRoutes(){
        this.router.post('/',this.commentController.createComment.bind(this))
        this.router.patch('/:id',this.commentController.patchCommentById.bind(this))
        this.router.delete('/:id',this.commentController.deleteCommentById.bind(this))
        return this.router
    }
}

module.exports = CommentRouter