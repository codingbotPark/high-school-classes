exports.isLoggedIn = (req,res,next) => {
    if (req.isAuthenticated()){
        next();
    } else {
        // res.status(403).redirect(`/`)
        res.status(403).send("로그인 필요");
        // res.status(403).write("<script>window.location=\"/\";alert('need login')</script>");
    }
}

exports.isNotLoggedIn = (req,res,next) => {
    if(!req.isAuthenticated()) {
        next()
    } else{
        const message = encodeURIComponent("로그인한 상태입니다")
        res.redirect(`/?error=${message}`)
    }
}
