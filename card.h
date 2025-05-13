// card.h
// Author: Amaya Bratcher
// All class declarations related to defining a single card go here
#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;
class Card { // declaring the card class
    char suit;
    string value;

    public:
    Card(char suit, string value);
    bool operator==(const Card& other) const;
    bool operator>=(const Card& other) const;
    bool operator<=(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator<(const Card& other) const;
    friend ostream& operator<<(ostream& out, const Card& card);
    
};
ostream& operator<<(ostream& out, const Card& card);
#endif
