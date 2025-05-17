// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h

#include "card.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;
// two maps to convert the card indicators and convert them to values in order to have the logic and ordering of the cards
//to be easier for me to understand
map<string, int> cardValConverter = {
    {"a", 1}, // ace
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"j", 11}, //jack
    {"q", 12}, //queen
    {"k", 13}, //king
    {"0", 99999} //dummy default card
};
map<char,int> cardSuitConverter{
    {'c',1}, //clubs
    {'d',2}, //diamonds
    {'s',3}, //spades
    {'h',4}, // hearts
    {'x',999999} // dummy default card

};

// Card constructor
Card::Card(){
    this -> suit = 'x';
    this -> value = "0";
}
Card::Card(char suit, string value){
    this -> suit = suit;
    this -> value = value;
}

//Card operator overloading
// == op
bool Card::operator==(const Card& other) const{
    if(cardSuitConverter[this -> suit] == cardSuitConverter[other.suit]){
        if(cardValConverter[this -> value] ==  cardValConverter[other.value]){
            return true;
        }
    }
    return false;
}
// >= op
bool Card::operator>=(const Card& other)const{
    if(cardSuitConverter[this -> suit] < cardSuitConverter[other.suit]){
        return false;
     }
     if(cardSuitConverter[this -> suit] == cardSuitConverter[other.suit] && cardValConverter[this -> value] <  cardValConverter[other.value]){
         return false;
     }
     return true;
}
// <= op
bool Card::operator<=(const Card& other)const{
    if(cardSuitConverter[this -> suit] > cardSuitConverter[other.suit]){
       return false;
    }
    if(cardSuitConverter[this -> suit] == cardSuitConverter[other.suit] && cardValConverter[this -> value] >  cardValConverter[other.value]){
        return false;
    }
    return true;
}

// > op
bool Card::operator>(const Card& other)const{
    if(cardSuitConverter[this -> suit] > cardSuitConverter[other.suit]){
        return true;
    }
    if(cardSuitConverter[this -> suit] == cardSuitConverter[other.suit] && cardValConverter[this -> value] > cardValConverter[other.value]){
        return true;
    }
    return false;
}
// < op
bool Card::operator<(const Card& other)const{
    if(cardSuitConverter[this -> suit] < cardSuitConverter[other.suit]){
        return true;
    }
    if(cardSuitConverter[this -> suit] == cardSuitConverter[other.suit] && cardValConverter[this -> value] < cardValConverter[other.value]){
        return true;
    }
    return false;
}
// << operator overloading to make printing the Card contents alot easier
ostream& operator<<(ostream& out, const Card& card){
    out << card.suit << " " << card.value;
    return out;
}