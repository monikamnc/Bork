#include "Creature.h"
#include <iostream>
#include "Room.h"


Creature::Creature(const string name, const string description, Room* room) : Entity(name, description, (Entity*)room)
{
	type = NPC;
	hit_points = 1;
	weapon = armour = NULL;
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

void Creature::Attack(string enemy)
{
	for (auto e : parent->childEntities)
	{
		if (ToLowerCase(e->name) == enemy )
		{
			if (((Creature*)e)->hit_points > 0)
			{
				int damage = Rando(weapon->min_value, weapon->min_value);
				if (((Creature*)e)->armour != NULL)
				{
					damage -= Rando(((Creature*)e)->armour->min_value, ((Creature*)e)->armour->max_value);
				}
				if (damage <= 0)
				{
					damage = 0;
				}
				cout << "You attack " << enemy << " and do " << damage << " points of damage.\n";
				((Creature*)e)->hit_points -= damage;
				if (((Creature*)e)->hit_points <= 0)
				{
					cout << "You killed " << enemy << "!\n";
				}
				return;
			}
			else
			{
				cout << "You can't attack " << enemy << "'s poor corpse.\n";
				return;
			}

		}
	}
	cout << "You can't find " << enemy << " in the room.\n";
}

void Creature::ReceiveAttack(string enemy)
{
	for (auto e : parent->childEntities)
	{
		if (ToLowerCase(e->name) == enemy && ((Creature*)e)->hit_points > 0)
		{
			if (((Creature*)e)->weapon)
			{
				int damage = Rando(((Creature*)e)->weapon->min_value, ((Creature*)e)->weapon->min_value);
				if (((Creature*)this)->armour != NULL)
				{
					int blocked = Rando(armour->min_value, armour->max_value);
					damage -= blocked;
					if (damage <= 0)
					{
						damage = 0;
					}
					cout << "You block " << blocked << " points of damage.\n";
				}
				cout << "You receive " << damage << " points of damage.\n";
				((Creature*)this)->hit_points -= damage;
				return;
			}
			else
			{
				cout << "The " << e->name << " does nothing.\n";
			}
		}
	}
}