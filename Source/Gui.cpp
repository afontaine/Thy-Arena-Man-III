#include "../Header/curses.h"
#include <string>
#include <vector>
#include "../Header/Gui.h"
#include "../Header/Window.h"
#include "../Header/Player.h"
#include "../Header/Item.h"

using namespace std;

Gui::Gui() {
	initscr();
	refresh();
	resize_term(25, 80);
	noecho();
	cbreak();
	leaveok(stdscr, TRUE);
	
	this->Arena = new Window(7, 14, 0, 0);
	this->Compass = new Window(7, 14, 7, 0);
	this->Menu = new Window(11, 80, 14, 0);
	this->Status = new Window(7, 32, 7, 14);
	this->Inventory = new Window(7, 34, 7, 46);
	this->Log = new Window(7, 66, 0, 14);

	refresh();
	
	leaveok(this->Arena->getWindow(), TRUE);
	box(this->Arena->getWindow(), 0, 0);
	wrefresh(this->Arena->getWindow());

	leaveok(this->Compass->getWindow(), TRUE);
	box(this->Compass->getWindow(), 0, 0);
	wrefresh(this->Compass->getWindow());

	box(this->Menu->getWindow(), 0, 0);
	wmove(this->Menu->getWindow(), 1, 1);
	scrollok(this->Menu->getWindow(), TRUE);
	wechochar(this->Menu->getWindow(), TRUE);
	wrefresh(this->Menu->getWindow());

	leaveok(this->Inventory->getWindow(), TRUE);
	box(this->Inventory->getWindow(), 0, 0);
	wrefresh(this->Inventory->getWindow());

	leaveok(this->Status->getWindow(), TRUE);
	box(this->Status->getWindow(), 0, 0);
	wrefresh(this->Status->getWindow());

	leaveok(this->Log->getWindow(), TRUE);
	box(this->Log->getWindow(), 0, 0);
	wrefresh(this->Log->getWindow());
	scrollok(this->Log->getWindow(), TRUE);

	curs_set(2);
	
}

Gui::~Gui() {
	delete this->Log;
	delete this->Status;
	delete this->Inventory;
	delete this->Arena;
	delete this->Compass;
	delete this->Menu;

	endwin();
}

Window *Gui::getArena() {
	return this->Arena;
}

void Gui::drawCompass() {
	WINDOW *compass = this->Compass->getWindow();
	mvwaddch(compass, 1, 6,'8');
	mvwaddch(compass, 2, 6, '|');
	mvwaddch(compass, 3, 6,'5');
	mvwaddch(compass, 4, 6, '|');
	mvwaddch(compass, 5, 6,'2');
	mvwaddch(compass, 3, 1,'4');
	mvwaddch(compass, 3, 2, '-');
	mvwaddch(compass, 3, 3,'-');
	mvwaddch(compass, 3, 4,'-');
	mvwaddch(compass, 3, 5,'-');
	mvwaddch(compass, 3, 7,'-');
	mvwaddch(compass, 3, 8,'-');
	mvwaddch(compass, 3, 9,'-');
	mvwaddch(compass, 3, 10, '-');
	mvwaddch(compass, 3, 11,'6');
	wrefresh(compass);
}

void Gui::printMenu(string message) {
	message.append(" ");
	WINDOW *menu = this->Menu->getWindow();
	wclear(menu);
	box(menu, 0, 0);
	wrefresh(menu);
	if(message.length() < 78)
		mvwprintw(menu, 1, 1, message.c_str());
	else {
		int line = 1;
		unsigned int charac = 0;
		int length = 78;
		while(charac < message.length()) {
			if(line >= 10) {
				mvwprintw(menu, line, 1, "Press any key to continue...");
				wrefresh(menu);
				getch();
				scroll(menu);
				wmove(menu, 9, 1);
				wclrtoeol(menu);
				box(menu, 0, 0);
				wrefresh(menu);
				line--;
			}
			if(charac + length < message.length())
				while(message.at(charac + length) != ' ' && length >=0) {length--;}
			if(length == 0)
				length = 78;
			mvwprintw(menu, line, 1, message.substr(charac, length).c_str());
			line++;
			charac += length + 1;
			length = 78;
			wrefresh(menu);
		}
	}
	wrefresh(menu);
}

void Gui::updateStatus(Player *player) {
	WINDOW *status = this->Status->getWindow();

	wclear(status);

	
	mvwprintw(status, 1, 1, player->GetName().c_str());
	
	mvwprintw(status, 2, 1, "\tLocation:\t%d,%d", player->GetLocation()->GetX(),player->GetLocation()->GetY());

	mvwprintw(status, 3, 1, "\tHealth:\t\t %02d", player->GetHealth());
	
	mvwprintw(status, 4, 1, "\tSkill:\t\t %02d", player->GetSkill());

	mvwprintw(status, 5, 1, "\tStrength:\t %02d", player->GetStrength());

	box(status, 0, 0);

	wrefresh(status);
}

void Gui::updateArena(std::vector<Player *> players) {
	WINDOW *arena = this->Arena->getWindow();

	wclear(arena);

	for(vector<Player *>::iterator it = players.begin(); it!= players.end(); it++) {
		mvwaddch(arena, it[0]->GetLocation()->GetY(), it[0]->GetLocation()->GetX(), it[0]->GetName().c_str()[0]);
	}

	box(arena, 0, 0);

	wrefresh(arena);

}


//TODO: Create line length macro
void Gui::printLog(const string message) {
	WINDOW *log = this->Log->getWindow();
	unsigned int charac = 0;
	int length = 65;
	while(charac < message.length()) {
		scroll(log);
		wmove(log, 5, 1);
		wclrtoeol(log);
		box(log, 0, 0);
		if(charac + length < message.length())
				while(message
					.at(charac + length) != ' ' && length >=0) {length--;}
		mvwprintw(log, 5, 1, message.substr(charac, length).c_str());
		charac += length + 1;
		length = 65;
		wrefresh(log);
	}
}

void Gui::updateInventory(Player *player) {
	WINDOW *inv = this->Inventory->getWindow();

	wclear(inv);
	box(inv, 0, 0);

	mvwprintw(inv, 1, 1, "Items");
	int control;
	for(unsigned int i = 0; i < player->GetEquip().size(); i++) {
		switch (i) {
		case 0:
			control = 1;
			break;
		case 1:
			control = 3;
			break;
		case 2:
			control = 7;
			break;
		}
		mvwprintw(inv, i+2, 1, "\t%i - %s", control, player->GetEquip().at(i)->GetName().c_str());
	}
	wrefresh(inv);
}

void Gui::updatePlayerandInventory(Player *player) {
	this->updateStatus(player);
	this->updateInventory(player);
}

char Gui::getMenu() {
	echo();
	nocbreak();
	WINDOW *menu = this->Menu->getWindow();
	int input = wgetch(menu);
	char selection = (char) input;
	noecho();
	cbreak();
	return selection;
}