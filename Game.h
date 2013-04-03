#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

class Player;

class Game {
private:
	int width;
	int height;
	std::vector<Player *> players;

public:
	Game();
	~Game();
	void SetWidth(int w);
	int GetWidth();

	void SetHeight(int h);
	int GetHeight();

	Player *GetPlayer(int i);
	Player *GetPlayer(std::string name);
	void SetPlayer(int i, Player *p);	
	void addPlayer(Player * p);
	Player *deletePlayer(int i);
	Player *deletePlayer(std::string name);

	void printArena();

};
#endif