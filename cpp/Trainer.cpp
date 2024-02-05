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
		std::cout << "Slot 6: " << mPokemon6.GetName() << ", ";
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
	
	trainer.SetPokemonInBattle(trainer.GetPokemons().front());

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
					std::cout << "\nInvalid choice";
				}
			}
		}
	}
};