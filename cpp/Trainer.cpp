#include "Trainer.h"
#include <string> 


Trainer::Trainer(string firstName, string lastName, string catchphrase, int money, int pokeballs, vector<Pokemon> newPokemons) 
	: mFirstName(firstName), mLastName(lastName), mCatchphrase(catchphrase), mMoney(money), mPokeballs(pokeballs), Pokemons(newPokemons)
{
}

string Trainer::GetFirstName() { return mFirstName; }
string Trainer::GetLastName() { return mLastName; }
string Trainer::Introduce() { return mCatchphrase; }
int Trainer::GetMoney() { return mMoney; }
int Trainer::GetPokeballs() { return mPokeballs; }
Pokemon& Trainer::GetPokemonInBattle() { return Pokemons[mPokemonInBattle]; };
vector<Pokemon> Trainer::GetPokemons() { return { Pokemons }; }
void Trainer::AddPokemon(Pokemon pokemon) {
	Pokemons.push_back(pokemon);
}
void Trainer::SetMoney(int money) { mMoney = money; }
void Trainer::SetPokeballs(int pokeballs) { mPokeballs = pokeballs; }
void Trainer::SetPokemonInBattle(int pokemon) { mPokemonInBattle = pokemon; };

void Trainer::ChallengeTrainer(Trainer& trainer) {
	std::cout << "\"" << trainer.Introduce() << "\"" << endl;
	 
	std::cout << "\nHere are your Pokemons:" << endl;

	for (int i = 0; i < Pokemons.size(); i++) {
		std::cout << "Slot " << i + 1 << " : " << Pokemons[i].GetName() << ", ";
	}

	bool chosen = false;
	while (!chosen) {
		std::cout << "\nChoose the Pokemon you want to send first, select it with its slot's number:" << endl;
		int choice;
		cin >> choice;
		if (choice <= Pokemons.size()) {
			SetPokemonInBattle(choice - 1);
			chosen = true;
		}
		else {
			std::cout << "\ninvalid choice";
		}
	}
	chosen = false;
	
	int KOCount = 0;
	trainer.SetPokemonInBattle(KOCount);

	cout << "\nYou've chosen " << Pokemons[mPokemonInBattle].GetName() << endl;
	cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " have chosen " << trainer.GetPokemonInBattle().GetName() << endl;
	cout << "The battle begins!" << endl;

	string winner;
	bool playerTurn = true;
	while (winner != "player" || winner != "trainer")
	{
		if (playerTurn) {
			cout << "\nIt's your turn, choose an ability of " << Pokemons[mPokemonInBattle].GetName() << ": (The stats are [damages, enery])" << endl;
			int slotNum = 1;
			for (Ability ability : Pokemons[mPokemonInBattle].GetAbilities()) {
				if (ability.GetName() != "") {
					cout << "Slot " << slotNum << ": " << ability.GetName() << " [" << ability.GetDamages() << ", " << ability.GetEnergy() << "]; " << endl;
					slotNum++;
				}
			}
			chosen = false;
			while (!chosen) {
				string choice = "";
				cin >> choice;
				if (choice == "1" && (Pokemons[mPokemonInBattle].GetAbilities()[0].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[0].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(1, trainer.GetPokemonInBattle());

					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " has now " << trainer.GetPokemonInBattle().GetLifepoints() << " PV!" << endl;
				}
				else if (choice == "2" && (Pokemons[mPokemonInBattle].GetAbilities()[1].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[1].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(2, trainer.GetPokemonInBattle());

					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " has now " << trainer.GetPokemonInBattle().GetLifepoints() << " PV!" << endl;
				}
				else if (choice == "3" && (Pokemons[mPokemonInBattle].GetAbilities()[2].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[2].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(3, trainer.GetPokemonInBattle());

					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " has now " << trainer.GetPokemonInBattle().GetLifepoints() << " PV!" << endl;
				}
				else if (choice == "4" && (Pokemons[mPokemonInBattle].GetAbilities()[3].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[3].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(4, trainer.GetPokemonInBattle());

					cout << trainer.GetPokemonInBattle().GetName() << " has now " << trainer.GetPokemonInBattle().GetLifepoints() << " PV!" << endl;
				}
				else {
					std::cout << "\nInvalid choice" << endl;
				}
			}
			chosen = false;
			if (trainer.GetPokemonInBattle().GetLifepoints() <= 0) {
				cout << trainer.GetPokemonInBattle().GetName() << " is KO!" << endl;
				KOCount++;
				if (KOCount+1 <= trainer.Pokemons.size()) {
					trainer.SetPokemonInBattle(KOCount);
					cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " sends " << trainer.GetPokemonInBattle().GetName() << " into the battle!" << endl;
				}
				else {
					cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " has no more Pokemons! You win!!" << endl;
					cout << "You have earned " << trainer.GetMoney() << " € from this fight!" << endl;
					SetMoney(GetMoney() + trainer.GetMoney());
					winner = "player";
					break;
				}
			}
		}
		else {
			cout << trainer.GetFirstName() << " " << trainer.GetLastName() << " is choosing an ability to use..." << endl;
			chosen = false;
			while (!chosen) {
				int trainerChoice = 0;
				srand(time(NULL));
				int abilitiesAvailable = 0;
				for (int i = 0; i < 4; i++) {
					if (trainer.GetPokemonInBattle().GetAbilities()[i].GetName() != "") {
						abilitiesAvailable++;
					}
				}
				if (abilitiesAvailable > 1) {
					trainerChoice = rand() % abilitiesAvailable + 1;
				}
				else {
					trainerChoice = 1;
				}
				if (trainerChoice == 1) {
					chosen = true;
					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[0].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(1, Pokemons[mPokemonInBattle]);

					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
				else if (trainerChoice == 2) {
					chosen = true;
					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[1].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(2, Pokemons[mPokemonInBattle]);

					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
				else if (trainerChoice == 3) {
					chosen = true;
					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[2].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(3, Pokemons[mPokemonInBattle]);

					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
				else if (trainerChoice == 4) {
					chosen = true;
					cout << "\n" << trainer.GetPokemonInBattle().GetName() << " uses " << trainer.GetPokemonInBattle().GetAbilities()[3].GetName() << "!" << endl;
					trainer.GetPokemonInBattle().UseAbility(4, Pokemons[mPokemonInBattle]);

					cout << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
			}
			if (Pokemons[mPokemonInBattle].GetLifepoints() <= 0) {
				cout << Pokemons[mPokemonInBattle].GetName() << " is KO!" << endl;
				bool canContinue = false;
				for (Pokemon pokemon : GetPokemons()) {
					if (pokemon.GetLifepoints() > 0) {
						cout << pokemon.GetLifepoints() << " " << pokemon.GetName() << endl;
						canContinue = true;
						break;
					}
				}
				if (canContinue) {
					cout << "You need to send another pokemon in the battle, here are the one(s) that are not KO: " << endl;
					int index = 0;
					for (int i = 0; i < Pokemons.size(); i++) {
						if (Pokemons[i].GetLifepoints() > 0) {
							index++;
							std::cout << "Slot " << i << ": " << Pokemons[i].GetName() << ", ";
						}
					}
				}
				else {
					cout << "All your Pokemons are KO, you lose the fight." << endl;
					cout << "You have lost 100 € from this fight... You rest immediatly after the fight." << endl;
					for (int i = 0; i < Pokemons.size(); i++) {
						Pokemons[i].Rest();
					}
					SetMoney(GetMoney() - 100);
					winner = "trainer";
					break;
				}
			}
		}
		playerTurn = !playerTurn;
	}
	for (int i = 0; i < trainer.Pokemons.size(); i++) {
		trainer.Pokemons[i].Rest();
	}
};
void Trainer::ChallengePokemon(Pokemon pokemon) {
	cout << pokemon.GetName() << " wants to fight!" << endl;

	std::cout << "\nHere are your Pokemons:" << endl;

	for (int i = 0; i < Pokemons.size(); i++) {
		std::cout << "Slot "<<i +1<<" : " << Pokemons[i].GetName() << ", ";
	}

	bool chosen = false;
	while (!chosen) {
		std::cout << "\nChoose the Pokemon you want to send first, select it with its slot's number:" << endl;
		int choice;
		cin >> choice;
		if (choice <= Pokemons.size()) {
			SetPokemonInBattle(choice -1);
			chosen = true;
		}
		else {
			std::cout << "\ninvalid choice";
		}
	}
	chosen = false;

	string winner;
	bool playerTurn = true;

	cout << "\nYou've chosen " << Pokemons[mPokemonInBattle].GetName() << "." << endl;
	cout << "The battle begins!" << endl;


	while (winner != "player" && winner != "pokemon")
	{
		if (playerTurn) {
			cout << "\nIt's your turn, choose an ability of " << Pokemons[mPokemonInBattle].GetName() << ": (The stats are [damages, enery])" << endl;
			int slotNum = 1;
			for (Ability ability : Pokemons[mPokemonInBattle].GetAbilities()) {
				if (ability.GetName() != "") {
					cout << "Slot " << slotNum << ": " << ability.GetName() << " [" << ability.GetDamages() << ", " << ability.GetEnergy() << "]; " << endl;
					slotNum++;
				}
			}
			chosen = false;
			while (!chosen) {
				string choice = "";
				cin >> choice;
				if (choice == "1" && (Pokemons[mPokemonInBattle].GetAbilities()[0].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[0].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(1, pokemon);

					cout << "\n" << pokemon.GetName() << " has now " << pokemon.GetLifepoints() << " PV!" << endl;
				}
				else if (choice == "2" && (Pokemons[mPokemonInBattle].GetAbilities()[1].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[1].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(2, pokemon);

					cout << "\n" << pokemon.GetName() << " has now " << pokemon.GetLifepoints() << " PV!" << endl;
				}
				else if (choice == "3" && (Pokemons[mPokemonInBattle].GetAbilities()[2].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[2].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(3, pokemon);

					cout << "\n" << pokemon.GetName() << " has now " << pokemon.GetLifepoints() << " PV!" << endl;
				}
				else if (choice == "4" && (Pokemons[mPokemonInBattle].GetAbilities()[3].GetName() != "")) {
					chosen = true;
					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " uses " << Pokemons[mPokemonInBattle].GetAbilities()[3].GetName() << "!" << endl;
					Pokemons[mPokemonInBattle].UseAbility(4, pokemon);

					cout << pokemon.GetName() << " has now " << pokemon.GetLifepoints() << " PV!" << endl;
				}
				else {
					std::cout << "\nInvalid choice" << endl;
				}
			}
			if (pokemon.GetLifepoints() <= 0) {
				if (Pokemons.size() > 5) {
					cout << pokemon.GetName() << " is KO! Your team is full so you can't capture it, you win the battle!" << endl;
					winner = "player";
					break;
				}
				else {
					cout << pokemon.GetName() << " is KO! Do you want to capture it? 1: yes; 2: no" << endl;
					
					string answer;
					chosen = false;
					while (!chosen) {
						cin >> answer;
						if (answer == "1" || answer == "2") {
							chosen = true;
						}
						else {
							cout << "Choose only with 1 or 2." << endl;
						}
					}
					chosen = false;
					if (answer == "1") {
						if (GetPokeballs() > 0) {
							cout << "You captured " << pokemon.GetName() << ", congratulations!" << endl;
							SetPokeballs(GetPokeballs() - 1);		
							AddPokemon(pokemon);
						}
						else {
							cout << "You don't have any pokeballs! The battle ends here." << endl;
						}
					}
					
					winner = "player";
					break;
				}
			}
		}
		else {
			chosen = false;
			while (!chosen) {
				int pokemonChoice = 0;
				srand(time(NULL));
				int abilitiesAvailable = 0;
				for (int i = 0; i < 4; i++) {
					if (pokemon.GetAbilities()[i].GetName() != "") {
						abilitiesAvailable++;
					}
				}
				if (abilitiesAvailable > 1) {
					pokemonChoice = rand() % abilitiesAvailable + 1;
				}
				else {
					pokemonChoice = 1;
				}
				if (pokemonChoice == 1) {
					chosen = true;
					cout << "\n" << pokemon.GetName() << " uses " << pokemon.GetAbilities()[0].GetName() << "!" << endl;
					pokemon.UseAbility(1, Pokemons[mPokemonInBattle]);

					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
				else if (pokemonChoice == 2) {
					chosen = true;
					cout << "\n" << pokemon.GetName() << " uses " << pokemon.GetAbilities()[1].GetName() << "!" << endl;
					pokemon.UseAbility(2, Pokemons[mPokemonInBattle]);

					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
				else if (pokemonChoice == 3) {
					chosen = true;
					cout << "\n" << pokemon.GetName() << " uses " << pokemon.GetAbilities()[2].GetName() << "!" << endl;
					pokemon.UseAbility(3, Pokemons[mPokemonInBattle]);

					cout << "\n" << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
				else if (pokemonChoice == 4) {
					chosen = true;
					cout << "\n" << pokemon.GetName() << " uses " << pokemon.GetAbilities()[3].GetName() << "!" << endl;
					pokemon.UseAbility(4, Pokemons[mPokemonInBattle]);

					cout << Pokemons[mPokemonInBattle].GetName() << " has now " << Pokemons[mPokemonInBattle].GetLifepoints() << " PV!" << endl;
				}
			}
			if (Pokemons[mPokemonInBattle].GetLifepoints() <= 0) {
				cout << Pokemons[mPokemonInBattle].GetName() << " is KO!" << endl;
				bool canContinue = false;
				for (Pokemon pokemon : GetPokemons()) {
					if (pokemon.GetLifepoints() > 0) {
						cout << pokemon.GetLifepoints() << " " << pokemon.GetName() << endl;
						canContinue = true;
						break;
					}
				}
				if (canContinue) {
					cout << "You need to send another pokemon in the battle, here are the one(s) that are not KO: " << endl;
					int index = 0;
					for (int i = 0; i < Pokemons.size(); i++) {
						if (Pokemons[i].GetLifepoints() > 0) {
							index++;
							std::cout << "Slot " << i << ": " << Pokemons[i].GetName() << ", ";
						}
					}
				}
				else {
					cout << "All your Pokemons are KO, you need to run away and forced to rest!" << endl;
					for (int i = 0; i < Pokemons.size(); i++) {
						Pokemons[i].Rest();
					}
					winner = "pokemon";
				}
			}
		}
		playerTurn = !playerTurn;
	}
}