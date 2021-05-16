#pragma once
#include "Entity.h"
using namespace std;

class Room;

class Creature : public Entity
{
public:
	Creature(const string name, const string description, Room* room);
	virtual ~Creature();
	Room* room;
};

