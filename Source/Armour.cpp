#include <string>

#include "..\Header\Armour.h"

using namespace std;

Armour::Armour(string name, int protection, int modifier) {
	this->Name = name;
	this->Protection = protection;
	this->Modifier = modifier;
}

string Armour::GetName() {
	return this->Name;
}

void Armour::SetName(string name) {
	this->Name = name;
	return;
}

int Armour::GetProtection() {
	return this->Protection;
}

void Armour::SetProtection(int protection) {
	this->Protection = protection;
	return;
}

int Armour::GetModifier() {
	return this->Modifier;
}

void Armour::SetModifier(int modifier) {
	this->Modifier = modifier;
	return;
}