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

const net = require('net');

const client = new net.Socket();

client.setEncoding('utf8');

let lastCommand = "";

let send = function (cmd) {
    lastCommand = cmd.split(/[\\n\s]/g)[0];
    client.write(cmd + "\n", function () {
        console.log(">> " + cmd);
    });
};

client.connect(4242, '127.0.0.1', () => {
    console.log('Client connected');
});

let flux = "";

client.on('data', (data) => {
    flux += data;

    if (data[data.length - 1] === '\n') {

        console.log('<< ' + JSON.stringify(flux));

        flux = flux.toLowerCase();

        if (flux === "ko\n")
            console.log("Command not recognized by the server");
        else if (flux === "dead\n")
            console.log("You are dead");
        else {

            switch (lastCommand) {
                case "Look":
                    let datas = flux.replace('\n', '').replace(/[\[\]]/g, '').split(',').map((x) => {
                        return x.trim();
                    });

                    // Format datas
                    datas.forEach((item, i) => {
                        let a = item.split(' ');
                        datas[i] = {"items": a, "length": a.length, "case": i};
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

                    //console.log(JSON.stringify(datas, null, '\t'));

                    //datas = datas[0].items.splice(0, 1);

                    if (datas[0].items && datas[0].items.length !== 0)
                        send("Take " + datas[0].items[0]);
                    else
                        send("Forward");
                    break;

                case "Take":
                    if (flux === "ok\n")
                        send("Look");

                    break;

                case "Forward":
                    if (flux === "ok\n")
                        send("Look");

                    break;

                case "team1":
                    let a = {};
                    let split = flux.split(/[\\n\s]/g);
                    a.remaining = split[0];
                    a.w = split[1];
                    a.h = split[2];

                    send("Look");

                    break;

                // First command
                case "":
                    send("team1");
                    //send("Look");
                    break;

                default:
                    console.log("Command not supported by client");
            }
        }

        flux = "";
    }
});

client.on('close', () => {
    console.log('Connection closed');
});

client.on('end', function () {
    console.log('Disconnected from server');
});

client.on('error', (err) => {
    console.log("Error : ", err.code);
});


//client.destroy(); // kill client after server's response
