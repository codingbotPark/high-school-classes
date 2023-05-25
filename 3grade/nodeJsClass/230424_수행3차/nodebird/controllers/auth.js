const bcrypt = require('bcrypt')
const passport = require('passport')
const User = require('../models/user')

exports.join = async(req,res,next) => {
    const {email,nick,password} = req.body;
    try{
        const exUser = await User.findOne({where:{email}})
        if (exUser){
            return res.redirect('/join?error-exist');
        }
        const hash = await bcrypt.hash(password,12);
        await User.create({
            email,nick,password:hash
        })
        return res.redirect('/')
    } catch(err){
        console.error(err)
        return next(err)
    }
}

exports.login = (req,res,next) => {
    console.log(req.body.email, req.body.password)
    passport.authenticate('local',(authError,user,info) => {
        console.log(authError,user,info)
        if (authError){
            console.error(authError);
            return next(authError)
        }
        if(!user){
            return res.redirect(`/?loginError=${info.message}`);
        }

        return req.login(user,(loginError) => {
            if(loginError){
                console.error(loginError);
                return next(loginError);
            }
            return res.redirect('/');
        });
    })(req, res, next);
}

exports.changePassword = async (req,res,next) => {
    const pw = req.body.password

    console.log("pw",pw)

    const password = await bcrypt.hash(pw,12)
    const result = await User.update({
        password
    },{where:{id:req.user.id}})

    res.send("success")
    // return res.redirect('/')
}

exports.logout = (req, res) => {
    req.logout(() => {
      res.redirect('/');
    });
  };