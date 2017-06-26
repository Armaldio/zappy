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

const net    = require('net');
const client = new net.Socket();
const fs     = require("fs");
const path   = require('path');
const chalk  = require('chalk');

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

console.log("Browser : ", yargs.browser);
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


let bot    = new Bot(yargs.behaviour);
bot.team   = yargs.name;
bot.client = client;

bot.client.connect(yargs.port, yargs.machine, () => {
	console.log('Client connected');
});

bot.client.on('data', (data) => {
	bot.flux += data;

	if (data[data.length - 1] === '\n') {

		bot.flux = bot.flux.toLowerCase();

		let msgs = bot.flux.split("\n").filter(v => v !== '');

		msgs.forEach((msg) => {
			bot.msg = msg;

			if (clients.length > 0) {
				clients[0].emit('message', bot.getState());
			}

			if (bot.msg === "welcome")
				bot.send(bot.team);
			else if (bot.msg === "dead")
				console.log(chalk.red("You are dead"));
			else {

				//When no errors if command is XXX

				bot.lastCommand = bot.queue[0];
				if (bot.queue[0] !== bot.team &&
					bot.queue[0] !== "Incantation") {
					bot.lastCommand = bot.queue.shift();
				}

				console.log(chalk.green("[Receiving] " + bot.lastCommand + ' : ' + JSON.stringify(msg)));
				//bot.output(bot.queue);

				if (bot.totalCommands % 5 === 0) {
					bot.send("Inventory");
				}

				if (bot.goesUp === bot.mapSize.y) {
					bot.send("Right");
					bot.send("Forward");
					bot.send("Left");
					bot.goesUp = 0;
				}

				switch (bot.lastCommand) {

					case "Look":
						bot.onLook();
						break;

					case "Take":
						bot.onTake();
						break;

					case "Forward":
						bot.onForward();
						break;

					case "Right":
						bot.onRight();
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
						if (bot.msg !== "ko") {
							if (!bot.incantating)
								bot.incantating = true;
							else {
								bot.level = bot.msg.replace("current level: ", "") * 1;
								bot.queue.shift();
							}
						}
						break;

					case "Inventory":
						bot.onInventory();
						break;

					default:
						console.log(chalk.red(`Command [${bot.lastCommand}] not supported by client`));
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
