const mongoose = require('mongoose');

const connect = async() => {
    if (process.env.NODE_ENV !== 'production'){
        mongoose.set('debug',true)
    }

    try{
        await mongoose.connect(
            `mongodb+srv://${process.env.MONGO_USERNAME}:${process.env.MONGO_PASSWORD}@cluster0.qk3re.mongodb.net/?retryWrites=true&w=majority`,
            {
                dbName:'nodejs',
                useNewUrlParser:true,
            }
        )
         console.log("들어옴")

        console.log('몽고디비 연결 성공');
    } catch (err){
        console.error("몽고디비 연결 에러", err);
    }
}

mongoose.connection.on('error', (error) => {
    console.error('connection erorr',error);
})
mongoose.connection.on('disconnected',() => {
    console.error('disconnected');;
    // connect();
})

module.exports = connect