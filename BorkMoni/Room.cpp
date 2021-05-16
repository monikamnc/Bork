#include "Room.h"
#include <iostream>



// ----------------------------------------------------
Room::Room(const char* title, const char* _description) : Entity(title, description, NULL)
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
}