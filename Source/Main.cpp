#include <vector>

#include "../Header/Main.h"

using namespace std;

Gui *gui;

int main() {
	Player *test = new Player("Andrew");
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
	return 0;
}
