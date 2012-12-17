#include <string>
#include "Item.h"

using namespace std;

Item::Item(string name, int effect) {
	this->Name = name;
	this->Effect = effect;
}

Item::~Item(){
}

int Item::GetEffect() {
	return this->Effect;
}

void Item::SetEffect(int effect) {
	this->Effect = effect;
	return;
}

string Item::GetName(){
	return this->Name;
}

void Item::SetName(string name){
	this->Name = name;
	return;
}