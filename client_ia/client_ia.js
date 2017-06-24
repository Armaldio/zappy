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
	}
}).demandOption(['port', 'name'], 'Please provide both port and name arguments')
							  .help().argv;

//TODO Check errors !

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

		console.log(chalk.green("[RAW] " + JSON.stringify(bot.flux)));

		let msgs = bot.flux.split("\n").filter(v => v !== '');

		msgs.forEach((msg) => {
			bot.msg = msg;

			/*if (msg === "ko") {
			 console.log(chalk.red(`Command [${bot.queue[0]}] failed : ${msg}`));
			 bot.queue.shift();
			 }
			 else */
			if (bot.msg === "welcome")
				bot.send(yargs.name);
			else if (bot.msg === "dead")
				console.log(chalk.red("You are dead"));
			else {

				//When no errors if command is XXX

				bot.lastCommand = bot.queue[0];
				if (bot.queue[0] !== bot.team) {
					bot.lastCommand = bot.queue.shift();
				}

				console.log(chalk.green("[Receiving] " + bot.lastCommand + ' : ' + JSON.stringify(msg)));
				bot.output(bot.queue);

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

					case bot.team:
						if (bot.clientNum === -1)
							bot.clientNum = bot.flux * 1;
						else {
							let size      = bot.flux.split(" ");
							bot.mapSize.x = size[0];
							bot.mapSize.y = size[1];
							bot.queue.shift();
							bot.onTeam();
						}
						break;

					case "Inventory":
						bot.onInventory();
						break;

					default:
						console.log(chalk.red(`Command [${bot.queue[0]}] not supported by client`));
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
