#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

using namespace std;

class Weapon {
private:
	string Name;
	int Speed;
	int Strength;

public:
	Weapon(string name, int speed, int strength);

	string GetName();
	void SetName(string name);

	int GetSpeed();
	void SetSpeed(int speed);

	int GetStrength();
	void SetStrength(int strength);
};

#endif