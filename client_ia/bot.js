/**
 * Created by goinau_q on 23/06/17.
 */

const fs    = require('fs');
const path  = require('path');
const chalk = require('chalk');

module.exports = class Bot {
	constructor (behaviour) {
		this.inventory     = {};
		this.view          = {
			up   : [],
			down : [],
			left : [],
			right: []
		};
		this.direction     = 'up';
		this.queue         = [];
		this.client        = {};
		this.behaviour     = {};
		this.flux          = '';
		this.team          = '';
		this.searchingFood = false;
		this.clientNum     = -1;
		this.mapSize       = {};
		this.lastCommand   = '';
		this.dead          = false;
		this.totalCommands = 0;
		this.goesUp        = 0;
		this.level         = 1;
		this.turning       = false;
		this.lv            = {
			2: {
				player  : 1,
				linemate: 1
			},
			3: {
				player   : 2,
				linemate : 1,
				deraumere: 1,
				sibur    : 1
			},
			4: {
				player  : 2,
				linemate: 2,
				phiras  : 2,
				sibur   : 1
			},
			5: {
				player   : 4,
				linemate : 1,
				deraumere: 1,
				phiras   : 1,
				sibur    : 2
			},
			6: {
				player   : 4,
				linemate : 1,
				deraumere: 2,
				phiras   : 0,
				sibur    : 1,
				mendiane : 3
			},
			7: {
				player   : 6,
				linemate : 1,
				deraumere: 2,
				sibur    : 3,
				mendiane : 0,
				phiras   : 1
			},
			8: {
				player   : 6,
				linemate : 2,
				deraumere: 2,
				sibur    : 2,
				mendiane : 2,
				phiras   : 2,
				thystame : 1
			}
		};
		this.inactivity    = 0;

		this.incantationStep = 0;
		this.incantating     = false;

		this.behaviour = JSON.parse(fs.readFileSync(path.join(__dirname, 'behaviours', behaviour + '.json'), 'utf8'));

		console.log(`Loading bot <${chalk.blue(this.behaviour.name)}> [${chalk.green(this.behaviour.description)}]`);
	}

	/**
	 * Get full state of the bot
	 * @returns {{inventory: ({}|*), view: ({up: Array, down: Array, left: Array, right: Array}|*), direction: string, queue: Array, flux: string, team: string, searchingFood: boolean, clientNum: (number|*), mapSize: ({}|*), lastCommand: string, totalCommands: number, goesUp: number, level: number, incantating: boolean, behaviour: (*|{})}}
	 */
	getState () {
		const obj = {
			inventory    : this.inventory,
			view         : this.view,
			direction    : this.direction,
			queue        : this.queue,
			flux         : this.flux,
			team         : this.team,
			searchingFood: this.searchingFood,
			clientNum    : this.clientNum,
			mapSize      : this.mapSize,
			lastCommand  : this.lastCommand,
			totalCommands: this.totalCommands,
			goesUp       : this.goesUp,
			level        : this.level,
			incantating  : this.incantating,
			behaviour    : this.behaviour
		};
		return (obj);
	}

	/**
	 * Send a command to the server
	 * @param cmd
	 * @returns {boolean}
	 */
	send (cmd) {
		// TODO send ony when last command is received
		if (this.queue.length >= 10) {
			console.log(chalk.red('Sorry, no more than 10 commands in the queue'));
			return false;
		}

		this.client.write(cmd + '\n', () => {
			if (cmd === undefined) {
				console.log('COMMAND IS UNDEFINED !!!');
			} else {
				console.log(chalk.blue('[Sending] ' + cmd));
				this.queue.push(cmd.split(/(\\n)| /g)[0]);
				this.output(this.queue);
				this.totalCommands++;
			}
		});
	}

	/**
	 * Triggered when look is successful
	 */
	onLook () {
		const datas = this.flux.replace('\n', '').replace(/[\[\]]/g, '').split(',').map(x => {
			return x.trim();
		});

		// Format datas
		datas.forEach((item, i) => {
			const onFloor = item.split(' ').filter(el => {
				return (el !== 'player');
			});

			const players = item.split(' ').filter(el => {
				return (el === 'player');
			});

			datas[i] = {
				items  : onFloor,
				length : onFloor.length,
				players: players.length,
				case   : i
			};
		});

		this.view.here = datas[0];
		this.view.up   = datas[2];

		if (this.view.here.items && this.view.here.items.length !== 0) {
			if (!this.willMove() && this.view.here.players <= 1) {
				this.send('Take ' + this.view.here.items[0]);
			} else {
				this.goRandomDir();
			}
		} else {
			this.send('Inventory');
		}
	}

	onTake () {
		if (this.msg === 'ok') {
			this.send('Look');
		}
	}

	onForward () {
		if (this.msg === 'ok' && !this.turning) {
			this.send('Look');
			this.goesUp++;
		}
	}

	onRight () {
		/* If (this.msg === "ok")
		 this.send("Forward"); */
	}

	onLeft () {
		if (this.turning) {
			this.turning = false;
		}
		/*	If (this.msg === "ok")
		 this.send("Forward"); */
	}

	onIncantation () {
		this.output('Incantation done, now level ' + this.level);
		this.send('Fork');
		this.send('Look');
	}

	onTeam () {
		const a     = {};
		const split = this.msg.split(/[\\n\s]/g);
		a.remaining = split[0];
		a.w         = split[1];
		a.h         = split[2];

		this.send('Look');
	}

	onInventory () {
		const inventory = this.msg.replace('\n', '').replace(/[\[\]]/g, '').split(',').map(x => {
			return x.trim();
		});

		const obj = {};

		inventory.forEach(x => {
			const a = x.split(' ');

			obj[a[0]] = Number(a[1]); // Convert to number
		});

		// ---

		this.inventory = obj;

		/*
		 Elevation nb of players linemate deraumere sibur mendiane phiras thystame
		 1->2      1             1        0         0     0        0      0
		 2->3      2             1        1         1     0        0      0
		 3->4      2             2        0         1     0        2      0
		 4->5      4             1        1         2     0        1      0
		 5->6      4             1        2         1     3        0      0
		 6->7      6             1        2         3     0        1      0
		 7->8      6             2        2         2     2        2      1
		 */

		// The case is empty
		if (this.view.here.length === 0) {
			if (this.canIncantation()) {
				this.startIncantation();
			} else {
				this.send('Forward');
			}
		} else {
			this.send('Forward');
		}
	}

	canIncantation () {
		let bool = true;
		Object.keys(this.lv[this.level + 1]).forEach(key => {
			// If (requirement to pass level) is in (inventory)

			if (key === 'player') {
				if (this.view.here.players !== this.lv[this.level + 1][key]) {
					bool = false;
					console.log('Not enough players : ' + this.view.here.players + ' vs ' + this.lv[this.level + 1][key]);
				}
			} else if (this.inventory[key] === undefined ||
					   this.inventory[key] < this.lv[this.level + 1][key]) {
				// Console.log("Not enough ressources : (" + key + ") " + this.inventory[key] + " vs " + this.lv[this.level + 1][key]);
				bool = false;
			}
		});

		return (bool);
	}

	/**
	 * Output any types of data
	 * @param data
	 */
	output (data) {
		if (data === null) {
			console.log(chalk.mangenta('(null)'));
		} else if (data === undefined) {
			console.log(chalk.mangenta('(undefined)'));
		} else if (typeof data === 'object') {
			console.log(chalk.magenta(JSON.stringify(data, null, '\t')));
		} else {
			console.log(chalk.magenta(data));
		}
	}

	startIncantation () {
		this.output('Starting incantation');

		Object.keys(this.lv[this.level + 1]).forEach(key => {
			/* Console.log("Key : " + key);
			 console.log(this.lv[this.level + 1][key]); */

			// Set each needed object on the ground
			for (let i = 0; i < this.lv[this.level + 1][key]; i++) {
				if (key !== 'player') {
					this.send('Set ' + key);
				}
			}
		});

		this.send('Incantation');
	}

	getRandomInt (min, max) {
		return Math.floor(Math.random() * (max - min + 1)) + min;
	}

	goRandomDir () {
		const r   = this.getRandomInt(0, 1);
		const c   = this.getRandomInt(1, 3);
		const dir = (r === 1 ? 'Left' : 'Right');

		for (let i = 0; i < c; i++) {
			this.send(dir);
		}
	}

	willMove () {
		let move = false;
		this.queue.forEach(cmd => {
			if (cmd === 'Left' || cmd === 'Right' || cmd === 'Forward') {
				move = true;
			}
		});
		return (move);
	}
};
