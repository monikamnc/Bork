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

Entity* Exit::GetDestinationFrom(const Room* room)
{
	//Si tu eres yo y yo soy tu quién es más tonto de los 2?
	if (room == parent)
		return (Entity*)destination;
	if (room == destination)
		return parent;

	return NULL;
}

const string& Exit::GetNameFrom(const Room* room) const
{
	if (room == parent)
		return name;
	if (room == destination)
		return opposite_name;

	return name;
}

