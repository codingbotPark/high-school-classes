class UserController{

    async getAllUsers(req,res,next){
        console.log(this.userUseCase)
        try{
            const {got, status,users} = await this.userUseCase.getAllUsers()
            res.json({got, status,users})
        } catch(err){
            console.error(err)
            next(err)
        }
    }

    async insertUser(req,res,next){
        const {name,age,married} = req.body

        try{
            const {inserted,status,createdUser} = await this.userUseCase.insertUser({name,age,married})
            res.json({inserted,status,createdUser})
        } catch(err){
            console.error(err)
            next(err)
        }


    }  

    async deleteUser(req,res,next){
        const id = req.get('id')

        try {
            const {deleted,status}= await this.userUseCase.deleteUser({id})
            res.json({deleted,status})
        }catch(err){
            console.error(err)
            next(err)
        }
    }

    async getCommentByUser(req,res,next){
        const {id} = req.params
        console.log(id)

        try{
            const {got,status,comments} = await this.userUseCase.getCommentByUser({id})
            res.json({got,status,comments})
        } catch(err){
            console.error(err)
            next(err)
        }

    }
}

module.exports = UserController