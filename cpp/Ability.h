#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Ability
{
private:
	string mName;
	string mType;
	int mDamages;
	int mEnergy;

public:
	Ability();
	Ability(string name, string type, int damages, int energy);
	string GetName();
	string GetType();
	int GetDamages();
	int GetEnergy();
	void SetEnergy(int energy);
};

