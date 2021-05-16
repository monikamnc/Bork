#include "Sekai.h"

// ----------------------------------------------------
Sekai::Sekai()
{

	youWin = false;

	// Rooms ----
	Room* seashore = new Room ("Seashore", "Lovely sun rises and touch your skin.");
	
	entities.push_back(seashore);

	// Player ----
	player = new Player("Hero", "You are an awesome adventurer!", seashore);
	player->hit_points = 25;

	entities.push_back(player);

}

// ----------------------------------------------------
Sekai::~Sekai()
{

	entities.clear();
}


// ----------------------------------------------------
bool Sekai::GameLogic(vector<string> args)
{
	bool ret = true;

	if (args.size() == 1)
	{
		if (args[0] == "Look")
		{
			player->Look(args[0]);
		}
	}

	return ret;
}
