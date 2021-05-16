#include "Creature.h"
#include <iostream>
#include "Room.h"


Creature::Creature(const string name, const string description, Room* room) : Entity(name, description), room(room)
{
	
}

Creature::~Creature()
{
}