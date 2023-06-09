const express = require("express")
const multer = require("multer")
const path = require("path")
const fs = require("fs")

const {afterUploadImage, uploadPost, updatePost,deletePost} = require("../controllers/post");
const {isLoggedIn} = require("../middlewares")

const router = express.Router()

router.patch('/:postid',isLoggedIn, updatePost)
router.delete('/:postid',isLoggedIn, deletePost)

try{
    fs.readdirSync("uploads");
}catch (error){
    console.error("uploads폴더가 없어 uploads폴더를 생성합니다")
    fs.mkdirSync("uploads")
}

const upload = multer({
    storage: multer.diskStorage({
        destination(req,file,cb){
            cb(null,'uploads/')
        },
        filename(req,file,cb){
            const ext = path.extname(file.originalname);
            cb(null, path.basename(file.originalname, ext) + Date.now() + ext);
        },
    }),
    limits:{fileSize:5 * 1024 * 1024}
})

router.post('/img',isLoggedIn, upload.single('img'),afterUploadImage);

const upload2 = multer();
router.post('/',isLoggedIn,upload2.none(), uploadPost)


module.exports = router;