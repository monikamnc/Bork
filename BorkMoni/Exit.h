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

	Entity* GetDestinationFrom(const Room* room);
	const string& GetNameFrom(const Room* room) const;

	//Variables
	bool one_way;
	bool locked;
	string opposite_name;
	Room* destination;
	Entity* key;
};
