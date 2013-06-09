#include <curses.h>
#include <string>
#include "Gui.h"
#include "Player.h"

using namespace std;

Gui::Gui() {
	initscr();
	refresh();
	resize_term(25, 80);
	curs_set(0);

	this->Arena = new Window(7, 13, 0, 0);
	this->Compass = new Window(7, 13, 7, 0);
	this->Menu = new Window(11, 80, 14, 0);
	this->Status = new Window(7, 33, 7, 13);
	this->Inventory = new Window(7, 34, 7, 46);
	this->Log = new Window(7, 67, 0, 13);

	refresh();

	box(this->Arena->getWindow(), 0, 0);
	wrefresh(this->Arena->getWindow());

	box(this->Compass->getWindow(), 0, 0);
	wrefresh(this->Compass->getWindow());

	box(this->Menu->getWindow(), 0, 0);
	wmove(this->Menu->getWindow(), 1, 1);
	wrefresh(this->Menu->getWindow());

	box(this->Inventory->getWindow(), 0, 0);
	wrefresh(this->Inventory->getWindow());

	box(this->Status->getWindow(), 0, 0);
	wrefresh(this->Status->getWindow());

	box(this->Log->getWindow(), 0, 0);
	wrefresh(this->Log->getWindow());
	wgetch(this->Menu->getWindow());
	
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

void Gui::printMenu(const string message) {
	WINDOW *menu = this->Menu->getWindow();
	wrefresh(menu);
	if(message.length() < 78)
		mvwprintw(menu, 1, 1, message.c_str());
	else {
		int line = 1;
		unsigned int charac = 0;
		int length = 78;
		while(charac < message.length()) {
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

	wmove(status, 1, 1);
	wclrtoeol(status);
	wprintw(status, player->GetName().c_str());
	
	wmove(status, 2, 1);
	wclrtoeol(status);
	wprintw(status, "\tLocation:\t%d,%d", player->GetLocation()->GetX(),player->GetLocation()->GetY());

	wmove(status, 3, 1);
	wclrtoeol(status);
	wprintw(status, "\tHealth:\t\t %02d", player->GetHealth());
	
	wmove(status, 4, 1);
	wclrtoeol(status);
	wprintw(status, "\tSkill:\t\t %02d", player->GetSkill());

	wmove(status, 5, 1);
	wclrtoeol(status);
	wprintw(status, "\tStrength:\t %02d", player->GetStrength());

	box(status, 0, 0);

	wrefresh(status);
}

void Gui::updateArena(std::vector<Player *> players) {
	WINDOW *arena = this->Arena->getWindow();

	for(int i = 1; i < 5; i++) {
		wmove(arena, i, 1);
		wclrtoeol(arena);
	}

	for(vector<Player *>::iterator it = players.begin(); it!= players.end(); it++) {
		mvwaddch(arena, it[0]->GetLocation()->GetY(), it[0]->GetLocation()->GetX(), it[0]->GetName().c_str()[0]);
	}

	box(arena, 0, 0);

	wrefresh(arena);

}