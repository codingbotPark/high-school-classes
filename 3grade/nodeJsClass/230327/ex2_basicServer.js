const http = require('http')
const fs = require('fs').promises;

http.createServer(async (req,res) => {
    // res.writeHead(200,{'Content-type':'text/plain; charset=utf-8'})
    // res.write('<h1>Hello Node!</h1>');
    // res.write('<p>Hello Server!</p>');
    // res.end();

    try{
        const data = await fs.readFile('./server.html')
        res.writeHead(200,{'Content-type':'text/html; charset=utf-8'})
        res.end(data)
    } catch(err) {
        console.error(err);
        res.writeHead(500,{'Conatent-Type':'text/plain; charset=utf-8'});
        res.end(err.message)
    }
})
.listen(9000,() => {
    console.log('9000포트')
})