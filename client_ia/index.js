let socket = io('http://192.168.0.110:4244');

/*let data = {
 'inventory'    : {
 food     : 13,
 linemate : 0,
 deraumere: 0,
 sibur    : 1,
 mendiane : 1,
 phiras   : 0,
 thystame : 0
 },
 'view'         : {
 up   : [[], [], [], []],
 down : [],
 left : [],
 right: []
 },
 'direction'    : 'up',
 'queue'        : ['Look'],
 'behaviour'    : {
 description: 'A default bot',
 name       : 'Default'
 },
 'flux'         : '[ player, food sibur, food phiras, deraumere phiras ]\n',
 'team'         : 'team1',
 'searchingFood': false,
 'clientNum'    : 0,
 'mapSize'      : {
 x: 0,
 y: 10
 },
 'lastCommand'  : 'Inventory',
 'totalCommands': 27,
 'goesUp'       : 3,
 'level'        : 1,
 'incantating'  : false
 };*/

socket.on('connect', function () {
	console.log("Connected");

	socket.emit('msg', "Hello")
});

socket.on('message', function (data) {
	console.log(data);

	var $datas = $("#datas");
	
	console.log(data.behaviour);

	$("#header").html(`<h1>${data["behaviour"].name} - ${data.behaviour.description}</h1>`);

	let str = `<ul>`;
	$.each(data.inventory, (value, key) => {
		str += `<li>${value} - ${key}</li>`
	});
	str += `</ul>`;
	$("#inventory").html(str);

	str = "";
	$.each(data, function (index, value) {
		console.log(index, value);
		if (index === "inventory" || index === "behaviour" || index === "queue")
			return;
		str += `${index} : ${JSON.stringify(value)} <br>`;
	});
	$("#other").html(str);

	str = "";
	$.each(data.queue, function (index, value) {
		str += `${value}<br>`;
	});
	$("#queue").html(str);

});

//socket.emit('my other event', {my: 'data'});