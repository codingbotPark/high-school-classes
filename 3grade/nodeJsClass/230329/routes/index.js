const express = require('express')

const router = express.Router();

// router.get('/',(req,res,next) => {
//     res.send('Hello users')
// })
router.route('/')
.post((req,res,next) => {
    
})
.get((req,res,next) => {
    res.send("hello")

})
.put((req,res,next) => {})

module.exports = router;