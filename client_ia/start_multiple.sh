#!/bin/bash

for i in {1..5}
do
    node zappy_ai.js -p 4242 -n Team1&
done

for i in {1..5}
do
    node zappy_ai.js -p 4242 -n Team2&
done
