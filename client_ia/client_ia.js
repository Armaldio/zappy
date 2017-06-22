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
    lastCommand = cmd.split(' ')[0];
    client.write(cmd, function () {
        console.log(">> " + cmd);
    });
};

client.connect(6666, '127.0.0.1', () => {
    console.log('Client connected');
});

let flux = "";

client.on('data', (data) => {
    flux += data;

    if (data[data.length - 1] === '\n') {

        console.log('<< ' + JSON.stringify(flux));

        if (flux === "KO\n")
            console.log("Command not recognized by the server");
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

                    // Sort datas
                    datas.sort((a, b) => {
                        return (b.length - a.length);
                    });

                    // Remove players
                    datas.forEach((item, i) => {
                        item.items.forEach((x, xi) => {
                            if (x === "player") {
                                item.items.splice(xi, 1);
                            }
                        });
                    });

                    if (datas[0].items.length !== 0)
                        send("Take " + datas[0].items[0]);


                    console.log(JSON.stringify(datas, null, '\t'));

                    break;

                case "Take":
                    if (flux === "OK\n")
                        send("Look");

                    break;

                // First command
                case "":
                    send("Look");
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
