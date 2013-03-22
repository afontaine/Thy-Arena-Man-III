#ifndef STEROIDS_H_
#define STEROIDS_H_

class Item;
class Player;

class Steroids : public Item { // Not entirely sure how I'm going to do this one.
private:
	bool Used;

public:
	bool isUsed();
	void Use(Player *player);

};

#endif