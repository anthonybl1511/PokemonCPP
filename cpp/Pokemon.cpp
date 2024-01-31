#include "Pokemon.h"

Pokemon::Pokemon(string name, string description, string genre, string type, float size, float weight, int lifepoints) {
	mName = name;
	mDescription = description;
	mGenre = genre;
	mType = type;
	mSize = size;
	mWeight = weight;
	mLifepoints = lifepoints;
}
Pokemon::~Pokemon(){}

string Pokemon::GetName() { return mName; }
string Pokemon::GetDescription() { return mDescription; }
string Pokemon::GetGenre() { return mGenre; }
string Pokemon::GetType() { return mType; }
float Pokemon::GetSize() { return mSize; }
float Pokemon::GetWeight() { return mWeight; }
int Pokemon::GetLifepoints() { return mLifepoints; }
void Pokemon::SetName(string newName) { mName = newName; }
void Pokemon::SetLifepoints(int newLifepoints) { mLifepoints = newLifepoints; }
