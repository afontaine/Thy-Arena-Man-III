#include <iostream>
#include <string>
#include <cstdlib>

#include "Teleporter.h"

using namespace std;

Teleporter::Teleporter() : Item("Teleporter") {}

void Teleporter::Use(Player *player) {
	int x,y;
	
	cout << "So, " << player->GetName << ". You think you can jump around wherever you please? 'Cause you can. Go for it." << endl;
	cout << "We just need some info." << endl;
	cout << "What is the X-coordinate you would like to jump to? (0 is the left edge of the arena, 5 is right) ";
	cin >> x;
	cout << "What is the Y-coordinate you would like to jump to? (0 is the left edge of the arena, 5 is right) ";
	cin >> y;
	cout << "Great! Did I mention there's a 1/4 chance things might not work as planned? I always forget about that. Ah well, let's get going!" << endl;

	int chance = rand() % 20 + 1;
	
	if(chance > 5) {
		cout << "IT'S WORKING! IT'S WORKING!" << endl;
		player->SetLocation(x, y);
	}
	else if(chance > 1) {
		cout << "Something's... somthing's wrong." << endl;
		player->SetLocation(y, x);
	}
	else {
		cout << "TRANSPORTER FAILURE: SELF-DESTRUCT IMMINANTE" << endl;
		player->SetHealth(player->GetHealth - 3);
	}