#include <vector>
#include <iostream>

#include "../Header/Main.h"

using namespace std;

Gui *gui;

int main() {
	Player *test = new Player("Andrew", 0);
	//Player *test2 = new Player("Jacob");
	//test2->SetLocation(2, 2);
	vector<Player *> players;
	players.push_back(test);
	//players.push_back(test2);
	gui = new Gui();
	gui->drawCompass();
	gui->updateStatus(test);
	gui->updateArena(players);
	gui->updateInventory(test);
	gui->printLog("Jacob just layed a porn mag! Watch out!");
	gui->printMenu("What do you want to do? Well... what's it going to be, punk?");
	gui->getMenu();
	delete gui;
	return 0;
}

int realMain() {
	int play;
	cout << "Welcome, peasants and kings, to THY ARENA MAN III!" << endl;
	cout << "Enter thy glorious arena, and pit thee against thine foes!" << endl;
	cout << "Thoust may enter 1 to play, or 2 to leave whimpering! ";
	cin >> play;
	if (play != 1) {
		cout << "Coward!" << endl;
		cin >> play;
		exit 0;
	}
	cout << "Thout shall not regret thine choice!" << endl;
	Game *thyArnea = new Game();


}