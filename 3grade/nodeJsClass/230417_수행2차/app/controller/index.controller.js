class PageController {
    constructor(){}

    async getMainPage(req,res,next){
        try {
            const {got, status, users} = await this.userUseCase.getAllUsers()
            console.log(users)
            res.render('sequelize',{users})
        } catch(err){
            console.error(err);
            next(err)
        }
    }
}

module.exports = PageController