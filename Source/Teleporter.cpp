#include <iostream>
#include <string>
#include <cstdlib>

#include "../Header/Item.h"
#include "../Header/Player.h"
#include "../Header/Teleporter.h"
#include "../Header/Gui.h"

using namespace std;

extern Gui *gui;

Teleporter::Teleporter() : Item("Teleporter") {}

void Teleporter::Use(Player *player) {
	int x,y;
	
	gui->printMenu("So, " + player->GetName() + ". You think you can jump around wherever you please? 'Cause you can. Go for it.");
	gui->printMenu("We just need some info.");
	gui->printMenu("What is the X-coordinate you would like to jump to? (0 is the left edge of the arena, 5 is right)");
	x = (int) gui->getMenu();
	gui->printMenu("What is the Y-coordinate you would like to jump to? (0 is the left edge of the arena, 5 is right)");
	y = (int) gui->getMenu();
	gui->printMenu("Great! Did I mention there's a 1/4 chance things might not work as planned? I always forget about that. Ah well, let's get going!");

	int chance = rand() % 20 + 1;
	
	if(chance > 5) {
		gui->printLog("IT'S WORKING! IT'S WORKING!");
		player->SetLocation(x, y);
	}
	else if(chance > 1) {
		gui->printLog("Something's... somthing's wrong.");
		player->SetLocation(y, x);
	}
	else {
		gui->printLog("TRANSPORTER FAILURE: SELF-DESTRUCT IMMINANTE");
		player->SetHealth(player->GetHealth() - 3);
	}

	return;
}
