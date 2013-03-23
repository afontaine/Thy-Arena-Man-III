#ifndef MEDKIT_H
#define MEDKIT_H

#include <string>

class Item;
class Player;

class Medkit : public Item {
public:
	Medkit();
	~Medkit();

	void Use(Player *player);
};

#endif