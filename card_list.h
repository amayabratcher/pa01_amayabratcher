// card_list.h
// Author: Amaya Bratcher
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
#include <iostream>
using namespace std;
class CardBST{
private:

struct Node{ // my node structure
    Card card; // the card stored in the bst
    Node *left, *right, *parent; // the declaring the left right and parent pointer
    
    Node(Card c) : card(c),left(0), right(0), parent(0){ } // default constructor that sets the card value to the card inputed 
};                                                         // sets all node values to null

Node* root;

bool insert(const Card& c, Node *n); // 
Node* getSuccessorNode(Card c) const; // overloaded function so that the user doesnt have to enter much information (abstraction)
Node* getPredecessorNode(Card c) const; // abstracting the function
void clear(Node* n); // destructor helper function
Node* getNodeFor(Card c, Node* n) const; //helper function for predecessor/successor/remove

public:
CardBST();// Constructor
~CardBST(); // Destructor
bool insert(const Card& c); 
bool contains(const Card& c) const;
void printDeck() const;
bool remove(const Card& c);



class Iterator{
    Node *ptr;
    const CardBST *deck;


public:
    Iterator(Node* n, const CardBST* cd) : ptr(n), deck(cd){}
    Iterator& operator++();
    Iterator& operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    Card operator*();
    bool operator!=(const Iterator& other);
    bool operator==(const Iterator& other);
    Card* operator->();


};

Iterator begin() const;
Iterator end() const;
Iterator rbegin() const;
Iterator rend() const;
friend class Iterator;

};

void playGame(CardBST& aCards, CardBST& bCards);
#endif
