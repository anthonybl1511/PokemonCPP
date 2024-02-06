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
	Ability();
	Ability(string name, TypeEnum type, int damages, int energy);
	string GetName();
	TypeEnum GetType();
	int GetDamages();
	int GetEnergy();
	void SetEnergy(int energy);
};

