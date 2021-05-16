#pragma once
//#include "Sekai.h"
#include "Room.h"
#include <vector>

class Player
{

public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Look(const vector<string>& args) const;

	//Variables
	string name;
	string description;
	Room room;
	int hit_points;
	int min_damage;
	int max_damage;
	int min_protection;
	int max_protection;
	
	//NPC* combat_target;
	/*Item* weapon;
	Item* armour;*/
};

