// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "What is your name?" << endl;
    string answer;
    cin >> answer;
    cout << "Hello " << answer << ", welcome back!" << endl;

    int x = 12;
    cout << "The value " << x << " is stored in " << &x;
}
