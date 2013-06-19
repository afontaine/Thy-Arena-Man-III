#include <string>
#include <iostream>

#include "../../Header/Player.h"
#include "../../Header/Item.h"
#include "../../Header/Items/PornMag.h"

using namespace std;

PornMag::PornMag() : Item("PornMag") {
	this->Location = NULL;
	this->Dropped = false;
}

PornMag::~PornMag() {
	delete Location;
}

Point *PornMag::GetLocation() {
	return this->Location;
}

void PornMag::SetLocation(Point *point) {
	if(this->Location != NULL)
		delete this->Location;
	this->Location = new Point(point->GetX(), point->GetY());
	return;
}

void PornMag::SetLocation(int x, int y) {
	if(this->Location != NULL)
		delete this->Location;
	this->Location = new Point(x, y);
	return;
}

bool PornMag::isDropped() {
	return this->Dropped;
}

void PornMag::Use(Player *player) {
	this->SetLocation(player->GetLocation());
	this->Dropped = true;
	cout << player->GetName() << " dropped a porn magazine at (" << player->GetLocation()->GetX() <<", "<< player->GetLocation()->GetY() << "). Watch out!" << endl;
}

