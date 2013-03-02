#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Item.h"
#include "Weapon.h"
#include "Armour.h"

#define ROUGUE 1
#define SOLDIER 2
#define BERZERKER 3

#define AI true

using namespace std;

//Carteasean coordinates (bottom right is (0,0))
class Point {
private:
	int X, Y;
public:
	Point(int x, int y) {this->X = x; this->Y = y;}
	Point() {this->X = 0; this->Y = 0;}
	int GetX() {return X;}
	int GetY() {return Y;}
	void SetX(int x) {this->X = x;}
	void SetY(int y) {this->Y = y;}

};

class Player {
private:
	string Name;	// Name of character
	int Health;		// Health of player
	int Skill;		// Skill of player
	int Strength;	// Strength of player
	int Class;		// Player's class. Either Rougue, Soldier, or Berzerker
	bool Ai;		// AI flag, default is false
	Point *Location;

	Armour *Defender;	// Armour of player
	Weapon *Attacker;	// Weapon of player
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

	Armour GetDefender();
	void SetDefender(Armour *armour);

	Weapon GetAttacker();
	void SetAttacker(Weapon *weapon);

	Point *GetLocation();
	void SetLocation(Point *location);
	void SetLocation(int x, int y);


	void Randomize();
	void ChooseClass();
	void ChooseAi();
	void ChooseArmour();
	void ChooseWeapon();
	void ChooseItems();
	void RandomItems();

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void Dead();

	bool isAlive();
};

#endif