const UserUseCase = require("../use-cases/user")

class UserController {
    constructor(){
        this.userUseCase = new UserUseCase()
    }

    async getAllUsers(req,res,next){
        try{
            const {got, status} = await this.userUseCase.getAllUsers()
            return {got,status}
        } catch(err){
            console.error(err)
            next(err)
        }
    }

    async insertUser(req,res,next){
        const {name,age,married} = req.body

        try{
            const {inserted,status} = await this.userUseCase.insertUser({name,age,married})
            return {inserted,status}
        } catch(err){
            console.error(err)
            next(err)
        }

    }  

    async getComment(req,res,next){
        const {id} = req.body

        try{
            const {got,status} = await this.userUseCase.getComment({id})
            return {got,status}
        } catch(err){
            console.error(err)
            next(err)
        }

    }
}

module.exports = UserController