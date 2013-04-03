#include <string>

class Player;
class Item;

class Carcass : public Item {
private:
	int Effect;

public:
	Carcass();
	~Carcass();

	void Use(Player *player);

	int GetEffect();
	void SetEffect(int effect);

};