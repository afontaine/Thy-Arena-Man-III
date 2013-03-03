#ifndef TELEPORTER_H_
#define TELEPORTER_H_

#include "Item.h"


class Teleporter : public Item {
public:
	Teleporter();
	~Teleporter();

	void Use(Player *player);
}

#endif