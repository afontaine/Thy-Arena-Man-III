#include <iostream>
#include <string>
#include <cstdlib>

#include "../Header/Player.h"
#include "../Header/Item.h"
#include "../Header/Weapon.h"
#include "../Header/Armour.h"
#include "../Header/PornMag.h"
#include "../Header/Bow.h"
#include "../Header/Medkit.h"
#include "../Header/Teleporter.h"
#include "../Header/Steroids.h"
#include "../Header/Carcass.h"
#include "../Header/Gui.h"

using namespace std;


extern Gui * gui;

Player::Player(string name) {

	this->SetName(name);
	
	this->ChooseAi();
	
	if(this->Ai == AI) {
		this->SetLocation(1, 1);
		return;
	}

	this->ChooseClass();

	this->ChooseArmour();

	this->ChooseWeapon();
	
	this->ChooseItems();

	this->SetLocation(1, 1);

}

Player::~Player() {
	delete this->Attacker;
	delete this->Defender;
	vector<Item *>::iterator Iterate;
	for(Iterate = Equip.begin(); Iterate != Equip.end(); Iterate++)
		delete *Iterate;
}

string Player::GetName() {
	return this->Name;
}

void Player::SetName(string name) {
	this->Name = name;
}

int Player::GetHealth() {
	return this->Health;
}

void Player::SetHealth(int health) {
	this->Health = health;
	return;
}

int Player::GetSkill() {
	return this->Skill;
}

void Player::SetSkill(int skill) {
	this->Skill = skill;
	return;
}

int Player::GetStrength() {
	return this->Strength;
}

void Player:: SetStrength(int strength) {
	this->Strength = strength;
	return;
}

string Player::GetClass() {
	switch (this->Class) {
	case ROUGUE:
		return "Rougue";
	case SOLDIER:
		return "Soldier";
	case BERZERKER:
		return "Berzerker";
	default:
		return NULL;
	}
	return NULL;
}

void Player::SetClass(char newClass) {
	switch (newClass) {
	case 'R':
		this->Class = ROUGUE;
		this->SetStrength(8);
		this->SetSkill(20);
		break;
	case 'B':
		this->Class = BERZERKER;
		this->SetStrength(10);
		this->SetSkill(18);
		break;
	case 'S':
		this->Class = SOLDIER;
		this->SetSkill(19);
		this->SetStrength(9);
		break;
	default:
		this->Class = SOLDIER;
		this->SetSkill(19);
		this->SetStrength(9);
		break;
	}

	this->SetHealth(20);

	return;
}


bool Player::GetAi() {
	return this->Ai;
}

void Player::SetAi(bool ai) {
	this->Ai = false;
	if(ai)
		this->Ai = AI;
	return;
}

Armour *Player::GetDefender() {
	return this->Defender;
}

void Player::SetDefender(Armour *armour) {
//	delete this->Defender;
	this->Defender = armour;
	return;
}

Weapon *Player::GetAttacker() {
	return this->Attacker;
}

void Player::SetAttacker(Weapon *weapon) {
	this->Attacker = weapon;
	return;
}

Point *Player::GetLocation() {
	return this->Location;
}

void Player::SetLocation(Point *location) {
	this->Location->~Point();
	this->Location = new Point(location->GetX(), location->GetY());
}

void Player::SetLocation(int x, int y) {
	this->Location->~Point();
	this->Location = new Point(x,y);
	return;
}

void Player::Randomize() {
	int random = rand() % 3;
	
	switch (random) {
	case 0:
		this->SetClass('R');
		break;
	case 1:
		this->SetClass('S');
		break;
	case 2:
		this->SetClass('B');
		break;
	}

	random = rand() % 3;

	switch (random) {
	case 0:
		this->SetAttacker(new Weapon("Rapier", 6, 2));
		break;
	case 1:
		this->SetAttacker(new Weapon("Broadsword", 5, 4));
		break;
	case 2:
		this->SetAttacker(new Weapon("BattleAxe", 4, 6));
	}

	random = rand() % 4;

	switch (random) {
	case 0:
		this->SetDefender(new Armour("Leather", 1, 0));
		break;
	case 1:
		this->SetDefender(new Armour("Chainmail", 3, -1));
		break;
	case 2:
		this->SetDefender(new Armour("Platemail", 5, -2));
		break;
	case 3:
		this->SetDefender(new Armour("Naked", 0, 2));
		break;
	}

	this->RandomItems();
}

void Player::ChooseClass() {
	cout << this->Name << ", CHOOSE YOUR CLASS!" << endl;
	cout << "(R)ogue class: Attack twice every 5 moves" << endl;
	cout << "(S)oldier class: Stay still and attack, receive a stat boost" << endl;
	cout << "(B)erzerker class: Become MEGA AWESOME every 5 moves" << endl << endl;

	cout << "Here's a stat table so you can make your ultimate decision:" << endl;
	cout << "\t\tRougue\tSoldier\tBerzerker" << endl;
	cout << "Skill:\t20\t19\t18" << endl;
	cout << "Strength:\t8\t9\t10" << endl;
	cout << "Health:\t20\t20\t20" << endl << endl;

	char Class = 'G';
	while(Class != 'R' && Class != 'S' && Class != 'R') {
		cout << "CHOOOSE! ";
		cin >> Class;
	}

	this->SetClass(Class);

	cout << "Awesome, you're a motherfucking " << this->GetClass() << "!" << endl;
}

void Player::ChooseAi() {
	int ai = 0;
	cout << "Are you an AI?" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	
	while(ai != 1 && ai != 2) {
		cin >> ai;
	}
	if(ai == 1) {
		this->SetAi(true);
		this->Randomize();
	}
	else
		this->SetAi(false);
}

