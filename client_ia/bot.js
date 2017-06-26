/**
 * Created by goinau_q on 23/06/17.
 */

const chalk = require('chalk');
const fs    = require('fs');
const path  = require("path");

module.exports = class Bot {
	constructor (behaviour) {
		this.inventory     = {};
		this.view          = {
			"up"   : [],
			"down" : [],
			"left" : [],
			"right": [],
		};
		this.direction     = "up";
		this.queue         = [];
		this.client        = {};
		this.behaviour     = {};
		this.flux          = "";
		this.team          = "";
		this.searchingFood = false;
		this.clientNum     = -1;
		this.mapSize       = {};
		this.lastCommand   = "";
		this.totalCommands = 0;
		this.goesUp        = 0;
		this.level         = 1;

		this.incantating = false;

		this.behaviour = JSON.parse(fs.readFileSync(path.join(__dirname, "behaviours", behaviour + ".json"), 'utf8'));

		console.log(`Loading bot <${chalk.blue(this.behaviour.name)}> [${chalk.green(this.behaviour.description)}]`);
	}

	getState () {
		let obj = {
			"inventory"    : this.inventory,
			"view"         : this.view,
			"direction"    : this.direction,
			"queue"        : this.queue,
			"flux"         : this.flux,
			"team"         : this.team,
			"searchingFood": this.searchingFood,
			"clientNum"    : this.clientNum,
			"mapSize"      : this.mapSize,
			"lastCommand"  : this.lastCommand,
			"totalCommands": this.totalCommands,
			"goesUp"       : this.goesUp,
			"level"        : this.level,
			"incantating"  : this.incantating,
			"behaviour"    : this.behaviour,
		};
		return (obj);
	}

	send (cmd) {
		if (this.queue.length >= 10) {
			console.log(chalk.red("Sorry, no more than 10 commands in the queue"));
			return false;
		}

		this.queue.push(cmd.split(/(\\n)| /g)[0]);
		this.totalCommands++;

		this.client.write(cmd + "\n", () => {
			console.log(chalk.blue("[Sending] " + cmd));
			//this.output(this.queue);
		});
	}

	onLook () {
		let datas = this.flux.replace('\n', '').replace(/[\[\]]/g, '').split(',').map((x) => {
			return x.trim();
		});

		// Format datas
		datas.forEach((item, i) => {
			let a    = item.split(' ');
			datas[i] = {
				"items" : a,
				"length": a.length,
				"case"  : i
			};
		});

		/* // Sort datas
		 datas.sort((a, b) => {
		 return (b.length - a.length);
		 });*/

		// Remove players
		datas.forEach((item, i) => {
			item.items.forEach((x, xi) => {
				if (x === "player") {
					datas[i].items.splice(xi, 1);
				}
			});
		});

		//this.view[this.direction] = datas;
		this.view["here"] = datas;

		if (datas[0].items && datas[0].items.length !== 0)
			this.send("Take " + datas[0].items[0]);
		else
			this.send("Forward");
	}

	onTake () {
		if (this.msg === "ok")
			this.send("Look");
	}

	onForward () {
		if (this.msg === "ok") {
			this.send("Look");
			this.goesUp++;
		}
	}

	onRight () {
		if (this.msg === "ok")
			this.send("Forward");
	}

	onIncantation () {
		this.output("Incantation done");
		this.output("Elevation message : " + this.msg);
	}

	onTeam () {
		let a       = {};
		let split   = this.msg.split(/[\\n\s]/g);
		a.remaining = split[0];
		a.w         = split[1];
		a.h         = split[2];

		this.send("Look");
	}

	onInventory () {
		let inventory = this.msg.replace('\n', '').replace(/[\[\]]/g, '').split(',').map((x) => {
			return x.trim()
		});

		let obj = {};

		inventory.forEach((x) => {
			let a = x.split(' ');

			obj[a[0]] = a[1] * 1; //convert to number
		});

		// ---

		this.inventory = obj;

		if (this.inventory["linemate"] >= 1) {
			console.log("Player can rise to level 2 !");
			this.startIncantation();
		}
	}

	/**
	 * Output any types of data
	 * @param data
	 */
	output (data) {
		if (data === null)
			console.log(chalk.mangenta("(null)"));
		else if (data === undefined)
			console.log(chalk.mangenta('(undefined)'));
		else if (typeof data === 'object')
			console.log(chalk.magenta(JSON.stringify(data, null, '\t')));
		else
			console.log(chalk.magenta(data));
	}

	startIncantation () {
		this.send("Set linemate");
		this.send("Incantation");
	}
};