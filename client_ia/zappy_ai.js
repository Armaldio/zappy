/**
 * Created by goinau_q on 21/06/17.
 */

/* const stones = [
 "linemate",
 "deraumere",
 "sibur",
 "mendiane",
 "phiras",
 "thystame"
 ]; */

const clients = [];

/* Sockets */
const net = require('net');

const client = new net.Socket();

/* File system */
const fs   = require('fs');
const path = require('path');

/* Colors */
const chalk = require('chalk');

/* Custom modules */
const Bot = require('./bot.js');

client.setEncoding('utf8');

/**
 * Command line arguments
 * @type {any}
 */
const yargs = require('yargs').options({
	behaviour: {
		alias   : 'b',
		describe: 'Specify an IA behaviour',
		default : 'default'
	},
	port     : {
		alias   : 'p',
		describe: 'port is the port number'
	},
	name     : {
		alias   : 'n',
		describe: 'name is the name of the team'
	},
	machine  : {
		alias   : 'h',
		describe: 'machine is the name of the machine; localhost by default',
		default : 'localhost'
	},
	browser  : {
		alias   : 'b',
		describe: 'specify the port for communication to the browser'
	}
}).demandOption(['port', 'name'], 'Please provide both port and name arguments')
							  .help().argv;

// TODO Check errors !

/**
 * Communication with client ---------------------------------------------------
 */

if (yargs.browser !== 'default') {
	const app = require('http').createServer(handler);
	const io  = require('socket.io')(app);

	app.listen(yargs.browser);

	function handler (req, res) {
		fs.readFile(__dirname + '/index.html',
			(err, data) => {
				if (err) {
					res.writeHead(500);
					return res.end('Error loading index.html');
				}

				res.writeHead(200);
				res.end(data);
			});
	}

	io.on('connection', socket => {
		console.log('New client connected');
		clients.push(socket);

		socket.on('msg', msg => {
			console.log('New message from client : ' + msg);
		});
	});
}

/**
 * End --------------------------------------------------------------------
 */

/* New bot */
const bot  = new Bot(yargs.behaviour);
bot.team   = yargs.name;
bot.client = client;

bot.client.connect(yargs.port, yargs.machine, () => {
	console.log('Client connected');
});

bot.client.on('data', data => {
	// When data received, add it to the flux
	bot.flux += data;

	// If flux is completed (\n), proceed to commands
	if (data[data.length - 1] === '\n') {
		// Make all lowercase so we can write all in lowercase
		bot.flux = bot.flux.toLowerCase();

		// Sometimes we receive multiple commands in one request (aka xxx\nxxx\n) so
		// we split \n and remove empty elements
		const msgs = bot.flux.split('\n').filter(v => v !== '');

		// So for each command we receive
		msgs.forEach(msg => {
			bot.msg = msg;

			// If browser clients are connected, send it the state of the bot
			if (clients.length > 0) {
				clients[0].emit('message', bot.getState());
			}

			// Wild messages appear
			// TODO refactor
			if (bot.msg === 'welcome') {
				bot.send(bot.team);
			} else if (bot.msg.startsWith('message')) {
				let broadcast = bot.msg.replace("message", "");
				console.log("Broadcast : " + broadcast);
				let split     = broadcast.split(',');

				broadcast  = split[1].trim();
				let tileID = split[0];


				broadcast = broadcast.split(' ');

				console.log(chalk.yellow(`Received broadcast : [${broadcast[0]}] [${broadcast[1]}] : ${tileID}`));
				if (broadcast[0] === "waiting")
					bot.aPlayerIsWaiting = broadcast[1] * 1; //To Number
				else if (broadcast[0] === "stopped")
					bot.aPlayerIsWaiting = -1;

			} else if (bot.msg === 'ko') {
				console.log('KO Queue : ' + bot.queue[0]);
				if (bot.queue[0] === 'Incantation') {
					if (bot.incantationStep === 0) {
						//bot.queue.shift();
						bot.incantationStep = 1;
						//bot.send("Look");
					} else if (bot.incantationStep === 1) {
						bot.queue.shift();
						bot.incantationStep = 0;
						bot.send("Look");
					}
				} else {
					bot.lastCommand = bot.queue.shift();
					bot.output(bot.lastCommand + ' : ko');
					bot.goRandomDir();
					console.log("Next command : " + bot.queue[0]);
				}
			} else if (bot.msg === 'dead') {
				bot.dead = true;
				console.log(chalk.red('You are dead'));
			} else if (bot.msg === 'elevation underway') {
				bot.incantating = true;
				bot.output('Incantation started');
				bot.output('[Elevation underway] Going to level ' + (bot.level + 1));
			} else if (bot.msg.match(/current level: (.*)/g)) {
				bot.output('[Curent level]');
				bot.level = Number(bot.msg.replace('current level: ', ''));
				bot.queue.shift();
				bot.incantating = false;
				bot.onIncantation();
			} else {
				// When no errors if command is XXX

				bot.lastCommand = bot.queue[0];
				if (bot.queue[0] !== bot.team) {
					bot.lastCommand = bot.queue.shift();
				}

				console.log(chalk.green(bot.getDate() + ' [Receiving] ' + bot.lastCommand + ' : ' + JSON.stringify(msg)));
				// Bot.output(bot.queue);

				switch (bot.lastCommand) {

					case 'Look':
						bot.onLook();
						break;

					case 'Broadcast':
						console.log(bot.msg);
						break;

					case 'Take':
						bot.onTake();
						break;

					case 'Fork':
						bot.output('A new player will be available soon');
						break;

					case 'Forward':
						bot.onForward();
						break;

					case 'Right':
						bot.onRight();
						break;

					case 'Left':
						bot.onLeft();
						break;

					case 'Set':
						break;

					case bot.team:
						if (bot.clientNum === -1) {
							bot.clientNum = Number(bot.flux);
						} else {
							const size    = bot.flux.split(' ');
							bot.mapSize.x = Number(size[0]);
							bot.mapSize.y = Number(size[1]);
							bot.queue.shift();
							bot.onTeam();
						}
						break;

					case 'Incantation':
						break;

					case 'Inventory':
						bot.onInventory();
						break;

					default:
						console.log(chalk.red(`Command [${bot.lastCommand}] not supported by client`));
				}

				// Change direction
				if (bot.goesUp === bot.mapSize.y) {
					bot.turning = true;
					bot.send('Right');
					bot.send('Forward');
					bot.send('Left');
					bot.goesUp = 0;
				}
			}
		});

		bot.flux = '';
	}
});

bot.client.on('close', () => {
	console.log(chalk.red('Connection closed'));
});

bot.client.on('end', () => {
	console.log(chalk.red('Disconnected from server'));
});

bot.client.on('error', err => {
	console.log(chalk.red('Error : ', err.code));
});

/*const interval = setInterval(() => {
	if (bot.dead) {
		clearInterval(interval);
		return;
	}
	if (bot.inactivity > 3) {
		bot.send('Look');
		bot.inactivity = 0;
	}
	if (bot.queue.length === 0) {
		bot.inactivity++;
	} else {
		bot.inactivity = 0;
	}
}, 1000);*/
