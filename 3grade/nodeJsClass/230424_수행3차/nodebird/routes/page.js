const express = require('express');
const { renderProfile, renderJoin, renderMain,renderHashtag } = require('../controllers/page');
const { isLoggedIn, isNotLoggedIn } = require('../middlewares');

const router = express.Router();

// 미들웨어, 초기화해준다
router.use((req, res, next) => {
  res.locals.user = req.user;
  res.locals.followerCount = req.user ? req.user.Followers.length : 0;
  res.locals.followingCount = req.user ? req.user.Followings.length : 0;
  res.locals.followingIdList = req.user ? req.user.Followings.map((f) => f.id) : [];

  next();
});

router.get('/profile', isLoggedIn,renderProfile);

router.get('/join',isNotLoggedIn, renderJoin);

router.get('/', renderMain);

router.get('/hashtag',renderHashtag)

module.exports = router;