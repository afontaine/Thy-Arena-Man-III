#include <string>
#include "Player.h"
#include "Item.h"
#include "Medkit.h"

using namespace std;

Medkit::Medkit() : Item("Medkit") {

}

Medkit::~Medkit(){}

void Medkit::Use(Player *player) {
	player->SetHealth(player->GetHealth() + 5);

	delete this;

	return;
}