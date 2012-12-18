#include <string>
#include "Item.h"

using namespace std;

Item::Item(string name, int effect) {
	this->Name = name;
}

Item::~Item(){
}

string Item::GetName(){
	return this->Name;
}

void Item::SetName(string name){
	this->Name = name;
	return;
}