
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "../Header/Player.h"
#include "../Header/Game.h"
#include "../Header/Gui.h"

using namespace std;

extern  Gui* gui;

Game::Game() {
	int numOfPlayers = 0;
	
	cout << "Enter the number of RANDOM_NOUN to enter thy RANDOM_MATCHING_ADJECTIVE ARENA!" << endl;
	cout << "For legal reasons, this number must be between 2 and 4" << endl;
	cin >> numOfPlayers;
	while (numOfPlayers < 2 || numOfPlayers > 4) {
		cout << "ATTEMPT AGAIN! ";
		cin >> numOfPlayers;
	}

	string name;

	for(int i = 0; i < numOfPlayers; i++) {
		cout << "RANDOM_NOUN " << i + 1 <<", please add your name to the Scroll of the Damned!" << endl;
		cin >> name;

		while(name.length() < 1) {
			cout << "THAT'S NOT A NAME!" << endl;
			cin >> name;
		}
		players.push_back(new Player(name, i));
		name = "";
	}

	cout << "All players are ready! Enter THY ARENA MAN III!" << endl;
	cin >> name;

	gui = new Gui();

}

Game::~Game() {}

void Game::SetHeight(int h) {
	this->height = h;
}

int Game::GetHeight() {
	return this->height;
}

void Game::SetWidth(int w) {
	this->width = w;
	return;
}

Player *Game::GetPlayer(int i) {
	return this->players[i];
}

Player *Game::GetPlayer(string name) {
	for(vector<Player *>::iterator it = this->players.begin(); it != this->players.end(); ++it)
		if((*it)->GetName() == name) {
			return *it;
		}
	return NULL;
}

void Game::SetPlayer(int i, Player *p) {
	vector<Player *>::iterator it;
	it = this->players.begin(); advance(it, i);
	this->players.insert(it, p);
}

void Game::addPlayer(Player *p) {
	this->players.push_back(p);
	return;
}

Player *Game::deletePlayer(int i) {
	vector<Player *>::iterator it = this->players.begin();
	advance(it, i);
	Player *play = NULL;
	play = (it[i]);
	if(play != NULL)
		this->players.erase(it);
	return play;
}

Player *Game::deletePlayer(string name) {
	Player *play;
	for(vector<Player *>::iterator it = this->players.begin(); it!=this->players.end(); it++) {
		if(it[0]->GetName() == name) {
			play = NULL;
			play = (it[0]);
			if(play != NULL)
				this->players.erase(it);
			return play;
		}
	}
	return NULL;
}

void Game::printArena() {
	}
