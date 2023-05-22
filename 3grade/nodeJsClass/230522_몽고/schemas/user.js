const mongoose = require("mongoose");

const {Schema} = mongoose;
const userSchema = new Schema({
    name:{
        type:String,
        required:true,
        unique:true
    },
    age:{
        type:Number,
        requird:true
    },
    married:{
        type:Boolean,
        requird:true
    },
    comment:String,
    createdAt:{
        type:Date,
        default:Date.now,
    },
})

module.exports = mongoose.model('User',userSchema)