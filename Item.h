#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {

protected:
	string Name;
	int Effect;

public:
	Item(string name, int effect);
	~Item();

	string GetName();
	void SetName(string name);

	int GetEffect();
	void SetEffect(int effect);

	abstract void Use(Player *player);
}


#endif