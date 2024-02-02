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
	string mType;
	int mLevel;
	int mLifepoints;
	Ability mAbility1;
	Ability mAbility2;
	Ability mAbility3;
	Ability mAbility4;

public:
	Pokemon(string name, string description, string type, int level, int lifepoints, Ability ability1, Ability ability2, Ability ability3, Ability ability4);
	~Pokemon();
	string GetName();
	string GetDescription();
	string GetType();
	int GetLevel();
	int GetLifepoints();
	vector<Ability> GetAbilities();
	void AddAbility(Ability ability, int slot);
	void SetLifepoints(int newLifepoints);
};

