#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;

class Item {

protected:
	std::string Name;

public:
	Item(std::string name);
	~Item();

	std::string GetName();
	void SetName(std::string name);

	virtual void Use(Player *player);
};


#endif