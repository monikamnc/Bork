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
	cout << "\n" << name << "\n";
	cout << description;
	cout << "\n";

	for (auto var : this->childEntities)
	{
		if (var->type == EXIT)
		{
			Exit* et = (Exit*)var;
			cout << et->name << " to " << et->opposite_name << "\n";
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
			Item* it = (Item*)var;
			cout << "There is '" << it->name << "'\n";
			cout << it->description << "\n";

		}
	}
}