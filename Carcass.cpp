#include <string>

#include "Carcass.h"
#include "Player.h"
#include "Item.h"

using namespace std;

Carcass::Carcass() : Item("Carcass") {
	this->Effect = -2;
}

Carcass::~Carcass() {}

int Carcass::GetEffect() {
	return this->Effect;
}

void Carcass::SetEffect(int effect) {
	this->Effect = effect;
	return;
}

void Carcass::Use(Player *player) {

} //TODO implement