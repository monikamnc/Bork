#include "Sekai.h"

// ----------------------------------------------------
Sekai::Sekai()
{

	youWin = false;

	// Rooms ----
	Room seashore ("Seashore", "Lovely sun rises and touch your skin.");
	
	heya.push_back(seashore);

}

// ----------------------------------------------------
Sekai::~Sekai()
{

	heya.clear();
}


// ----------------------------------------------------
bool Sekai::GameLogic(string args)
{
	bool ret = true;

	
		if (args == "Look")
		{
			heya[0].Look();
		}


	return ret;
}
