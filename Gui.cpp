#include <curses.h>
#include <string>
#include "Gui.h"

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

