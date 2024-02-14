#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "TypeEnum.h"
#include "Ability.h"
#include "Trainer.h"

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
        {"Water Gun", TypeEnum::Water, 15, 5},
        {"Flamethrower", TypeEnum::Fire, 28, 4},
        {"Psychic Wave", TypeEnum::Psychic, 22, 5},
        {"Ice Shard", TypeEnum::Ice, 18, 7},
        {"Tackle", TypeEnum::Normal, 12, 6},
        {"Mud Slap", TypeEnum::Ground, 20, 4},
        {"Shadow Punch", TypeEnum::Ghost, 25, 4},
        {"Leaf Blade", TypeEnum::Grass, 30, 3},
        {"Toxic", TypeEnum::Poison, 15, 8},
        {"Gust", TypeEnum::Flying, 22, 5},
        {"Thunder Wave", TypeEnum::Electric, 15, 6},
        {"Solar Flare", TypeEnum::Fire, 32, 3},
        {"Confusion", TypeEnum::Psychic, 20, 7},
        {"Frost Breath", TypeEnum::Ice, 25, 6},
        {"Crush Claw", TypeEnum::Normal, 28, 5},
        {"Quicksand", TypeEnum::Ground, 23, 6},
        {"Spectral Beam", TypeEnum::Ghost, 30, 4},
        {"Razor Leaf", TypeEnum::Grass, 18, 8},
        {"Venomous Bite", TypeEnum::Poison, 25, 5},
        {"Wing Attack", TypeEnum::Flying, 20, 7},
        {"Hydro Pump", TypeEnum::Water, 35, 3},
        {"Dragon Breath", TypeEnum::Dragon, 24, 5},
    };

    vector<Pokemon> pokemonList = {
        {"", "", TypeEnum::Electric, 0, 0, abilitiesList[0], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Pikachu", "A yellow mouse, everyone loves it.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Magikarp", "A useless fish.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Charmander", "A fire lizard.", TypeEnum::Fire, 1, 100, abilitiesList[1], abilitiesList[4], abilitiesList[0], abilitiesList[0]},
        {"Bulbasaur", "A living plant.", TypeEnum::Grass, 1, 100, abilitiesList[1], abilitiesList[3], abilitiesList[0], abilitiesList[0]},
        {"Squirtle", "Water turtle.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Butterfree", "A beautiful butterfly.", TypeEnum::Flying, 1, 100, abilitiesList[1], abilitiesList[16], abilitiesList[0], abilitiesList[0]},
        {"Jigglypuff", "A singing balloon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[25], abilitiesList[0], abilitiesList[0]},
        {"Vulpix", "A fox with fire tails.", TypeEnum::Fire, 1, 100, abilitiesList[1], abilitiesList[19], abilitiesList[0], abilitiesList[0]},
        {"Geodude", "A rock with arms.", TypeEnum::Ground, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Gastly", "A ghostly presence.", TypeEnum::Ghost, 1, 100, abilitiesList[1], abilitiesList[10], abilitiesList[0], abilitiesList[0]},
        {"Squirtle", "Water turtle.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Pidgey", "A small bird.", TypeEnum::Flying, 1, 100, abilitiesList[26], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Ekans", "A snake Pokémon.", TypeEnum::Poison, 1, 100, abilitiesList[1], abilitiesList[15], abilitiesList[0], abilitiesList[0]},
        {"Sandshrew", "A mouse-like Pokémon.", TypeEnum::Ground, 1, 100, abilitiesList[1], abilitiesList[21], abilitiesList[0], abilitiesList[0]},
        {"Meowth", "A cat Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[26], abilitiesList[0], abilitiesList[0]},
        {"Abra", "A psychic Pokémon.", TypeEnum::Psychic, 1, 100, abilitiesList[6], abilitiesList[28], abilitiesList[0], abilitiesList[0]},
        {"Machop", "A strong Pokémon.", TypeEnum::Fighting, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Tentacool", "A jellyfish Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[13], abilitiesList[0], abilitiesList[0]},
        {"Geodude", "A rock with arms.", TypeEnum::Ground, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Ponyta", "A fire horse.", TypeEnum::Fire, 1, 100, abilitiesList[1], abilitiesList[18], abilitiesList[0], abilitiesList[0]},
        {"Slowpoke", "A slow Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[22], abilitiesList[0], abilitiesList[0]},
        {"Magnemite", "A magnet Pokémon.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[23], abilitiesList[0], abilitiesList[0]},
        {"Farfetch'd", "A leek-wielding Pokémon.", TypeEnum::Flying, 1, 100, abilitiesList[26], abilitiesList[19], abilitiesList[0], abilitiesList[0]},
        {"Doduo", "A two-headed Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[28], abilitiesList[0], abilitiesList[0]},
        {"Seel", "A sea lion Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Grimer", "A sludge Pokémon.", TypeEnum::Poison, 1, 100, abilitiesList[1], abilitiesList[14], abilitiesList[0], abilitiesList[0]},
        {"Shellder", "A bivalve Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Gastly", "A ghostly presence.", TypeEnum::Ghost, 1, 100, abilitiesList[1], abilitiesList[10], abilitiesList[0], abilitiesList[0]},
        {"Onix", "A rock snake Pokémon.", TypeEnum::Ground, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Drowzee", "A drowsing Pokémon.", TypeEnum::Psychic, 1, 100, abilitiesList[6], abilitiesList[27], abilitiesList[0], abilitiesList[0]},
        {"Krabby", "A crab Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Voltorb", "A ball Pokémon.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Exeggcute", "An egg Pokémon.", TypeEnum::Grass, 1, 100, abilitiesList[1], abilitiesList[15], abilitiesList[0], abilitiesList[0]},
        {"Cubone", "A lonely Pokémon.", TypeEnum::Ground, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Hitmonlee", "A kicking Pokémon.", TypeEnum::Fighting, 1, 100, abilitiesList[1], abilitiesList[11], abilitiesList[0], abilitiesList[0]},
        {"Hitmonchan", "A punching Pokémon.", TypeEnum::Fighting, 1, 100, abilitiesList[1], abilitiesList[12], abilitiesList[0], abilitiesList[0]},
        {"Lickitung", "A licking Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[28], abilitiesList[0], abilitiesList[0]},
        {"Koffing", "A poison gas Pokémon.", TypeEnum::Poison, 1, 100, abilitiesList[1], abilitiesList[14], abilitiesList[0], abilitiesList[0]},
        {"Rhyhorn", "A spike Pokémon.", TypeEnum::Ground, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Chansey", "A egg Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[29], abilitiesList[0], abilitiesList[0]},
        {"Tangela", "A vine Pokémon.", TypeEnum::Grass, 1, 100, abilitiesList[1], abilitiesList[21], abilitiesList[0], abilitiesList[0]},
        {"Kangaskhan", "A parenting Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[28], abilitiesList[0], abilitiesList[0]},
        {"Horsea", "A sea horse Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Goldeen", "A goldfish Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Staryu", "A star shape Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Mr. Mime", "A barrier Pokémon.", TypeEnum::Psychic, 1, 100, abilitiesList[6], abilitiesList[30], abilitiesList[0], abilitiesList[0]},
        {"Scyther", "A mantis Pokémon.", TypeEnum::Bug, 1, 100, abilitiesList[1], abilitiesList[17], abilitiesList[0], abilitiesList[0]},
        {"Jynx", "A human shape Pokémon.", TypeEnum::Ice, 1, 100, abilitiesList[1], abilitiesList[31], abilitiesList[0], abilitiesList[0]},
        {"Electabuzz", "An electric Pokémon.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[14], abilitiesList[0], abilitiesList[0]},
        {"Magmar", "A spitfire Pokémon.", TypeEnum::Fire, 1, 100, abilitiesList[1], abilitiesList[19], abilitiesList[0], abilitiesList[0]},
        {"Pinsir", "A stag beetle Pokémon.", TypeEnum::Bug, 1, 100, abilitiesList[1], abilitiesList[17], abilitiesList[0], abilitiesList[0]},
        {"Tauros", "A wild bull Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[29], abilitiesList[0], abilitiesList[0]},
        {"Magikarp", "A useless fish.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Gyarados", "A fierce sea Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[32], abilitiesList[0]},
        {"Lapras", "A transport Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[33], abilitiesList[0]},
        {"Ditto", "A transforming Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Eevee", "An evolution Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Vaporeon", "A water evolution Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Jolteon", "An electric evolution Pokémon.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Flareon", "A fire evolution Pokémon.", TypeEnum::Fire, 1, 100, abilitiesList[1], abilitiesList[19], abilitiesList[0], abilitiesList[0]},
        {"Porygon", "A virtual Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Omanyte", "A spiral Pokémon.", TypeEnum::Water, 1, 100, abilitiesList[1], abilitiesList[5], abilitiesList[0], abilitiesList[0]},
        {"Kabuto", "A shellfish Pokémon.", TypeEnum::Rock, 1, 100, abilitiesList[1], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Aerodactyl", "A fossil Pokémon.", TypeEnum::Flying, 1, 100, abilitiesList[26], abilitiesList[9], abilitiesList[0], abilitiesList[0]},
        {"Snorlax", "A sleeping Pokémon.", TypeEnum::Normal, 1, 100, abilitiesList[8], abilitiesList[34], abilitiesList[0], abilitiesList[0]},
        {"Articuno", "A freeze Pokémon.", TypeEnum::Ice, 1, 100, abilitiesList[1], abilitiesList[35], abilitiesList[0], abilitiesList[0]},
        {"Zapdos", "An electric Pokémon.", TypeEnum::Electric, 1, 100, abilitiesList[1], abilitiesList[0], abilitiesList[0], abilitiesList[0]},
        {"Moltres", "A flame Pokémon.", TypeEnum::Fire, 1, 100, abilitiesList[1], abilitiesList[19], abilitiesList[0], abilitiesList[0]},
        {"Dratini", "A dragon Pokémon.", TypeEnum::Dragon, 1, 100, abilitiesList[1], abilitiesList[36], abilitiesList[0], abilitiesList[0]},
        {"Dragonair", "A dragon Pokémon.", TypeEnum::Dragon, 1, 100, abilitiesList[1], abilitiesList[37], abilitiesList[0], abilitiesList[0]},
        {"Dragonite", "A dragon Pokémon.", TypeEnum::Dragon, 1, 100, abilitiesList[1], abilitiesList[38], abilitiesList[0], abilitiesList[0]},
    };

    vector<Trainer> trainerList = {
        { "", "", "", 100, 5, {} },
        {"Marie", "Legrand", "Okayyy, let's take a break!", 150, 0, {pokemonList[12], pokemonList[24], pokemonList[0], pokemonList[0], pokemonList[0], pokemonList[0]}},
        {"John", "Smith", "Time to battle!", 200, 3, {pokemonList[3], pokemonList[7], pokemonList[15], pokemonList[0], pokemonList[0], pokemonList[0]}},
        {"Emily", "Jones", "Catch 'em all!", 180, 5, {pokemonList[1], pokemonList[10], pokemonList[18], pokemonList[25], pokemonList[0], pokemonList[0]} },
        {"David", "Johnson", "Prepare for defeat!", 220, 2, {pokemonList[2], pokemonList[14], pokemonList[20], pokemonList[27], pokemonList[34], pokemonList[0]}},
        {"Sophie", "Brown", "Let's have a friendly battle!", 190, 4, {pokemonList[4], pokemonList[0], pokemonList[0], pokemonList[0], pokemonList[0], pokemonList[0]} },
    };

    string playerFirstname;
    string playerLastname;
    string choice;
    Pokemon chosenPokemon;
    Trainer player = trainerList[0];
    bool chosen = false;
    bool gameActive = true;
    


    // GAME START
    cout << "Hello young trainer, welcome to the world of Pokemon! I'm professor Oak and I will introduce you to the basics of this world." << endl;
    cin.ignore();

    cout << "First what is your firstname? Type it in the console below." << endl;
    cin >> playerFirstname;
    cout << "And your lastname? Type it in the console below." << endl;
    cin >> playerLastname;
    cout << "Nice to meet you " << playerFirstname << " " << playerLastname << "!" << endl;
    cin.ignore();
    cout << "You will soon start your adventure, but before you need to choose your first Pokemon. You have to choose between those 3 Pokemon:" << endl;
    cout << "- 1: Chamander, a fire Pokemon." << endl;
    cout << "- 2: Bulbasaur, a grass Pokemon." << endl;
    cout << "- 3: Squirtle, a water Pokemon." << endl;
    cout << "Choose the one you want to start with by telling me its number (1, 2 or 3):" << endl;

    // Start pokemon choice
    while (!chosen) {
        cin >> choice;
        if (choice == "1") {
            chosen = true;
            chosenPokemon = pokemonList[3];
            cout << "Great choice!" << endl;
        }
        else if (choice == "2") {
            chosen = true;
            chosenPokemon = pokemonList[4];
            cout << "Great choice!" << endl;
        }
        else if (choice == "3") {
            chosen = true;
            chosenPokemon = pokemonList[5];
            cout << "Great choice!" << endl;
        }
        else {
            std::cout << "Invalid choice." << endl;
        }
    }
    player.AddPokemon(chosenPokemon);
    chosen = false;
    cin.ignore();
    cout << "You can now start your adventure! Here is 100$ and 5 pokeballs for you! Good luck!" << endl;
    cin.ignore();



    // GAME LOOP
    while (gameActive) {
        cout << "\n\nYou are in the wild, you see a trainer not too far away from you, what do you want to do?" << endl;
        cout << "- 1: Go in the tall grass to find a Pokemon." << endl;
        cout << "- 2: Talk to the trainer." << endl;
        cout << "- 3: Rest for a bit." << endl;
        cout << "Choose what you want to do (1, 2 or 3):" << endl;


        // Action choice
        while (!chosen) {
            cin >> choice;
            if (choice == "1") {
                chosen = true;
                cout << "\nAs your walking in the tall grass, a Pokemon jumps at you! Prepare to fight!" << endl;
                srand(time(NULL));
                int randomPokemonIndex = rand() % 70 + 1;
                player.ChallengePokemon(pokemonList[randomPokemonIndex]);
            }
            else if (choice == "2") {
                chosen = true;
                srand(time(NULL));
                int randomTrainerIndex = rand() % 8 + 1;

                cout << "\nAs soon as you cross the trainer's sight, the battle starts!" << endl;

                player.ChallengeTrainer(trainerList[randomTrainerIndex]);
            }
            else if (choice == "3") {
                chosen = true;
                cout << "\nTU TU TUDUDU!" << endl;
                for (Pokemon pokemon : player.GetPokemons()) {
                    pokemon.Rest();
                }
                cout << "All your Pokemon are now rested." << endl;
            }
            else {
                std::cout << "\nInvalid choice." << endl;
            }
        }
        chosen = false;
    }
}
