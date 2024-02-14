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
	vector<Pokemon> Pokemons;
	int mPokemonInBattle;

public:
	Trainer(string firstName, string lastName, string catchphrase, int money, int pokeballs, vector<Pokemon> newPokemons);
	string GetFirstName();
	string GetLastName();
	string Introduce();
	int GetMoney();
	int GetPokeballs();
	vector<Pokemon> GetPokemons();
	Pokemon& GetPokemonInBattle();
	void AddPokemon(Pokemon pokemon);
	void SetMoney(int money);
	void SetPokeballs(int pokeballs);
	void ChallengeTrainer(Trainer& trainer);
	void ChallengePokemon(Pokemon pokemon);
	void SetPokemonInBattle(int pokemon);
};

