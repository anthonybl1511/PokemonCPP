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

string Trainer::GetFirstName() { return mFirstName; }
string Trainer::GetLastName() { return mLastName; }
string Trainer::Introduce() { return mCatchphrase; }
int Trainer::GetMoney() { return mMoney; }
int Trainer::GetPokeballs() { return mPokeballs; }
vector<Pokemon> Trainer::GetPokemons() { return { mPokemon1, mPokemon2, mPokemon3, mPokemon4, mPokemon5, mPokemon6 }; }
void Trainer::AddPokemon(Pokemon pokemon, int slot) {
	if (slot == 1) {
		mPokemon1 = pokemon;
	}
	else if (slot == 2) {
		mPokemon2 = pokemon;
	}
	else if (slot == 3) {
		mPokemon3 = pokemon;
	}
	else if (slot == 4) {
		mPokemon4 = pokemon;
	}
	else if (slot == 5) {
		mPokemon5 = pokemon;
	}
	else if (slot == 6) {
		mPokemon6 = pokemon;
	}
}
void Trainer::SetMoney(int money) { mMoney = money; }
void Trainer::SetPokeballs(int pokeballs) { mPokeballs = pokeballs; }
void Trainer::CapturePokemon(Pokemon pokemon) {
	if (pokemon.GetLifepoints() < 50) {
		mPokeballs -= 1;
		
		cout << "Which slot? (1-6)\n";
		int slot;
		cin >> slot;
		AddPokemon(pokemon, slot);
	}
}
