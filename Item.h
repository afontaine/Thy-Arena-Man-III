#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {
private:
	string Name;
	int Effect;

public:
	Item(string name, int effect);
	~Item();

	string GetName();
	void SetName(string name);

	int GetEffect();
	void SetEffect(int effect);
}