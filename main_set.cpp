// Feb 14: This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

class Gameplay{
  set<Card> bCards;
  set<Card> aCards;
  public:
  Gameplay(set<Card> alicesCards, set<Card> bobsCards);
  void startGame(); // starts game
  bool alicesTurn(); // go through cards smallest to largest find match then print
  bool bobsTurn(); // go through cards largest to smallest find match then print
  void printHands(); //print hands and ends the game
  

};

Gameplay::Gameplay(set<Card> alicesCards, set<Card> bobsCards){
  aCards = alicesCards;
  bCards = bobsCards;
}

void Gameplay::startGame(){
  bool runningGame = true;
  while(runningGame){
    runningGame = alicesTurn();
    runningGame = bobsTurn();
  }
  printHands();
}
bool Gameplay::alicesTurn(){
  for(auto it = aCards.begin(); it != aCards.end(); ++it){
      if(bCards.count(*it) == 1){
        cout << "Alice picked matching card " << *it << endl;
        aCards.erase(*it);
        bCards.erase(*it);
        return true;
      }
    }
    return false;
}
bool Gameplay::bobsTurn(){
  for(auto it = bCards.end(); it != bCards.begin(); --it){
    if(aCards.count(*it) == 1){
      cout << "Bob picked matching card " << *it << endl;
      aCards.erase(*it);
      bCards.erase(*it);
      return true;
    }
  }
  return false;
}


void Gameplay::printHands(){
cout << "Alice's cards:" << endl;
for(auto it = aCards.begin(); it != aCards.end(); ++it){
  cout << *it << endl;
}
cout << endl;
cout << "Bob's cards:" << endl;
for(auto it = bCards.begin(); it != bCards.end(); ++it){
  cout << *it << endl;
}
}




int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  set <Card> alicesCards = {};
  set <Card> bobsCards = {};
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    Card card = Card(line[0], line.substr(2));
    alicesCards.insert(card);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    Card card = Card(line[0], line.substr(2));
    bobsCards.insert(card);
  }
  cardFile2.close();
  
  Gameplay cardGame(alicesCards,bobsCards);
  cardGame.startGame();
  return 0;
}
