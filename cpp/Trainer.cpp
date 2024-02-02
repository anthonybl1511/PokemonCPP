#include "Trainer.h"

Trainer::Trainer(string firstName, string lastName, string catchphrase, int money, int pokeballs, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3, Pokemon pokemon4, Pokemon pokemon5, Pokemon pokemon6) {
	mFirstName = firstName;
	mLastName = lastName;
	mCatchphrase = catchphrase;
	mMoney = money;
	mPokeballs = pokeballs;
	mPokemon1 = pokemon1;
	mPokemon2 = pokemon2;
	mPokemon3 = pokemon3;
	mPokemon4 = pokemon4;
	mPokemon5 = pokemon5;
	mPokemon6 = pokemon6;
}
Trainer::~Trainer() {}

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
