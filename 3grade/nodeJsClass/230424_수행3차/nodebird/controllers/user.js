const User = require("../models/user");

exports.follow = async (req, res, next) => {
  try {
    const user = await User.findOne({ where: { id: req.user.id } });
    if (user) {
      // req.user.id가 followerId, req.params.id가 followingId
      console.log("-----------")
      console.log("에드팔로잉");
      console.log(user.addFollowing);
      console.log("-----------")
      await user.addFollowing(parseInt(req.params.id, 10));
      res.send("success");
    } else {
      res.status(404).send("no user");
    }
  } catch (error) {
    console.error(error);
    next(error);
  }
};

exports.unFollow = async(req,res,next) => {
  try{
    const user = await User.findOne({where:{id:req.params.id}})
    if (user){
      await user.destroyFollowing(parseInt(req.params.id,10));
      console.log(user);
      res.send("success")
    } else {
      res.status(404).send("no user");
    }
  }catch(error){
    console.error(error);
    next(error)
  }
}