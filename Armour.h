#ifndef	ARMOUR_H_
#define ARMOUR_H_

#import <string>

class Armour {
private:
	string Name;
	int Protection;
	int Modifier;

public:
	Armour(string name, int protection, int modifier);

	string GetName();
	void SetName(string name);

	int GetProtection();
	void SetProtection(int protection);

	int GetModifier();
	void SetModifier(int modifier);

};

#endif