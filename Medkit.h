#ifndef MEDKIT_H
#define MEDKIT_H

#include <string>
#include "Item.h"
#include "Player.h"

class Medkit : public Item {
public:
	Medkit();
	~Medkit();

	void Use(Player *player);
};

#endif