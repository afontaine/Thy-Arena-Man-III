#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Item.h"

#define ROUGUE 1
#define SOLDIER 2
#define BERZERKER 3

#define AI true



class Player {
private:
	string Name;	// Name of character
	int Health;		// Health of player
	int Skill;		// Skill of player
	int Strength;	// Strength of player
	int Class;		// Player's class. Either Rougue, Soldier, or Berzerker
	bool Ai;		// AI flag, default is false

	Equipment *Armour;	// Armour of player
	Equipment *Weapon;	// Weapon of player
	vector<Item *> Equip;		// Vector(s are cool) of items the player is holding

public:
	Player(string name);
	~Player();

	string GetName();
	void SetName(string name);

	int GetHealth();
	void SetHealth(int health);
	
	int GetSkill();
	void SetSkill(int skill);
	
	int GetStrength();
	void SetStrength(int strength);

	string GetClass();
	void SetClass(char newClass);

	bool GetAi();
	void SetAi(bool ai);

	Equipment GetArmour();
	void SetArmour(Equipment armour);

	Equipment GetWeapon();
	void SetWeapon(Equipment weapon);


	void Randomize();
	void ChooseClass();
	void ChooseAi();
	void ChooseArmour();
	void ChooseWeapon();
	void ChooseItems();
	void RandomItems();
}

#endif