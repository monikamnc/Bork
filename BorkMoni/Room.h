#pragma once
#include <string>
#include "Entity.h"

using namespace std;

//class Exit;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

 
	void Look() const;
};

