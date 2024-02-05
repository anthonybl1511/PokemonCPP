#pragma once
#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Trainer
{
private:
	string mFirstName;
	string mLastName;
	string mCatchphrase;
	int mMoney;
	int mPokeballs;
	Pokemon mPokemon1;
	Pokemon mPokemon2;
	Pokemon mPokemon3;
	Pokemon mPokemon4;
	Pokemon mPokemon5;
	Pokemon mPokemon6;
	Pokemon mPokemonInBattle;

public:
	Trainer(string firstName, string lastName, string catchphrase, int money, int pokeballs, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3, Pokemon pokemon4, Pokemon pokemon5, Pokemon pokemon6);
	~Trainer();
	string GetFirstName();
	string GetLastName();
	string Introduce();
	int GetMoney();
	int GetPokeballs();
	vector<Pokemon> GetPokemons();
	Pokemon GetPokemonInBattle();
	void AddPokemon(Pokemon pokemon, int slot);
	void SetMoney(int money);
	void SetPokeballs(int pokeballs);
	void ChallengeTrainer(Trainer trainer);
	void CapturePokemon(Pokemon pokemon);
	void SetPokemonInBattle(Pokemon pokemon);
};

