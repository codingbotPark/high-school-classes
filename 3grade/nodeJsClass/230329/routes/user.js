const express = require('express')

const router = express.Router();



router.get('/',(req,res,next) => {
    res.send('Hello user')
})
router.get('/:id',(req,res,next) => {
    const query = req.query
    const id = req.params.id
    console.log(id)
    console.log(query)
    res.send('HELLO'+id)
})


module.exports = router;