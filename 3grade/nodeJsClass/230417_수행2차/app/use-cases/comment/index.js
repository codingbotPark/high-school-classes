const { Comment } = require("../../models");



class CommentUseCase{
    constructor(){}   

    async createComment({
        id,
        comment
    }){
        console.log(this)
        try {
            const createdComment = await Comment.create({
                id,
                comment
            });
            return {created:true, status:200, createdComment:createdComment}
        } catch(err) {
            console.error(err);
            next(err);
        }
    }

    async patchCommentById({id,comment}){
        try {
            const fetchedComment =  await Comment.update({
                comment:comment
            }, {
                where:{id:id}
            })
            return {patched:true, status:200, fetchedComment:fetchedComment}
        } catch(err) {
            console.error(err)
            next(err)
        }
    }  

    async deleteCommentById({id}){
        try {
            await Comment.destroy({where:{
                id:id
            }})
            return {deleted:true,status:200}
        } catch(err){
            console.error(err)
            next(err)
        }
    }
}

module.exports = CommentUseCase
