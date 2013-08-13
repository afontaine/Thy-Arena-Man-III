#ifndef GUI_H_
#define GUI_H_

#include <string>
#include <vector>
#include <curses.h>

class Player;
class Window;

// Contained in Gui.cpp, manages entire GUI.
class Gui {
private:
	Window *Menu;
	Window *Arena;
	Window *Inventory;
	Window *Status;
	Window *Compass;
	Window *Log;

public:
	Gui();
	~Gui();

	Window *getArena();

	void printMenu(const std::string message);

	void updateArena(std::vector<Player *> players);

	void updateStatus(Player *player);

	void drawCompass();

	void updateInventory(Player *player);

	void updatePlayerandInventory(Player *player);

	void printLog(const std::string message);

	char getMenu();
};


#endif