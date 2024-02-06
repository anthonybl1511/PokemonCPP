#pragma once
#include <iostream>
#include <vector>
#include "Ability.h"

using namespace std;

class Pokemon
{
private:
	string mName;
	string mDescription;
	TypeEnum mType;
	int mLevel;
	int mLifepoints;
	Ability mAbility1;
	Ability mAbility2;
	Ability mAbility3;
	Ability mAbility4;

public:
	Pokemon();
	Pokemon(string name, string description, TypeEnum type, int level, int lifepoints, Ability ability1, Ability ability2, Ability ability3, Ability ability4);
	~Pokemon();
	string GetName();
	string GetDescription();
	TypeEnum GetType();
	int GetLevel();
	int GetLifepoints();
	vector<Ability> GetAbilities();
	void AddAbility(Ability ability, int slot);
	void SetLifepoints(int lifepoints);
	void UseAbility(int slot, Pokemon pokemon);
	void Rest();
};

