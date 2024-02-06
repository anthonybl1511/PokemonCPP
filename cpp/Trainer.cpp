#include "Trainer.h"

Trainer::Trainer(string firstName, string lastName, string catchphrase, int money, int pokeballs, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3, Pokemon pokemon4, Pokemon pokemon5, Pokemon pokemon6) {
	mFirstName = firstName;
	mLastName = lastName;
	mCatchphrase = catchphrase;
	mMoney = money;
	mPokeballs = pokeballs;
	mPokemon1 = pokemon1;
	mPokemon2 = pokemon2;
	mPokemon3 = pokemon3;
	mPokemon4 = pokemon4;
	mPokemon5 = pokemon5;
	mPokemon6 = pokemon6;
}
Trainer::~Trainer() {}

string Trainer::GetFirstName() { return mFirstName; }
string Trainer::GetLastName() { return mLastName; }
string Trainer::Introduce() { return mCatchphrase; }
int Trainer::GetMoney() { return mMoney; }
int Trainer::GetPokeballs() { return mPokeballs; }
Pokemon Trainer::GetPokemonInBattle() { return mPokemonInBattle; };
vector<Pokemon> Trainer::GetPokemons() { return { mPokemon1, mPokemon2, mPokemon3, mPokemon4, mPokemon5, mPokemon6 }; }
void Trainer::AddPokemon(Pokemon pokemon, int slot) {
	if (slot == 1) {
		mPokemon1 = pokemon;
	}
	else if (slot == 2) {
		mPokemon2 = pokemon;
	}
	else if (slot == 3) {
		mPokemon3 = pokemon;
	}
	else if (slot == 4) {
		mPokemon4 = pokemon;
	}
	else if (slot == 5) {
		mPokemon5 = pokemon;
	}
	else if (slot == 6) {
		mPokemon6 = pokemon;
	}
}
void Trainer::SetMoney(int money) { mMoney = money; }
void Trainer::SetPokeballs(int pokeballs) { mPokeballs = pokeballs; }
void Trainer::SetPokemonInBattle(Pokemon pokemon) { mPokemonInBattle = pokemon; };
void Trainer::CapturePokemon(Pokemon pokemon) {
	if (pokemon.GetLifepoints() < 50) {
		mPokeballs -= 1;
		
		cout << "Which slot? (1-6)\n";
		int slot;
		cin >> slot;
		AddPokemon(pokemon, slot);
	}
}
void Trainer::ChallengeTrainer(Trainer trainer) {
	std::cout << trainer.Introduce();
	 
	std::cout << "Here are your Pokemons:\n";
	if (mPokemon1.GetName() != "") {
		std::cout << "Slot 1: " << mPokemon1.GetName() << ", ";
	}
	if (mPokemon2.GetName() != "") {
		std::cout << "Slot 2: " << mPokemon2.GetName() << ", ";
	}
	if (mPokemon3.GetName() != "") {
		std::cout << "Slot 3: " << mPokemon3.GetName() << ", ";
	}
	if (mPokemon4.GetName() != "") {
		std::cout << "Slot 4: " << mPokemon4.GetName() << ", ";
	}
	if (mPokemon5.GetName() != "") {
		std::cout << "Slot 5: " << mPokemon5.GetName() << ", ";
	}
	if (mPokemon6.GetName() != "") {
		std::cout << "Slot 6: " << mPokemon6.GetName() << endl;
	}
	bool chosen = false;
	int choice;
	while (!chosen) {
		std::cout << "\nChoose the Pokemon you want to send first, select it with its slot's number";
		cin >> choice;
		if (choice == 1 && (mPokemon1.GetName() != "")) {
			mPokemonInBattle = mPokemon1;
			chosen = true;
		}
		else if (choice == 2 && (mPokemon2.GetName() != "")) {
			mPokemonInBattle = mPokemon2;
			chosen = true;
		}
		else if (choice == 3 && (mPokemon3.GetName() != "")) {
			mPokemonInBattle = mPokemon3;
			chosen = true;
		}
		else if (choice == 4 && (mPokemon4.GetName() != "")) {
			mPokemonInBattle = mPokemon4;
			chosen = true;
		}
		else if (choice == 5 && (mPokemon5.GetName() != "")) {
			mPokemonInBattle = mPokemon5;
			chosen = true;
		}
		else if (choice == 6 && (mPokemon6.GetName() != "")) {
			mPokemonInBattle = mPokemon6;
			chosen = true;
		}
		else {
			std::cout << "\nInvalid choice";
		}
	}
	chosen = false;
	
	int KOCount = 0;
	trainer.SetPokemonInBattle(trainer.GetPokemons()[KOCount]);

	string winner;
	bool playerTurn = true;
	while (winner != "player" || winner != "trainer")
	{
		cout << "\nYou've chosen " << mPokemonInBattle.GetName() << endl;
		cout << trainer.GetFirstName() << " " << trainer.GetLastName() << "have chosen " << trainer.GetPokemonInBattle().GetName() << endl;
		cout << "The battle begins!" << endl;

		if (playerTurn) {
			cout << "It's your turn, choose an ability of " << mPokemonInBattle.GetName() << ":" << endl;
			for (Ability ability : mPokemonInBattle.GetAbilities()) {
				cout << "Slot 1: " << ability.GetName() << " (" << ability.GetDamages() << ", " << ability.GetEnergy() << "); " << endl;
			}
			while (!chosen) {
				cin >> choice;
				if (choice == 1 && (mPokemonInBattle.GetAbilities()[0].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[0].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(1, trainer.mPokemonInBattle);
				}
				else if (choice == 2 && (mPokemonInBattle.GetAbilities()[1].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[1].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(2, trainer.mPokemonInBattle);
				}
				else if (choice == 3 && (mPokemonInBattle.GetAbilities()[2].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[2].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(3, trainer.mPokemonInBattle);
				}
				else if (choice == 4 && (mPokemonInBattle.GetAbilities()[3].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[3].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(4, trainer.mPokemonInBattle);
				}
				else {
					std::cout << "\nInvalid choice" << endl;
				}
			}
			chosen = false;
			if (trainer.mPokemonInBattle.GetLifepoints() <= 0) {
				cout << trainer.mPokemonInBattle.GetName() << " is KO!" << endl;
				KOCount++;
				if (trainer.GetPokemons()[KOCount].GetName() != "") {
					trainer.SetPokemonInBattle(trainer.GetPokemons()[KOCount]);
					cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " sends " << trainer.GetPokemonInBattle().GetName() << " into the battle!" << endl;
				}
				else {
					cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " has no more Pokemons! You win!!" << endl;
					cout << "You have earned " << trainer.GetMoney() << " € from this fight!" << endl;
					SetMoney(GetMoney() + trainer.GetMoney());
					winner = "player";
				}
			}
		}
		else {
			cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " is choosing an ability to use..." << endl;
			chosen = false;
			int trainerChoice = 0;
			while (!chosen) {
				srand(time(NULL));
				trainerChoice = rand() % 4 + 1;
				if (trainerChoice == 1 && (trainer.GetPokemonInBattle().GetAbilities()[0].GetName() != "")) {
					chosen = true;
					cout << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[0].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(1, mPokemonInBattle);
				}
				else if (trainerChoice == 2 && (trainer.GetPokemonInBattle().GetAbilities()[1].GetName() != "")) {
					chosen = true;
					cout << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[1].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(2, mPokemonInBattle);
				}
				else if (trainerChoice == 3 && (trainer.GetPokemonInBattle().GetAbilities()[2].GetName() != "")) {
					chosen = true;
					cout << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[2].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(3, mPokemonInBattle);
				}
				else if (trainerChoice == 4 && (trainer.GetPokemonInBattle().GetAbilities()[3].GetName() != "")) {
					chosen = true;
					cout << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[3].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(4, mPokemonInBattle);
				}
			}
			if (mPokemonInBattle.GetLifepoints() <= 0) {
				cout << mPokemonInBattle.GetName() << " is KO!" << endl;
				bool canContinue = false;
				for (Pokemon pokemon : GetPokemons()) {
					if (pokemon.GetLifepoints() > 0) {
						canContinue = true;
						break;
					}
				}
				if (canContinue) {
					cout << "You need to send another pokemon in the battle, here are the one(s) that are not KO: " << endl;
					if (mPokemon1.GetName() != "" && mPokemon1.GetLifepoints() > 0) {
						std::cout << "Slot 1: " << mPokemon1.GetName() << ", ";
					}
					if (mPokemon2.GetName() != "" && mPokemon2.GetLifepoints() > 0) {
						std::cout << "Slot 2: " << mPokemon2.GetName() << ", ";
					}
					if (mPokemon3.GetName() != "" && mPokemon3.GetLifepoints() > 0) {
						std::cout << "Slot 3: " << mPokemon3.GetName() << ", ";
					}
					if (mPokemon4.GetName() != "" && mPokemon4.GetLifepoints() > 0) {
						std::cout << "Slot 4: " << mPokemon4.GetName() << ", ";
					}
					if (mPokemon5.GetName() != "" && mPokemon5.GetLifepoints() > 0) {
						std::cout << "Slot 5: " << mPokemon5.GetName() << ", ";
					}
					if (mPokemon6.GetName() != "" && mPokemon6.GetLifepoints() > 0) {
						std::cout << "Slot 6: " << mPokemon6.GetName() << endl;
					}
				}
				else {
					cout << "All your Pokemons are KO, you lose the fight." << endl;
					cout << "You have lost 100 € from this fight..." << endl;
					SetMoney(GetMoney() - 100);
					winner = "trainer";
				}
			}
		}
		playerTurn = !playerTurn;
	}
};
void Trainer::ChallengePokemon(Pokemon pokemon) {
	cout << pokemon.GetName() << " wants to fight!" << endl;

	std::cout << "Here are your Pokemons:\n";
	if (mPokemon1.GetName() != "") {
		std::cout << "Slot 1: " << mPokemon1.GetName() << ", ";
	}
	if (mPokemon2.GetName() != "") {
		std::cout << "Slot 2: " << mPokemon2.GetName() << ", ";
	}
	if (mPokemon3.GetName() != "") {
		std::cout << "Slot 3: " << mPokemon3.GetName() << ", ";
	}
	if (mPokemon4.GetName() != "") {
		std::cout << "Slot 4: " << mPokemon4.GetName() << ", ";
	}
	if (mPokemon5.GetName() != "") {
		std::cout << "Slot 5: " << mPokemon5.GetName() << ", ";
	}
	if (mPokemon6.GetName() != "") {
		std::cout << "Slot 6: " << mPokemon6.GetName() << endl;
	}
	bool chosen = false;
	int choice;
	while (!chosen) {
		std::cout << "\nChoose the Pokemon you want to send first, select it with its slot's number";
		cin >> choice;
		if (choice == 1 && (mPokemon1.GetName() != "")) {
			mPokemonInBattle = mPokemon1;
			chosen = true;
		}
		else if (choice == 2 && (mPokemon2.GetName() != "")) {
			mPokemonInBattle = mPokemon2;
			chosen = true;
		}
		else if (choice == 3 && (mPokemon3.GetName() != "")) {
			mPokemonInBattle = mPokemon3;
			chosen = true;
		}
		else if (choice == 4 && (mPokemon4.GetName() != "")) {
			mPokemonInBattle = mPokemon4;
			chosen = true;
		}
		else if (choice == 5 && (mPokemon5.GetName() != "")) {
			mPokemonInBattle = mPokemon5;
			chosen = true;
		}
		else if (choice == 6 && (mPokemon6.GetName() != "")) {
			mPokemonInBattle = mPokemon6;
			chosen = true;
		}
		else {
			std::cout << "\nInvalid choice";
		}
	}
	chosen = false;

	string winner;
	bool playerTurn = true;
	while (winner != "player" || winner != "pokemon")
	{
		cout << "\nYou've chosen " << mPokemonInBattle.GetName() << endl;
		cout << "The battle begins!" << endl;

		if (playerTurn) {
			cout << "It's your turn, choose an ability of " << mPokemonInBattle.GetName() << ":" << endl;
			for (Ability ability : mPokemonInBattle.GetAbilities()) {
				cout << "Slot 1: " << ability.GetName() << " (" << ability.GetDamages() << ", " << ability.GetEnergy() << "); " << endl;
			}
			while (!chosen) {
				cin >> choice;
				if (choice == 1 && (mPokemonInBattle.GetAbilities()[0].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[0].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(1, pokemon);
				}
				else if (choice == 2 && (mPokemonInBattle.GetAbilities()[1].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[1].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(2, pokemon);
				}
				else if (choice == 3 && (mPokemonInBattle.GetAbilities()[2].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[2].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(3, pokemon);
				}
				else if (choice == 4 && (mPokemonInBattle.GetAbilities()[3].GetName() != "")) {
					chosen = true;
					cout << mPokemonInBattle.GetName() << " uses " << mPokemonInBattle.GetAbilities()[3].GetName() << "!" << endl;
					mPokemonInBattle.UseAbility(4, pokemon);
				}
				else {
					std::cout << "\nInvalid choice" << endl;
				}
			}
			chosen = false;
			if (pokemon.GetLifepoints() <= 0) {
				if (GetPokemons().size() == 6) {
					cout << pokemon.GetName() << " is KO! Your team is full so you can't capture it, you win the battle!" << endl;
					winner = "player";
				}
				else {
					cout << pokemon.GetName() << " is KO! Do you want to capture it? 1: yes; 2: no" << endl;
					
					string answer;
					while (!chosen) {
						cin >> answer;
						if (answer == "1" || answer == "2") {
							chosen = true;
						}
						else {
							cout << "Choose only with 1 or 2." << endl;
						}
					}
					if (answer == "1") {
						if (GetPokeballs() > 0) {
							cout << "You captured " << pokemon.GetName() << ", congratulations!" << endl;
							SetPokeballs(GetPokeballs() - 1);
							
							int slot = 0;
							for (Pokemon pokemon : GetPokemons()) {
								if (pokemon.GetName() == "") {
									AddPokemon(pokemon, slot);
									break;
								}
								slot++;
							}
						}
						else {
							cout << "You don't have any pokeballs! The battle ends here." << endl;
						}
					}
					
					winner = "player";
				}
			}
		}
		else {
			cout << pokemon.GetName() << " is choosing an ability to use..." << endl;
			chosen = false;
			int pokemonChoice = 0;
			while (!chosen) {
				srand(time(NULL));
				pokemonChoice = rand() % 4 + 1;
				if (pokemonChoice == 1 && (pokemon.GetAbilities()[0].GetName() != "")) {
					chosen = true;
					cout << pokemon.GetName() << " uses " << pokemon.GetAbilities()[0].GetName() << "!" << endl;
					pokemon.UseAbility(1, mPokemonInBattle);
				}
				else if (pokemonChoice == 2 && (pokemon.GetAbilities()[1].GetName() != "")) {
					chosen = true;
					cout << pokemon.GetName() << " uses " << pokemon.GetAbilities()[1].GetName() << "!" << endl;
					pokemon.UseAbility(1, mPokemonInBattle);
				}
				else if (pokemonChoice == 3 && (pokemon.GetAbilities()[2].GetName() != "")) {
					chosen = true;
					cout << pokemon.GetName() << " uses " << pokemon.GetAbilities()[2].GetName() << "!" << endl;
					pokemon.UseAbility(1, mPokemonInBattle);
				}
				else if (pokemonChoice == 4 && (pokemon.GetAbilities()[3].GetName() != "")) {
					chosen = true;
					cout << pokemon.GetName() << " uses " << pokemon.GetAbilities()[3].GetName() << "!" << endl;
					pokemon.UseAbility(1, mPokemonInBattle);
				}
			}
			if (mPokemonInBattle.GetLifepoints() <= 0) {
				cout << mPokemonInBattle.GetName() << " is KO!" << endl;
				bool canContinue = false;
				for (Pokemon pokemon : GetPokemons()) {
					if (pokemon.GetLifepoints() > 0) {
						canContinue = true;
						break;
					}
				}
				if (canContinue) {
					cout << "You need to send another pokemon in the battle, here are the one(s) that are not KO: " << endl;
					if (mPokemon1.GetName() != "" && mPokemon1.GetLifepoints() > 0) {
						std::cout << "Slot 1: " << mPokemon1.GetName() << ", ";
					}
					if (mPokemon2.GetName() != "" && mPokemon2.GetLifepoints() > 0) {
						std::cout << "Slot 2: " << mPokemon2.GetName() << ", ";
					}
					if (mPokemon3.GetName() != "" && mPokemon3.GetLifepoints() > 0) {
						std::cout << "Slot 3: " << mPokemon3.GetName() << ", ";
					}
					if (mPokemon4.GetName() != "" && mPokemon4.GetLifepoints() > 0) {
						std::cout << "Slot 4: " << mPokemon4.GetName() << ", ";
					}
					if (mPokemon5.GetName() != "" && mPokemon5.GetLifepoints() > 0) {
						std::cout << "Slot 5: " << mPokemon5.GetName() << ", ";
					}
					if (mPokemon6.GetName() != "" && mPokemon6.GetLifepoints() > 0) {
						std::cout << "Slot 6: " << mPokemon6.GetName() << endl;
					}
				}
				else {
					cout << "All your Pokemons are KO, you need to run away!" << endl;
					winner = "pokemon";
				}
			}
		}
		playerTurn = !playerTurn;
	}
}