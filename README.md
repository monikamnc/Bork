# Welcome to Bork!

Hi! This is a simple zork game that I have developed in one week. In this file you will find a small guide that will help you to play and finish the game.


## Authors

This entire code is developed by Mónica Martín. 

## Guide

You wake up in the seashore with one mission: to find the potion and drink it to escape from this universe. Take care because there are many drinks and only one will allow you to reach the good ending. 
You will find a blocked path to the east. To unlock it, you will need to attack the trees to get the ladder. Before you get it, you have to pick up the Axe that that will allow you to attack the trees. The Axe is inside a Box in the Fisherman's House, but that Box is closed with a Key that has the Fisherman. To get the key, you will need to give him the bottle of Rum that is in the Seashore, at the beggining.

Use the ladder to get to the Ship, get the Shield and equip it, go down and get the gun and equip it. Go down one final time, fight the final boss and drink your Potion of Eternal Life.

Extra help for difficult commands: give rum to fisherman, use key in box, take axe from box, unlock east with ladder.

## Map

![BorkMap](https://github.com/monikamnc/Bork/blob/main/MapBork.jpg?raw=true)

## Command list

Commands with no arguments: `look, north, south, east, west, up, down, inventory`.

Commands with one argument (example: drink potion): `take, drop, loot, equip, attack, drink`.

Commands with three arguments (example: use key in box): `use, give, drop, take, unlock`.


## Extra features implemented

- State machine for the main loop
- RPG stats in items
- Exits that can be unlocked with keys
- Real-Time combat (only Attack action implemented)
