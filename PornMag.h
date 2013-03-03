#ifndef PORNMAG_H_
#define PORNMAG_H_

#include <string>
#include "Item.h"
#include "Player.h"

class PornMag : public Item {
private:
	Point *Location;
	bool Dropped;

public:
	PornMag();
	~PornMag();

	Point *GetLocation();
	void SetLocation(int x, int y);
	void SetLocation(Point *location);

	bool isDropped();

	void Use(Player *player);

}


#endif