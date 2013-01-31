#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Game.h"

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
