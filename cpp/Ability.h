#pragma once
#include <iostream>
#include <vector>
#include "TypeEnum.h"

using namespace std;

class Ability
{
private:
	string mName;
	TypeEnum mType;
	int mDamages;
	int mEnergy;

public:
	Ability(string name = "", TypeEnum type = TypeEnum::Fire, int damages = 0, int energy = 0);
	string GetName();
	TypeEnum GetType();
	int& GetDamages();
	int GetEnergy();
	void SetEnergy(int energy);
};

