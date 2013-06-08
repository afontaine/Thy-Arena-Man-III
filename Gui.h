#ifndef GUI_H_
#define GUI_H_

#include <string>
#include <vector>
#include <curses.h>

class Player;

// Contained in Window.cpp, wrapper for curses windows
class Window {
private:
	int Width;
	int Height;
	WINDOW *window;

public:
	Window(int height, int width, int posY, int posX);
	~Window();
	
	WINDOW *getWindow();
	void setWindow(WINDOW *newWindow);

	int getHeight();
	void setHeight(int newHeight);

	int getWidth();
	void setWidth(int newWidth);
	


};

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

	void printMenu(const std::string message);

	void updateArena(const std::vector<Player *> players);

	void updateStatus(const Player *player);

	void drawCompass();

	void updateInventory(const Player *player);

	void updatePlayerandInventory(const Player *player);
};

#endif