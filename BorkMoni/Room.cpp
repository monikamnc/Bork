#include "Room.h"
#include <iostream>



// ----------------------------------------------------
Room::Room(const char* title, const char* _description)
{
	name = title;
	description = _description;
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