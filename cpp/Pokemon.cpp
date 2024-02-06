#include "Pokemon.h"

Pokemon::Pokemon(string name, string description, TypeEnum type, int level, int lifepoints, Ability ability1, Ability ability2, Ability ability3, Ability ability4) {
	mName = name;
	mDescription = description;
	mType = type;
	mLevel = level;
	mLifepoints = lifepoints;
	mAbility1 = ability1;
	mAbility2 = ability2;
	mAbility3 = ability3;
	mAbility3 = ability4;
}
Pokemon::~Pokemon(){}

string Pokemon::GetName() { return mName; }
string Pokemon::GetDescription() { return mDescription; }
TypeEnum Pokemon::GetType() { return mType; }
int Pokemon::GetLevel() { return mLevel; }
int Pokemon::GetLifepoints() { return mLifepoints; }
vector<Ability> Pokemon::GetAbilities() { return { mAbility1, mAbility2, mAbility3, mAbility4 }; }
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
void Pokemon::UseAbility(int slot, Pokemon pokemon) {
	if (slot == 1) {
		if (mAbility1.GetEnergy() > 0) {
			pokemon.SetLifepoints(pokemon.GetLifepoints() - mAbility1.GetDamages());
			mAbility1.SetEnergy(mAbility1.GetEnergy() - 1);
		}
		else {
			std::cout << "\nYour pokemon is axhausted and can't use this ability anymore. Nothing happens.";
		}
	}
	else if (slot == 2) {
		if (mAbility2.GetEnergy() > 0) {
			pokemon.SetLifepoints(pokemon.GetLifepoints() - mAbility2.GetDamages());
			mAbility2.SetEnergy(mAbility2.GetEnergy() - 1);
		}
		else {
			std::cout << "\nYour pokemon is axhausted and can't use this ability anymore. Nothing happens.";
		}
	}
	else if (slot == 3) {
		if (mAbility3.GetEnergy() > 0) {
			pokemon.SetLifepoints(pokemon.GetLifepoints() - mAbility3.GetDamages());
			mAbility3.SetEnergy(mAbility3.GetEnergy() - 1);
		}
		else {
			std::cout << "\nYour pokemon is axhausted and can't use this ability anymore. Nothing happens.";
		}
	}
	else if (slot == 4) {
		if (mAbility4.GetEnergy() > 0) {
			pokemon.SetLifepoints(pokemon.GetLifepoints() - mAbility4.GetDamages());
			mAbility4.SetEnergy(mAbility4.GetEnergy() - 1);
		}
		else {
			std::cout << "\nYour pokemon is axhausted and can't use this ability anymore. Nothing happens.";
		}
	}
};
void Pokemon::Rest() { 
	mLifepoints = 100; 
	for (Ability ability : GetAbilities())
	{
		ability.SetEnergy(5);
	}
}
