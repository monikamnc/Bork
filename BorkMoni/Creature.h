#pragma once
#include "Entity.h"
#include "Room.h"
using namespace std;

class Room;

class Creature : public Entity
{
public:
	Creature(const string name, const string description, Room* room);
	~Creature();


	//Variables
	Creature* combat_target;
	int hit_points;
	int min_damage;
	int max_damage;
	int min_protection;
	int max_protection;

	//NPC* combat_target;
	/*Item* weapon;
	Item* armour;*/
};

