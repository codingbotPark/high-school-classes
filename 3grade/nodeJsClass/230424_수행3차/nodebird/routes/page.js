const express = require('express');
const { renderProfile, renderJoin, renderMain } = require('../controllers/page');
const { isLoggedIn, isNotLoggedIn } = require('../middlewares');

const router = express.Router();

// 미들웨어, 초기화해준다
router.use((req, res, next) => {
  res.locals.user = req.user;
  res.locals.followerCount = 0;
  res.locals.followingCount = 0;
  res.locals.followingIdList = [];
  next();
});

router.get('/profile', isLoggedIn,renderProfile);

router.get('/join',isNotLoggedIn, renderJoin);

router.get('/', renderMain);

module.exports = router;