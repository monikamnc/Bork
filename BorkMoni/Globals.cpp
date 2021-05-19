#include "Globals.h"

string ToLowerCase(string s)
{
	for (auto& c : s)
	{
		c = tolower(c);
	}
	return s;
}

int Rando(int min, int max)
{
	return rand() % max + min;
}