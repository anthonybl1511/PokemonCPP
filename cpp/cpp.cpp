#include <iostream>
#include "Pokemon.h"
using namespace std;

void EarnMoney(int* wallet, int wage) {
    *wallet += wage;
    *wallet -= wage / 4;
}

int main()
{
    cout << "What is your name?" << endl;
    string answer;
    cin >> answer;
    cout << "Hello " << answer << ", welcome back!" << endl;

    int money = 1000;
    int* bankaccount = &money;
    cout << "You can find your money at this address: " << bankaccount << endl;
    cout << "You can find your bank at this address: " << &bankaccount << endl;
    EarnMoney(bankaccount, 10000);
    cout << "Thank you for the 10 000, now I have " << money;

    Pokemon pikachu = Pokemon::Pokemon("Pikachu", "It's the flagship Pokemon.", "Male", "Electric", 32, 11, 200);

    cout << pikachu.GetName() << endl;
}
