const { Op } = require("sequelize");
const {Post, Hashtag} = require("../models")

exports.afterUploadImage = (req,res) => {
    console.log(req.file);
    res.json({url:`/img/${req.file.filename}`});
}

exports.uploadPost = async(req,res,next) => {
    try{
        const post = await Post.create({
            content:req.body.content,
            img:req.body.url,
            UserId:req.user.id
        })
        const hashtags = req.body.content.match(/#[^\s#]*/g);
        console.log("------",hashtags,"-------")
        if (hashtags){
            const result = await Promise.all(
                hashtags.map(tag => {
                    return Hashtag.findOrCreate({
                        where:{title:tag.slice(1).toLowerCase()},
                    })
                })
            )
            await post.addHashtags(result.map(r => r[0]))
        }
        res.redirect("/")
    }catch(error){
        console.error(error);
        next(error)
    }
}

exports.updatePost = async(req,res,next) => {
    try{    
        const post = await Post.findOne({where:{id:req.params.postid}})
        console.log("------------");
        const prevHashtags = post.content.match(/#[^\s#]*/g)
        const prevHashtagsWithoutShop = prevHashtags.map(str => str.slice(1))
        console.log("prevHashtagsWithoutShop",prevHashtagsWithoutShop)
        const prevHashTagIds = await Hashtag.findAll({
            attributes:['id'],
            where:{
            title:{[Op.in]:prevHashtagsWithoutShop}
        }})
        // console.log(prevHashTagIds);
        await post.removeHashtags(prevHashTagIds)
        console.log("------------");

        // const prevHashTags = await Hashtag.findAll({where:{
        //     title:{[Op.in]:}
        // }})
        // if (prevHashTags){
        //     await post.removeHashtags(prevHashTags.map(r => r))
        // }

        // 내용 수정
        const updateResult = await Post.update({
            content:req.body.content
        },{where:{id:req.params.postid}})

        const hashtags = req.body.content.match(/#[^\s#]*/g)
        // 수정된 내용을 기반으로 해시테그 추가
        if (hashtags) {
            const result = await Promise.all(
                hashtags.map(tag => {
                    return Hashtag.findOrCreate({where:{title:tag.slice(1).toLowerCase()}})
                })
            )
            console.log(result.map(r => r[0]))
            await post.addHashtags(result.map(r => r[0]))
        }

        res.send({updateResult})
        // res.redirect("/")
    } catch (error){
        console.error(error)
        next(error)
    }
}

exports.deletePost = async(req,res,next) => {
    try{
        const post = await Post.destroy({where:{id:req.params.postid}})
        res.send({post})
    }catch(error) {
        console.error(error)
        next(error)
    }
}