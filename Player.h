#ifndef PLAYER_H
#define PLAYER_H

#define ROUGUE 1
#define SOLDIER 2
#define BERZERKER 3

#define AI true

class Player {
private:
	int Health;		// Health of player
	int Skill;		// Skill of player
	int Strength;	// Strength of player
	int Class;		// Player's class. Either Rougue, Soldier, or Berzerker
	bool Ai;		// AI flag, default is false

	Equipment *Armour;	// Armour of player
	Equipment *Weapon;	// Weapon of player
	Item Equip[4];		// Array of items the player is holding

public:
	Player();
	~Player();

	int GetHealth();
	SetHealth(int health);
	
	int GetSkill();
	SetSkill(int skill);
	
	int GetStrength();
	SetStrength(int strength);

	int GetClass();
	SetClass(int Class);

	bool GetAi();
	SetAi(bool ai);
}

#endif