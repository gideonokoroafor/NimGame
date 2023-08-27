/* 
 * File:   ScoreKeeper.cpp
 * Author: Gideon O.
 * 
 */

#include "nim.H"

void ScoreKeeperInfo::start() {
    // you provide
    welcome();
    flipCoin();
    playRepeatedly();
}

ScoreKeeperInfo::ScoreKeeperInfo(){}

ScoreKeeperInfo::ScoreKeeperInfo(string name){
  this->name = name;
}

string ScoreKeeperInfo::getPlayer(string name){
  return name;
} 
// definitions of private methods go here

void ScoreKeeperInfo::welcome(){
  name = getPlayer(name);
  wins = 0;
    cout<< "Welcome to a game of nim\n" "What is your name: ";
    getline(cin, name);
}

string ScoreKeeperInfo::getFlip(){
  string guess;
  do {
    cout << "heads or tails? ";
    cin >> guess;
  }
  while ( guess.compare("heads") != 0 && guess.compare("tails") != 0 );
  return guess;
}

string ScoreKeeperInfo::getToss(){
  int randomNumber = rand() % 2;
  string headTail = "";
  srand((time(0)));
  if(randomNumber == 0){
    headTail = "heads";
  }
  if(randomNumber == 1){
    headTail = "tails";
  }
  return headTail;
}

void ScoreKeeperInfo::flipCoin(){
  cout<< "I will flip a coin to start"<<endl;
  getToss();
}

int ScoreKeeperInfo::makeRandomState(){
  int randomState = Utils::generateRandomInt(6, 12);
  return randomState;
}

void ScoreKeeperInfo::playRepeatedly(){
  string coinResult = getToss();
  string guess = getFlip();

  int playerPoint = 0;
  int computerPoint = 0;
  Player winner;

  GameState randomGameState = new GameStateInfo(makeRandomState(), makeRandomState(), makeRandomState());
  Player player1 = new PlayerInfo(name);
  Player player2 = new AutomatedPlayerInfo("HAL 9000", new IntermediateStrategyInfo);

  bool play_again = true;

  //while(play_again){

  if(coinResult == guess){
    cout << "It is " << coinResult << endl;
    cout << "You go first" << endl;
    Game game = new GameInfo(player1, player2, randomGameState);
    winner = game->play();
    cout << winner->getName() << " wins. " << "Score(s): " << endl;
    if(winner == player1){
      playerPoint++;
      cout << player1->getName() << ": " << playerPoint << endl;
      cout << player2->getName() << ": " << computerPoint << endl;
    }
    else {
      computerPoint++;
      cout << player1->getName() << ": " << playerPoint << endl;
      cout << player2->getName() << ": " << computerPoint << endl;
    }
  }
  else{
    cout << "It is " << coinResult << endl;
      cout<<"HAL 9000 go first"<<endl;
      Game game = new GameInfo(player2, player1, randomGameState);
      winner = game->play();
      cout << winner->getName() << " wins. " << "Score(s): " << endl;
      if(winner == player2){
        computerPoint++;
        cout << player1->getName() << ": " << playerPoint << endl;
        cout << player2->getName() << ": " << computerPoint << endl;
      }
      else {
        playerPoint++;
        cout << player1->getName() << ": " << playerPoint << endl;
        cout << player2->getName() << ": " << computerPoint << endl;
      }
    }
  while (play_again){
    GameState randomGameState = new GameStateInfo(makeRandomState(), makeRandomState(), makeRandomState());
    firstToPlay = player1;
    string ans = getGameloop();
    const std::string yesCompareHelper("yes");    
    const std::string noCompareHelper("no");
    if(ans == yesCompareHelper){
      if(winner == firstToPlay){
        //firstToPlay = player2;
        Game game = new GameInfo(player2, player1, randomGameState);
        winner = game->play();
        cout << winner->getName() << " wins. " << "Score(s): " << endl;
        if(winner == player1){
          playerPoint++;
          cout << player1->getName() << ": " << playerPoint << endl;
          cout << player2->getName() << ": " << computerPoint << endl;
        }
        else{
          computerPoint++;
          cout << player1->getName() << ": " << playerPoint << endl;
          cout << player2->getName() << ": " << computerPoint << endl;
        }
      }
      if(winner == player2){
        //firstToPlay = player1;
        Game game = new GameInfo(player1, player2, randomGameState);
        winner = game->play();
        cout << winner->getName() << " wins. " << "Score(s): " << endl;
        if(winner == player1){
          playerPoint++;
          cout << player1->getName() << ": " << playerPoint << endl;
          cout << player2->getName() << ": " << computerPoint << endl;
        }
        else{
          computerPoint++;
          cout << player1->getName() << ": " << playerPoint << endl;
          cout << player2->getName() << ": " << computerPoint << endl;
        }
      }
    }
    if(ans == noCompareHelper){
      cout << "Good game." <<endl;
      play_again = false;
      
    }
  }
}

string ScoreKeeperInfo::getGameloop(){
  string ans = " ";
  do {
    std::cout << "Another game (yes or no)? " <<endl;
    std::cin >> ans;
  }
  while ( ans.compare("yes") != 0 && ans.compare("no") != 0 );
  return ans;
}
