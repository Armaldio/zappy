#!/bin/bash

for i in {1..5}
do
    node zappy_ai.js -p 4242 -n team1&
done

for i in {1..5}
do
    node zappy_ai.js -p 4242 -n team2&
done
