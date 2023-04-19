const { User,Comment } = require("../../models");



class UserUseCase{
    constructor(){}   

    async getAllUsers(){
        console.log(this)
        try {
            const users = await User.findAll();
            return {got:true, status:200, users:users}
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
            return {created:true, status:200, createdUser:user}
        } catch(err) {
            console.error(err)
            next(err)
        }
    }  

    async deleteUser({id}){
        console.log("----------",id)
        try {
            await User.destroy({where:{
                id:id
            }})
            return {deleted:true,status:200}
        } catch(err){
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
            return {got:true, status:200, comments}
        } catch(err){
            console.error(err)
            next(err)
        }
    }
}

module.exports = UserUseCase
