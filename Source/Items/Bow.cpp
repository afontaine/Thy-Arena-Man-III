#include <string>
#include <cstdlib>
#include <iostream>
#include "../../Header/Player.h"
#include "../../Header/Item.h"
#include "../../Header/Items/Bow.h"

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

void Bow::Use(Player *player) {
	Player *poorSucker = NULL;

	cout << "Select the player you wish to use this bow on." << endl;
	//TODO Add Player select

	cout << "You are firing an arrow at " << poorSucker->GetName() << "." << endl;

	int attack, defend, modify, loss;
	int playerX, playerY;
	int poorSuckerX, poorSuckerY;

	playerX = player->GetLocation()->GetX();
	playerY = player->GetLocation()->GetY();

	poorSuckerX = poorSucker->GetLocation()->GetX();
	poorSuckerY = poorSucker->GetLocation()->GetY();

	attack = rand() % 20 + 1; // Roll d20s
	defend = rand() % 20 + 1;
	modify = (int) (sqrt((playerX*playerX - poorSuckerX*poorSuckerX) + (playerY*playerY + poorSuckerY*poorSuckerY)) + 0.5); // Cartesean distance
	loss = (player->GetSkill()/modify); // Something I made up. Will probably alter later. Health loss

	if(attack == 20 && defend == 1) { // attack: critical success; defend: critical failure
		cout << poorSucker->GetName() << " got hit right in the eye socket! HEADSHOT!" << endl;
		poorSucker->Dead();
	}
	else if(attack == 1 && defend == 20) { // attack: critical failure; defend: critical success
		cout << poorSucker->GetName() << " caught the arrow mid-flight! " << endl;
		cout << "What's this? " << poorSucker->GetName() << " charged at " << player->GetName() << "!" << endl;
		cout << poorSucker->GetName() << " sunk the arrow right through " << player->GetName() << "'s mouth!" << endl;
		poorSucker->SetLocation(player->GetLocation());
		player->Dead(); // Seriously, we need to kill people
	}
	else if(defend == 20) // attack: unimportant; defend: critical success
		cout << poorSucker->GetName() << " grabbed the arrow mid-flight and snapped it in half!" << endl;
	else if(loss < 0) // Check to see if there's acutal health loss
		cout << "The arrow glanced off of " << poorSucker->GetName() << "'s mighty chest." << endl;
	else if(attack == 1) { // attack: critical failure; defend: critical success
		cout << player->GetName() << "'s feeble attempt to fire a bow backfires and hits them in the foot!" << endl;
		player->SetHealth(player->GetHealth() - 3);
		if(!player->isAlive())
			player->Dead();
	}
	else if(attack < defend) // attack rolls worse than defense
		cout << poorSucker->GetName() << " dodged the arrow! What a coward!" << endl;
	else {
		if (attack == 20) // attack: critical success; defense: unimportant
			poorSucker->SetHealth(poorSucker->GetHealth() - loss*2); // double damage
		else
			poorSucker->SetHealth(poorSucker->GetHealth() - loss); // standard damage
	}

	this->Arrows--;

	return;
}