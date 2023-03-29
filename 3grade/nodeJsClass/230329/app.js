const express = require("express")

const app = express()
app.set('port',process.env.PORT || 3000)

app.get('/',(req,res) => {
    res.send("Hello Express")
})

app.listen(3000,() => {
    console.log("3000번 포트에서 대기중")
})