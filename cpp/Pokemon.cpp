#include "Pokemon.h"

Pokemon::Pokemon(string name, string description, string type, int level, int lifepoints, bool inPokeball, Ability ability1, Ability ability2, Ability ability3, Ability ability4) {
	mName = name;
	mDescription = description;
	mType = type;
	mLevel = level;
	mLifepoints = lifepoints;
	mAbility1 = ability1;
	mAbility2 = ability2;
	mAbility3 = ability3;
	mAbility3 = ability4;
	mInPokeball = inPokeball;
}
Pokemon::~Pokemon(){}

string Pokemon::GetName() { return mName; }
string Pokemon::GetDescription() { return mDescription; }
string Pokemon::GetType() { return mType; }
int Pokemon::GetLevel() { return mLevel; }
int Pokemon::GetLifepoints() { return mLifepoints; }
vector<Ability> Pokemon::GetAbilities() { return { mAbility1, mAbility2, mAbility3, mAbility4 }; }
bool Pokemon::GetInPokeball() { return mInPokeball; }
void Pokemon::AddAbility(Ability ability, int slot) {
	if (slot == 1) {
		mAbility1 = ability;
	}
	else if (slot == 2) {
		mAbility2 = ability;
	}
	else if (slot == 3) {
		mAbility3 = ability;
	}
	else if (slot == 4) {
		mAbility4 = ability;
	}
}
void Pokemon::SetLifepoints(int lifepoints) { mLifepoints = lifepoints; }
void Pokemon::SetInPokeball(int inPokeball) { mInPokeball = inPokeball; }
