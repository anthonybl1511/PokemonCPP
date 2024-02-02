#include "Ability.h"

Ability::Ability(string name, string description, string type, int damages) {
	mName = name;
	mDescription = description;
	mType = type;
	mDamages = damages;
}

string Ability::GetName() { return mName; }
string Ability::GetDescription() { return mDescription; }
string Ability::GetType() { return mType; }
int Ability::GetDamages() { return mDamages; }
