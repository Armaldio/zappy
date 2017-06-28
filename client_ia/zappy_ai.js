/**
 * Created by goinau_q on 21/06/17.
 */

const stones = [
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame"
];

let clients = [];

/* Sockets */
const net    = require('net');
const client = new net.Socket();

/* File system */
const fs   = require("fs");
const path = require('path');

/* Colors */
const chalk = require('chalk');

/* Custom modules */
const Bot = require("./bot.js");

client.setEncoding('utf8');

/**
 * Command line arguments
 * @type {any}
 */
const yargs = require('yargs').options({
	'behaviour': {
		alias   : 'b',
		describe: 'Specify an IA behaviour',
		default : 'default'
	},
	'port'     : {
		alias   : 'p',
		describe: 'port is the port number',
	},
	'name'     : {
		alias   : 'n',
		describe: 'name is the name of the team',
	},
	'machine'  : {
		alias   : 'h',
		describe: 'machine is the name of the machine; localhost by default',
		default : 'localhost'
	},
	'browser'  : {
		alias   : 'b',
		describe: 'specify the port for communication to the browser'
	}
}).demandOption(['port', 'name'], 'Please provide both port and name arguments')
							  .help().argv;

//TODO Check errors !

/**
 * Communication with client ---------------------------------------------------
 */

if (yargs.browser !== "default") {
	const app = require('http').createServer(handler);
	const io  = require('socket.io')(app);

	app.listen(yargs.browser);

	function handler (req, res) {
		fs.readFile(__dirname + '/index.html',
			function (err, data) {
				if (err) {
					res.writeHead(500);
					return res.end('Error loading index.html');
				}

				res.writeHead(200);
				res.end(data);
			});
	}

	io.on('connection', function (socket) {
		console.log("New client connected");
		clients.push(socket);

		socket.on('msg', function (msg) {
			console.log("New message from client : " + msg);
		});
	});
}

/**
 * End --------------------------------------------------------------------
 */

/* New bot */
let bot    = new Bot(yargs.behaviour);
bot.team   = yargs.name;
bot.client = client;

bot.client.connect(yargs.port, yargs.machine, () => {
	console.log('Client connected');
});

bot.client.on('data', (data) => {
	// When data received, add it to the flux
	bot.flux += data;

	// if flux is completed (\n), proceed to commands
	if (data[data.length - 1] === '\n') {

		// make all lowercase so we can write all in lowercase
		bot.flux = bot.flux.toLowerCase();

		// sometimes we receive multiple commands in one request (aka xxx\nxxx\n) so
		// we split \n and remove empty elements
		let msgs = bot.flux.split("\n").filter(v => v !== '');

		// so for each command we receive
		msgs.forEach((msg) => {
			bot.msg = msg;

			// if browser clients are connected, send it the state of the bot
			if (clients.length > 0) {
				clients[0].emit('message', bot.getState());
			}

			//Wild messages appear
			// TODO refactor
			if (bot.msg === "welcome")
				bot.send(bot.team);
			else if (bot.msg === "ko")
				bot.send("Look");
			else if (bot.msg === "dead")
				console.log(chalk.red("You are dead"));
			else if (bot.msg === "elevation underway") {
				bot.incantating = true;
				bot.output("Incantation started");
			} else if (bot.msg.match(/current level: (.*)/g)) {
				bot.level = bot.msg.replace("current level: ", "") * 1;
				bot.queue.shift();
				bot.incantating = false;
				bot.onIncantation();
			} else {

				//When no errors if command is XXX

				bot.lastCommand = bot.queue[0];
				if (bot.queue[0] !== bot.team) {
					bot.lastCommand = bot.queue.shift();
				}

				console.log(chalk.green("[Receiving] " + bot.lastCommand + ' : ' + JSON.stringify(msg)));
				//bot.output(bot.queue);

				switch (bot.lastCommand) {

					case "Look":
						bot.onLook();
						break;

					case "Take":
						bot.onTake();
						break;

					case "Fork":
						bot.output("A new player will be available soon");
						break;

					case "Forward":
						bot.onForward();
						break;

					case "Right":
						bot.onRight();
						break;

					case "Left":
						bot.onLeft();
						break;

					case "Set":
						break;

					case bot.team:
						if (bot.clientNum === -1)
							bot.clientNum = bot.flux * 1;
						else {
							let size      = bot.flux.split(" ");
							bot.mapSize.x = size[0] * 1;
							bot.mapSize.y = size[1] * 1;
							bot.queue.shift();
							bot.onTeam();
						}
						break;

					case "Incantation":
						break;

					case "Inventory":
						bot.onInventory();
						break;

					default:
						console.log(chalk.red(`Command [${bot.lastCommand}] not supported by client`));
				}

				// Change direction
				if (bot.goesUp === bot.mapSize.y) {
					bot.turning = true;
					bot.send("Right");
					bot.send("Forward");
					bot.send("Left");
					bot.goesUp = 0;
				}
			}
		});

		bot.flux = "";
	}
});

bot.client.on('close', () => {
	console.log(chalk.red('Connection closed'));
});

bot.client.on('end', function () {
	console.log(chalk.red('Disconnected from server'));
});

bot.client.on('error', (err) => {
	console.log(chalk.red("Error : ", err.code));
});

setInterval(() => {
	if (bot.inactivity > 3) {
		bot.send("Look");
		bot.inactivity = 0;
	}
	if (bot.queue.length === 0)
		bot.inactivity++;
	else
		bot.inactivity = 0;

}, 1000);
