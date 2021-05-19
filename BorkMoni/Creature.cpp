#include "Creature.h"
#include <iostream>
#include "Room.h"


Creature::Creature(const string name, const string description, Room* room) : Entity(name, description, (Entity*)room)
{
	type = NPC;
	hit_points = 1;
	min_damage = max_damage = min_protection = max_protection = 0;
	weapon = armour = NULL;
	combat_target = NULL;
}

Creature::~Creature()
{
}

void Creature::AutoEquip()
{
	for (auto item : this->childEntities)
	{
		if (((Item*)item)->item_type == WEAPON)
			weapon = ((Item*)item);
		else if (((Item*)item)->item_type == ARMOUR)
			armour = ((Item*)item);
	}
}