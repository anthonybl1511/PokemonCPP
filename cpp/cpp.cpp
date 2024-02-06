#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "TypeEnum.h"
#include "Ability.h"

using namespace std;

int main()
{
    vector<Ability> abilitiesList = { 
        {"", TypeEnum::Electric, 0, 0},
        {"Charge", TypeEnum::Electric, 10, 8},
        {"Thunderbolt", TypeEnum::Electric, 20, 5},
        {"Vine Whip", TypeEnum::Grass, 15, 7},
        {"Ember", TypeEnum::Fire, 18, 6},
        {"Bubble Beam", TypeEnum::Water, 12, 8},
        {"Psychic Blast", TypeEnum::Psychic, 25, 3},
        {"Ice Beam", TypeEnum::Ice, 22, 4},
        {"Hyper Beam", TypeEnum::Normal, 30, 3},
        {"Earthquake", TypeEnum::Ground, 28, 4},
        {"Shadow Ball", TypeEnum::Ghost, 24, 5},
        {"Solar Beam", TypeEnum::Grass, 35, 3},
        {"Blizzard", TypeEnum::Ice, 32, 5},
        {"Thunder Punch", TypeEnum::Electric, 26, 5},
        {"Dragon Claw", TypeEnum::Dragon, 28, 6},
        {"Poison Jab", TypeEnum::Poison, 18, 8},
        {"Aerial Ace", TypeEnum::Flying, 20, 6}, 
    };

    vector<Pokemon> pokemonList = { 
        {"Pikachu", "A yellow mouse, everyone love it.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Magicarp", "A useless fish.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
    };
}
