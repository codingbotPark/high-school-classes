const express = require('express')
const mysql = require('mysql2')

const pool = mysql.createPool({
    host:'mysql',
    user:"root",
    password:"password",
    database:'word',
    port:'3306'
})


const app = express()

app.get("/students",(req,res) => {
    pool.getConnection((err,connection) => {
        if (err) throw err;

        connection.query("SELECT * from students",(error,rows,fields) => {
            if (error) throw error
            console.log("User info is : ",rows);
            res.send(rows)
        })

        connection.release();
    })
})
app.get('/',(req,res) => {
    res.send("hi")
})
app.listen("5001",() => {
    console.log("5001listening")
})