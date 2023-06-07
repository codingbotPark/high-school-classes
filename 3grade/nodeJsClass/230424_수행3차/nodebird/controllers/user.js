const User = require("../models/user");
const { Op } = require("sequelize");

exports.follow = async (req, res, next) => {
  try {
    const user = await User.findOne({ where: { id: req.user.id } });
    if (user) {
      await user.addFollowing(parseInt(req.params.id, 10));
      res.send("success");
    } else {
      res.status(404).send("no user");
    }
  } catch (error) {
    // console.error(error);
    next(error);
  }
};

exports.unFollow = async(req,res,next) => {
  try{
    const user = await User.findOne({where:{id:req.user.id}});
    if (user){
      await user.removeFollowing(parseInt(req.params.id, 10));
      res.send("success")
    } else {
      res.status(404).send("no user")
    }


    // console.log(follow);
    // const result = follow.destroy({where:{
    //   [Op.and]:[
    //     {followingId:req.params.id},
    //     {followerId:req.params.myid}
    //   ]
    // }})
    // console.log("-------");
    // console.log(result);


  }catch(error){ 
    console.error(error);
    next(error)
  }
}