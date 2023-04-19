
class CommentController{
    async createComment(req,res,next){
        const {id,comment} = req.body

        try {
            const {created,status,createdComment} = await this.commentUseCase.createComment({id,comment})
            res.json({created,status,createdComment})
        } catch(err){
            console.error(err)
            next(err)
        }

    }

    async patchCommentById(req,res,next){
        const {comment} = req.body
        const {id} = req.params

        try {
            const {patched, status, fetchedComment} = await this.commentUseCase.patchCommentById({id,comment})

            res.json({patched, status, fetchedComment})
        } catch(err) {
            console.error(err);
            next(err)
        }
    }

    async deleteCommentById(req,res,next){
        const {id} = req.params

        try{
            const {deleted,status} = await this.commentUseCase.deleteCommentById({id})
            res.json({deleted,status})
        } catch(err){

        }
    }
}

module.exports = CommentController