
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Player.h"
#include "Game.h"
#include "Gui.h"

using namespace std;
// TODO: Implement constructor/destructor (start game/finish game)
Game::Game() {}

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
	insert_iterator<vector<Player *>> insert_it(this->players, it);
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
	*play = *(this->players[i]);
	if(play != NULL)
		this->players.erase(it);
	return play;
}

Player *Game::deletePlayer(string name) {
	Player *play;
	for(vector<Player *>::iterator it = this->players.begin(); it!=this->players.end(); it++) {
		if(it[0]->GetName() == name) {
			play = NULL;
			*play = *(it[0]);
			if(play != NULL)
				this->players.erase(it);
			return play;
		}
	}
	return NULL;
}

void Game::printArena() {
	}

int main() {
	Gui *gui = new Gui();
	gui->drawCompass();
	gui->printMenu("This message is well over 79 characters long and should be a decent test of my little function. This message is well over 79 characters long and should be a decent test of my little function. This message is well over 79 characters long and should be a decent test of my little function.");
	getch();
	return 0;
}