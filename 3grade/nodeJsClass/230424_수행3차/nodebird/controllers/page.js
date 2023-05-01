const {User,Post,Hashtag} = require("../models")

exports.renderProfile = (req, res) => {
    res.render('profile', { title: '내 정보 - NodeBird' });
  };
  
  exports.renderJoin = (req, res) => {
    res.render('join', { title: '회원가입 - NodeBird' });
  };
  
  exports.renderMain = (req, res, next) => {
    const twits = [];
    res.render('main', {
      title: 'NodeBird',
      twits,
    });
  };

  exports.renderMain = async (req, res, next) => {
    try {
      const posts = await Post.findAll({
        include: {
          model: User,
          attributes: ['id', 'nick'],
        },
        order: [['createdAt', 'DESC']],
      });
      res.render('main', {
        title: 'NodeBird',
        twits: posts,
      });
    } catch (err) {
      console.error(err);
      next(err);
    }
  }