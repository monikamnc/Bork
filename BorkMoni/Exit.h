#pragma once
#include <string>
#include "Entity.h"

class Room;

using namespace std;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination, bool one_way = false);
	~Exit();


	//Variables
	bool one_way;
	bool closed;
	bool locked;
	string opposite_name;
	Room* destination;
	Entity* key;
};
