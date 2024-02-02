#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Ability
{
private:
	string mName;
	string mDescription;
	string mType;
	int mDamages;

public:
	Ability(string name, string description, string type, int damages);
	string GetName();
	string GetDescription();
	string GetType();
	int GetDamages();
};

