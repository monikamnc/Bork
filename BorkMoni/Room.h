#include <string>

using namespace std;

//class Exit;

class Room
{

public:
	Room(const char* name, const char* description);
	~Room();

	void Look() const;

	//Exit* GetExit(const string& direction) const;

	//Variables

	string name;
	string description;
};

