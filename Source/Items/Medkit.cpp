#include <string>
#include "../../Header/Player.h"
#include "../../Header/Item.h"
#include "../../Header/Items/Medkit.h"

using namespace std;

Medkit::Medkit() : Item("Medkit") {

}

Medkit::~Medkit(){}

void Medkit::Use(Player *player) {
	player->SetHealth(player->GetHealth() + 5);

	delete this;

	return;
}