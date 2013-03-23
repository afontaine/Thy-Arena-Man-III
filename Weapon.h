#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon {
private:
	std::string Name;
	int Speed;
	int Strength;

public:
	Weapon(std::string name, int speed, int strength);

	std::string GetName();
	void SetName(std::string name);

	int GetSpeed();
	void SetSpeed(int speed);

	int GetStrength();
	void SetStrength(int strength);
};

#endif