#ifndef BOW_H
#define BOW_H

#include <string>
#include "Player.h"
#include "Item.h"

class Bow : public Item {
private:
	int Arrows;

public:
	Bow();
	~Bow();

	void SetArrows(int arrows);
	int GetArrows();

	void Use(Player *player);
}
#endif