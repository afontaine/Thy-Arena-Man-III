#include <string>

#include "Weapon.h"

using namespace std;

Weapon::Weapon(string name, int speed, int strength) {
	this->Name = name;
	this->Speed = speed;
	this->Strength = strength;
}

string Weapon::GetName() {
	return this->Name;
}

void Weapon::SetName(string name) {
	this->Name = name;
	return;
}

int Weapon::GetSpeed() {
	return this->Speed;
}

void Weapon::SetSpeed(int speed) {
	this->Speed = speed;
	return;
}

int Weapon::GetStrength() {
	return this->Strength;
}

void Weapon::SetStrength(int strength) {
	this->Strength = strength;
	return;
}