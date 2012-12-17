#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"

using namespace std;

Player::Player(string name) {

	this->SetName(name);
	
	this->ChooseAi();

	this->ChooseClass();

	this->ChooseArmour();

	this->ChooseWeapon();

}

Player::~Player() {
	delete this->Weapon;
	delete this->Armour;
	std::vector<Item *>::iterator Iterate;
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

Equipment Player::GetArmour() {
	return this->Armour;
}

void Player::SetArmour(Equipment armour) {
	delete this->Armour;
	this->Armour = armour;
	return;
}

Equipment Player::GetWeapon() {
	return this->Weapon;
}

void Player::SetWeapon(Equipment weapon) {
	this->Weapon = weapon;
	return;
}

void Player::Randomize(){}

void Player::ChooseClass() {
	cout << this->Name << ", CHOOSE YOUR CLASS!" << endl;
	cout << "(R)ougue class: Attack twice every 5 moves" << endl;
	cout << "(S)oldier class: Stay still and attack, receive a stat boost" << endl;
	cout << "(B)erzerker class: Become MEGA AWESOME every 5 moves" << endl << endl;

	cout << "Here's a stat table so you can make your ultimate decision:" << endl;
	cout << "\t\tRougue\tSoldier\tBerzerker" << endl;
	cout << "Skill:\t20\t19\t18" << endl;
	cout << "Strength:\t8\t9\t10" << endl;
	cout << "Health:\t20\t20\t20" << endl << endl;

	cout << "CHOOOSE! ";

	char Class;
	cin >> Class;

	this->SetClass(Class);

	cout << "Awesome, you're a motherfucking " << this->GetClass() << "!" << endl;
}

void Player::ChooseAi() {
	int ai;
	cout << "Are you an AI?" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	
	cin >> ai;
	
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
	cout << "(C)hainmail: For those looking for a taste of the Medieval in this honourable arena." << endl;
	cout << "(P)latemail: I'M A MANLY MAN, LOOK AT MY PLATEMAIL" << endl;
	cout << "(N)aked: Extreme intimidation to the extreme!!!!1!!11!1!!!" << endl << endl;

	cout << "Now, ANOTHER STAT TABLE" << endl;
	cout << "\t\tLeather\tChainmail\tPlatemail\tNaked" << endl;
	cout << "Protection:\t1\t3\t5\t0" << endl;
	cout << "Modifier:\t0\t-1\t-2\t-2 (from opponents attacking you)" << endl;

	char armour;
	cout << "Choose: ";
	cin >> armour;

	Equipment *newArmour;

	switch(armour) {
	case 'L':
		newArmour = new Armour("Leather");
		break;
	case 'C':
		newArmour = new Armour("Chainmail");
		break;
	case 'P':
		newArmour = new Armour("Platemail");
		break;
	case 'N':
		newArmour = new Armour("Naked");
		break
	}

	this->SetArmour(newArmour);

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

	char weapons;
	cout << "Choose your tool of death! ";
	cin >> weapons;

	Equipment *weapon;

	switch(weapons) {
	case 'R':
		weapon = new Weapon("Rapier");
		break;
	case 'B':
		weapon = new Weapon("Broadsword");
		break;
	case 'A':
		weapon = new Weapon("BattleAxe");
		break;
	}

	this->SetWeapon(weapon);

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
		Equip.push_back(new Item(item));
	}