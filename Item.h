#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {

protected:
	string Name;

public:
	Item(string name);
	~Item();

	string GetName();
	void SetName(string name);

	virtual void Use(Player *player) = 0;
}


#endif