#include "Room.h"
#include <iostream>



// ----------------------------------------------------
Room::Room(const char* title, const char* _description) : Entity(title, _description, NULL)
{
	type = ROOM;
}

// ----------------------------------------------------
Room::~Room()
{
}

// ----------------------------------------------------
void Room::Look() const
{
	cout << name << "\n";
	cout << description;
	cout << "\n";

	for (auto var : this->childEntities)
	{
		if (var->type == EXIT)
		{
			Exit* et = (Exit*)var;
			cout << "Direction: " << et->GetNameFrom((Room*)this) << "\n";
			cout << et->description << "\n";

		}

		if (var->type == ITEM)
		{
			Item* it = (Item*)var;
			cout << "There is '" << it->name << "'\n";
			cout << it->description << "\n";

		}

		if (var->type == NPC)
		{
			Creature* it = (Creature*)var;
			if (it->hit_points > 0)
			{
				cout << "There is '" << it->name << "'\n";
				cout << it->description << "\n";
			}
			else
			{
				cout << "There is the poor corpse of '" << it->name << "'.\n";
			}

		}
	}
}