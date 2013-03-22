#include <string>
#include <iostream>
#include <cstdlib>

#include "Item.h"
#include "Player.h"
#include "Steroids.h"

using namespace std;

Steroids::Steroids() : Item("Steroids"){}

void Steroids::Use(Player *player) {
	int roll = rand() % 20 + 1;

	if(roll > 1) {
		cout << player->GetName() << " has used steroids! They are now MEGA AWESOME!!!!!!1!111!!1!1!!!!" << endl;
		player->SetAwesome(true);
	}
	else {
		cout << player->GetName() << " feels a little funny..." << endl;
		cout << player->GetName() << "'s gonads have shrivelled! Their honor lost, they leave the battle." << endl;
		player->SetHealth(DEAD);
	}

	return;
}
