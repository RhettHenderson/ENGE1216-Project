//The default http and filesystem includes
var http = require('http');
var fs = require('fs');
//SerialPort module is used to listen to the COM port
var SerialPort = require('serialport');


//Our index.html file is being read
var index = fs.readFileSync('index.html');

//This is how we read data
const parsers = SerialPort.parsers;
const parser = new parsers.Readline({
	delimiter: '\r\n'
});

var port = new SerialPort('\\\\.\\COM5', { 
	baudRate: 9600, 
	databits: 8, 
	parity: 'none', 
	stopBits: 1, 
	flowControl: false });
	
port.pipe(parser);

var app = http.createServer(function(req, res) {
	res.writeHead(200, {'Content-Type': 'text/html'});
	res.end(index);
});

var io = require('socket.io').listen(app);

io.on('connection', (socket) => {
    console.log('Node.js is listening');
});

parser.on('data', function(data)
{
    console.log(data);
    
    io.emit('data', data);
});

app.listen(3000);
