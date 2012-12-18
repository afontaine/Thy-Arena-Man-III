#include <string>
#include "Player.h"
#include "Item.h"
#include "Bow.h"
#include <random>
#include <iostream>

using namespace std;

Bow::Bow() : Item("Bow") {
	Arrows = 5;
}

Bow::~Bow(){}

void Bow::SetArrows(int arrows) {
	this->Arrows = arrows;
	return;
}

int Bow::GetArrows() {
	return this->Arrows;
}

void Bow::Use(Player *player);