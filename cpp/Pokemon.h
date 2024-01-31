#pragma once
#include <iostream>

using namespace std;

class Pokemon
{
private:
	string mName;
	string mDescription;
	string mGenre;
	string mType;
	float mSize;
	float mWeight;
	int mLifepoints;

public:
	Pokemon(string name, string description, string genre, string type, float size, float weight, int lifepoints);
	~Pokemon();
	string GetName();
	string GetDescription();
	string GetGenre();
	string GetType();
	float GetSize();
	float GetWeight();
	int GetLifepoints();
	void SetName(string newName);
	void SetLifepoints(int newLifepoints);
};

