#include "Ability.h"

Ability::Ability(string name, TypeEnum type, int damages, int energy) {
	mName = name;
	mType = type;
	mDamages = damages;
	mEnergy = energy;
}

string Ability::GetName() { return mName; }
TypeEnum Ability::GetType() { return mType; }
int Ability::GetDamages() { return mDamages; }
int Ability::GetEnergy() { return mEnergy; }
void Ability::SetEnergy(int energy) { mEnergy = energy; }
