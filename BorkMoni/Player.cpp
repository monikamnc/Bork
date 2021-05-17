#include "Player.h"
#include <iostream>
#include <vector>


using namespace std;


Player::Player(const char* title, const char* description, Room* room) : Creature(title, description, room)
{
	type = PLAYER;
}


Player::~Player()
{
}


void Player::Look(string args) const
{
	Room* rum = (Room*)parent;
	rum->Look();


	cout << "\n" << this->name << "\n";
	cout << this->description << "\n";
}

void Player::Move(string args) const
{
	
	for (auto var : parent->childEntities)
	{
		if (var->type == EXIT)
		{
			Exit* et = (Exit*)var;
			if (et->name == args) 
			{
				//Si encontramos una salida y es la dirección correcta, borramos el child player de roomX
				for (int i = 0; i < parent->childEntities.size(); i++)
				{
					if (parent->childEntities[i]->type == PLAYER)
					{
						parent->childEntities.erase(parent->childEntities.begin() + i);
						break;
					}
				}
				//Asignar nuevo parent a player
				Entity* owo = (Entity*) et->destination;

				parent->childEntities.push_back(var);
			}


		}
	}




	
}

