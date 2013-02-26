#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Player.h"

using namespace std;

class Game {
private:
	int width;
	int height;
	vector<Player *> players;

public:
	Game();
	~Game();
	void SetWidth(int w);
	int GetWidth();

	void SetHeight(int h);
	int GetHeight();

	Player *GetPlayer(int i);
	Player *GetPlayer(string name);
	void SetPlayer(int i, Player *p);	
	void addPlayer(Player * p);
	Player *deletePlayer(int i);
	Player *deletePlayer(string name);

};
#endif