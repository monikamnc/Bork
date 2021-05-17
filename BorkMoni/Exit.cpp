#include "Exit.h"
#include <iostream>
#include "Room.h"


// ----------------------------------------------------
Exit::Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination, bool one_way) :
	Entity(name, description, (Entity*)origin),
	closed(false), locked(false), key(NULL), one_way(one_way), destination(destination), opposite_name(opposite_name)
{
	type = EXIT;

	if (one_way == false)
		destination->childEntities.push_back(this);
}

// ----------------------------------------------------
Exit::~Exit()
{
}

