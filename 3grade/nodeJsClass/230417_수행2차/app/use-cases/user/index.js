const { User } = require("../../models");


class UserUseCase{
    constructor(){}   

    async getAllUsers(req,res,next){
        try {
            const user = await User.findAll();
            res.json(user)
        } catch(err) {
            console.error(err);
            next(err);
        }
    }

    async insertUser({
        name,
        age,
        married
    }){
        try {
            const user =  await User.create({
                name,
                age,
                married    
            })
        } catch(err) {
            console.error(err)
            next(err)
        }
    }  

    async getCommentByUser({id}){
        try {
            const comments = await Comment.findAll({
                include:{
                    model:User,
                    where:{id}
                }
            })
            console.log(comments)
            res.json(comments)
        } catch(err){
            console.error(err)
            next(err)
        }
    }
}

module.exports = UserUseCase