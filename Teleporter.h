#ifndef TELEPORTER_H_
#define TELEPORTER_H_


class Item;
class Player;

class Teleporter : public Item {
public:
	Teleporter();
	~Teleporter();

	void Use(Player *player);
};

#endif