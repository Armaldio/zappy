/**
 * Created by goinau_q on 23/06/17.
 */

const chalk = require('chalk');
const fs    = require('fs');
const path  = require("path");

module.exports = class Bot {
	constructor (behaviour) {
		this.inventory     = {};
		this.view          = [];
		this.queue         = [];
		this.client        = {};
		this.behaviour     = {};
		this.flux          = "";
		this.team          = "";
		this.searchingFood = false;
		this.clientNum     = -1;
		this.mapSize       = {};

		this.behaviour = JSON.parse(fs.readFileSync(path.join(__dirname, "behaviours", behaviour + ".json"), 'utf8'));

		console.log(`Loading bot <${chalk.blue(this.behaviour.name)}> [${chalk.green(this.behaviour.description)}]`);
	}

	send (cmd) {
		if (this.queue.length >= 10) {
			console.log(chalk.red("Sorry, no more than 10 commands in the queue"));
			return false;
		}

		this.queue.push(cmd.split(/(\\n)| /g)[0]);

		this.client.write(cmd + "\n", () => {
			console.log(chalk.blue(">> " + cmd));
			this.output(this.queue);
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

		this.view = datas;

		if (datas[0].items && datas[0].items.length !== 0)
			this.send("Take " + datas[0].items[0]);
		else
			this.send("Forward");
	}

	onTake () {
		if (this.flux === "ok")
			this.send("Look");
	}

	onForward () {
		if (this.flux === "ok")
			this.send("Look");
	}

	onTeam () {
		let a       = {};
		let split   = this.flux.split(/[\\n\s]/g);
		a.remaining = split[0];
		a.w         = split[1];
		a.h         = split[2];

		this.send("Inventory");
		this.send("Look");
	}

	onInventory () {
		let inventory = this.flux.replace('\n', '').replace(/[\[\]]/g, '').split(',').map((x) => {
			return x.trim()
		});

		let obj = {};

		inventory.forEach((x) => {
			let a = x.split(' ');

			obj[a[0]] = a[1] * 1; //convert to number
		});

		// ---

		this.inventory = obj;

		if (this.inventory.food < 10)
			this.searchFood();

		this.output("Food : " + this.inventory.food);

		this.send('Forward');
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

	searchFood () {
		console.log(chalk.magenta("** Started searching for food **"));
		this.searchingFood = true;
		this.send("Look");
		this.send("Right");
		this.send("Look");
		this.send("Right");
		this.send("Look");
		this.send("Right");
		this.send("Look");
		this.searchingFood = false;
		console.log(chalk.magenta("** Stopped searching for food **"));
	}
};