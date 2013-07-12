#include <string>
#include <iostream>
#include <cstdlib>

#include "../Header/Item.h"
#include "../Header/Player.h"
#include "../Header/Steroids.h"
#include "../Header/Gui.h"

using namespace std;

extern Gui *gui;

Steroids::Steroids() : Item("Steroids"){}

void Steroids::Use(Player *player) {
	int roll = rand() % 20 + 1;

	if(roll > 1) {
		gui->printLog(player->GetName() + " has used steroids! They are now MEGA AWESOME!!!!!!1!111!!1!1!!!!");
		player->SetAwesome(true);
	}
	else {
		gui->printLog(player->GetName() + " feels a little funny...");
		gui->printLog(player->GetName() + "'s gonads have shrivelled! Their honor lost, they leave the battle.");
		player->SetHealth(DEAD);
	}

	return;
}
