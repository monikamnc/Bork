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

void Player::Move(string args)
{
	
	for (auto var : parent->childEntities)
	{
		if (var->type == EXIT)
		{
			Exit* et = (Exit*)var;
			if (et->name == args) 
			{

				if (et->locked)
				{
					cout << "\nThat exit is locked.\n";
					return;
				}

				//Si encontramos una salida y es la dirección correcta, borramos el child player de roomX
				//Asignar nuevo parent a player
				cout << "\nYou take direction " << et->GetNameFrom((Room*)parent) << "...\n";

				Entity* aux = (et->GetDestinationFrom((Room*)parent));
				ChangeParent(aux);

				return;
			}
		}
	}
	cout << "\nThere is no exit at '" << args << "'.\n";
}

