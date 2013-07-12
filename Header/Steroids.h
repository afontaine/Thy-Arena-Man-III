#ifndef STEROIDS_H_
#define STEROIDS_H_

class Item;
class Player;

class Steroids : public Item { // Not entirely sure how I'm going to do this one.

public:
	Steroids();
	~Steroids();

	void Use(Player *player);

};

#endif
