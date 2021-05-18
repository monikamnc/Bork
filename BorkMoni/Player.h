#pragma once
#include "Globals.h"
#include "Creature.h"
#include "Room.h"
#include "Item.h"
#include <vector>

class Player : public Creature
{

public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Look(string args) const;
	void Move(string args);
	void Take(string args);
	void Drop(string args);

};

