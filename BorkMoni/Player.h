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
	void Take(string item, string itemContainer);
	void Drop(string itemDropped, string itemContainer);
	void Use(string usableO, string destinationO);
	void Inventory();
	void Give(string item, string destinationNPC);
	void Loot(string args);
	void Equip(string item);
	bool Attack(string enemy);

};

