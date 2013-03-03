#ifndef	ARMOUR_H_
#define ARMOUR_H_

#include <string>


class Armour {
private:
	std::string Name;
	int Protection;
	int Modifier;

public:
	Armour(std::string name, int protection, int modifier);

	std::string GetName();
	void SetName(std::string name);

	int GetProtection();
	void SetProtection(int protection);

	int GetModifier();
	void SetModifier(int modifier);

};

#endif