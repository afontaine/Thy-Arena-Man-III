#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player::Player(string name) {
	this->SetName(name);
	int ai;
	cout << "Are you an AI?" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	
	cin >> ai;
	
	if(ai == 1) {
		this->SetAi(true);
		this->Randomize();
	}
	else
		this->SetAi(false);

}

Player::~Player() {
	delete this->Weapon;
	delete this->Armour;
	std::vector<Item *>::iterator Iterate;
	for(Iterate = Equip.begin(); Iterate != Equip.end(); Iterate++)
		delete *Iterate;
}

string Player::GetName() {
	return this->Name;
}

void Player::SetName(string name) {
	this->Name = name;
}

int Player::GetHealth() {
	return this->Health;
}

void Player::SetHealth(int health) {
	this->Health = health;
	return;
}

int Player::GetSkill() {
	return this->Skill;
}

void Player::SetSkill(int skill) {
	this->Skill = skill;
	return;
}

int Player::GetStrength() {
	return this->Strength;
}

void Player:: SetStrength(int strength) {
	this->Strength = strength;
	return;
}

string Player::GetClass() {
	switch (this->Class) {
	case ROUGUE:
		return "Rougue";
	case SOLDIER:
		return "Soldier";
	case BERZERKER:
		return "Berzerker";
	default:
		return NULL;
	}
	return NULL;
}

void Player::SetClass(char newClass) {
	switch (newClass) {
	case 'R':
		this->Class = ROUGUE;
		break;
	case 'B':
		this->Class = BERZERKER;
		break;
	case 'S':
		this->Class = SOLDIER;
		break;
	default:
		this->Class = SOLDIER;
		break;
	}
	return;
}


bool Player::GetAi() {
	return this->Ai;
}

void Player::SetAi(bool ai) {
	this->Ai = false;
	if(ai)
		this->Ai = AI;
	return;
}