void Player::ChooseArmour() {
	cout << "Armour time, maggot!" << endl;
	cout << "(L)eather: Sexy" << endl;
	cout << "(C)hainmail: For those looking for a taste of the Medieval in this honourable" << endl << "\tarena." << endl;
	cout << "(P)latemail: I'M A MANLY MAN, LOOK AT MY PLATEMAIL" << endl;
	cout << "(N)aked: Extreme intimidation to the extreme!!!!1!!11!1!!!" << endl << endl;

	cout << "Now, ANOTHER STAT TABLE" << endl;
	cout << "\t\tLeather\tChainmail\tPlatemail\tNaked" << endl;
	cout << "Protection:\t1\t3\t5\t0" << endl;
	cout << "Modifier:\t0\t-1\t-2\t-2 (from opponents attacking you)" << endl;

	char armour = 'G';
	while(armour != 'L' && armour != 'C' && armour != 'P' && armour != 'N'){
		cout << "Choose: ";
		cin >> armour;
	}


	switch(armour) {
	case 'L':
		this->SetDefender(new Armour("Leather", 1, 0));
		break;
	case 'C':
		this->SetDefender(new Armour("Chainmail", 3, -1));
		break;
	case 'P':
		this->SetDefender(new Armour("Platemail", 5, -2));
		break;
	case 'N':
		this->SetDefender(new Armour("Naked", 0, 2));
		break;
	}

	

	return;
}

void Player::ChooseWeapon() {
	cout << "Choose your weapon for this most glorious battle." << endl;
	cout << "(R)apier: Quick as a fox, but rather weak." << endl;
	cout << "(B)roadsword: More hacking than slashing, runs the middle ground." << endl;
	cout << "Battle(A)xe: AND MY AXE!" << endl << endl;

	cout << "Last stat table, I think." << endl;
	cout << "\t\tRapier\tBroadsword\tBattleAxe" << endl;
	cout << "Speed:\t6\t5\t4" << endl;
	cout << "Strength:\t2\t4\t6" << endl << endl;

	char weapons = 'G';
	while(weapons != 'R' && weapons != 'B' && weapons != 'A') {
		cout << "Choose your tool of death! ";
		cin >> weapons;
	}

	switch(weapons) {
	case 'R':
		this->SetAttacker(new Weapon("Rapier", 6, 2));
		break;
	case 'B':
		this->SetAttacker(new Weapon("Broadsword", 5, 4));
		break;
	case 'A':
		this->SetAttacker(new Weapon("BattleAxe", 4, 6));
		break;
	}

	return;
}

void Player::ChooseItems() {
	int random;

	cout << "It's SUPER AWESOME ITEM TIME!" << endl;
	cout << "1) Choose your own awesome items" << endl;
	cout << "2) Let the computer coose for you" << endl;

	cin >> random;

	if(random == 2) {
		this->RandomItems();
		return;
	}

	char item;

	for(int i = 3; i > 0; i--) {
		cout << "You have " << i << " items left to choose." << endl << endl;
		cout << "(S)teroids: MEGA AWESOME for one turn" << endl;
		cout << "(P)orn Magazine: Drop on the ground to distract your enemies with scantally clad women" << endl;
		cout << "(B)ow with 5 arrows" << endl;
		cout << "(T)eleporter" << endl;
		cout << "(M)edkit: Adds 5 to your current health" << endl;
		cout << "(D)ead carcasses: Lug them around for maximum intimidation" << endl << endl;
		cout << "Choose: ";
		cin >> item;
		
		switch(item) {
		case 'S':
			this->Equip.push_back(new Steroids());
			break;
		case 'P':
			this->Equip.push_back(new PornMag());
			break;
		case 'B':
			this->Equip.push_back(new Bow());
			break;
		case 'T':
			this->Equip.push_back(new Teleporter());
			break;
		case 'M':
			this->Equip.push_back(new Medkit());
			break;
		case 'D':
			this->Equip.push_back(new Carcass());
			break;
		default:
			i++;
			break;
		}
	}
}

	void Player::MoveDown() {
		this->Location->SetY(this->Location->GetY()-1);
		return;
	}

	void Player::MoveUp() {
		this->Location->SetY(this->Location->GetY()+1);
		return;
	}

	void Player::MoveLeft() {
		this->Location->SetX(this->Location->GetX()-1);
		return;
	}

	void Player::MoveRight() {
		this->Location->SetX(this->Location->GetX()+1);
		return;
	}

	void Player::Dead() {
		if(Alive) {
			gui->printLog(this->GetName() + " has run out of health and died a cowardly death. Begone to the underworld, vile one!");
			Alive = false;
		}
	}

	bool Player::isAlive() {
		return Alive;
	}

	void Player::RandomItems() {

		int item;

		for(int i = 0; i < 3; i++) {
			item = rand() % 6;
			switch (item) {
			case 0:
				this->Equip.push_back(new Bow);
				break;
			case 1:
				this->Equip.push_back(new Carcass);
				break;
			case 2:
				this->Equip.push_back(new Medkit);
				break;
			case 3:
				this->Equip.push_back(new PornMag);
				break;
			case 4:
				this->Equip.push_back(new Steroids);
				break;
			case 5:
				this->Equip.push_back(new Teleporter);
				break;
			}
		}

	}

	bool Player::isAwesome() {
		return this->Roids;
	}

	void Player::SetAwesome(bool awesome) {
		this->Roids = awesome;
		return;
	}

	void Player::AddItem(Item *newItem, Gui *gui) {
		
	}

	vector<Item *> Player::GetEquip() {
		return this->Equip;
	}
