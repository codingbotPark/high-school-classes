const express = require('express')
const passport = require('passport')

const {isLoggedIn, isNotLoggedIn} = require("../middlewares")
const {join,login,logout,changePassword,changeNickname} = require('../controllers/auth')

const router = express.Router();

router.post('/join',isNotLoggedIn,join);

router.post('/login',isNotLoggedIn,login);

router.get('/logout',isLoggedIn,logout);

router.patch('/changepw',isLoggedIn,changePassword)

router.patch('/changenick',isLoggedIn,changeNickname)

router.get('/kakao',passport.authenticate('kakao'));

router.get('/kakao/callback',passport.authenticate('kakao',{
    failureRedirect:'/?loginError=카카오로그인 실패',
}), (req,res) => {
    res.redirect('/')
})

module.exports = router