#include "Creature.h"
#include <iostream>
#include "Room.h"


Creature::Creature(const string name, const string description, Room* room) : Entity(name, description, (Entity*)room)
{
	type = NPC;
	hit_points = 1;
	min_damage = max_damage = min_protection = max_protection = 0;
	//weapon = armour = NULL;
	combat_target = NULL;
}

Creature::~Creature()
{
}