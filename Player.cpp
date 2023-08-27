#include "nim.H"

PlayerInfo::PlayerInfo(string name) {
    this->name = name;
}

string PlayerInfo::getName() {
    return name;
}

Move PlayerInfo::getMove(GameState state) {
    string response = new char[5];
    cout << "Which pile will you remove from? ";
    cin >> response;
    int pile = atoi(response.c_str()); // if response non-integer, zero returned
    cout << "How many coins do you want to remove? ";
    cin >> response;
    int coins = atoi(response.c_str());
    return new MoveInfo(coins, pile);
}

