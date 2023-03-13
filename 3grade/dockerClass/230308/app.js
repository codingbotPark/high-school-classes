var http = require('http')
var content = function(req,res){
    res.end("welcom to dgsw server!" + "\n")
    res.writeHead(200)
}
var server = http.createServer(content)
server.listen(8000)
