#!/bin/bash

for i in {1..250}
do
    ./node client_ia.js -p 4242 -n team1&
done

for i in {1..250}
do
    ./node client_ia.js -p 4242 -n team2&
done
