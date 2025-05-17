// card_list.cpp
// Author: Amaya Bratcher
// Implementation of the classes defined in card_list.h
#include "card_list.h"
#include "card.h"
#include <iostream>
using namespace std;


CardBST::CardBST(){
    this -> root = nullptr;
}

// destructor clears and cleans up bst
CardBST::~CardBST(){
    clear(this -> root);
}
// helper function for destructor that helps recursively delete each node
void CardBST::clear(Node* n){
    if(n != nullptr){
        clear(n -> left);
        clear(n -> right);
        delete n;
    }
}

// attempts to insert value into tree and returns false if the
// it is a duplicate value
bool CardBST::insert(const Card& c){
    if(root == nullptr){
        root = new Node(c);
        return true;
    }
    return insert(c,root);
}
// recursively calls insert until it finds the correct place to insert the new card
// once the correct spot is found a new node is created with the card value and placed into 
// the bst and it returns true if a value is found and it is equal to the card value it returns false
bool CardBST::insert(const Card& c, Node *n){
    if( c == n -> card){
        return false;
    }
    else if(c < n -> card){
        if(n -> left == nullptr){
            n -> left  =  new Node(c);
            n -> left -> parent = n;
            return true;
        }
        else{
            return insert(c, n -> left);
            
        }
    }
    else if(c > n -> card){
        if(n -> right == nullptr){
            n -> right  =  new Node(c);
            n -> right -> parent = n;
            return true;
        }
        else{
            return insert(c, n -> right);
            
        }
    }
    return false;
}

// a helper function for remove and contains and the predecessor and successor functions
// iterates til it finds the value its looking for or hits a nullptr
// if the value it found it returns a pointer to it
// if the value isnt found it returns a nullptr
CardBST::Node* CardBST::getNodeFor(Card c, Node* n) const{
    if(n != nullptr){
        if(c == n -> card){
            return n;
        }
        else if (c > n -> card){
            return getNodeFor(c, n -> right);
        }
        else if (c < n -> card){
            return getNodeFor(c, n -> left);
        }
    }
    return nullptr;
}
 // checks if the bst contains the value its looking for
 // if the bst doesnt contain the value its looking for it returns false
 // if the bst contains the value it returns true
bool CardBST::contains(const Card& c) const{
    Node *ptr = getNodeFor(c, this -> root);
    return ptr != nullptr;
}


// returns the node that comes after the card given 
// returns null if there is not a successor Node
CardBST::Node* CardBST::getSuccessorNode(Card c) const{
    Node *n = getNodeFor(c, this -> root);
    if(n == nullptr){
        return nullptr;
    }
    else if(n -> right != nullptr){
        n = n -> right;
        while(n != nullptr && n -> left != nullptr){
            n = n -> left;
        }
        return n;
    }
    else{
        Node *parent = n -> parent;
        while( parent != nullptr &&  parent -> left != n){
            n = parent;
            parent = parent -> parent;
        }
        return parent;
        
    }
}

// returns the node that comes before the card given 
// returns null if there is not a predescessor Node
CardBST::Node* CardBST::getPredecessorNode(Card c) const{
    Node *n = getNodeFor(c, this -> root);
    if(n == nullptr){
        return nullptr;
    }
    else if(n -> left != nullptr){
        n = n -> left;
        while( n -> right != nullptr && n !=  nullptr ){
            n = n -> right;
        }
        return n;
    }
    else{
        Node *parent = n -> parent;
        while(parent -> right != n && parent != nullptr){
            n = parent;
            parent = parent -> parent;
        }
        return parent;
        
    }
}


bool CardBST::remove(const Card& c){
    
        Node *ptr = getNodeFor(c, this -> root);
        if(!ptr) return false;
        if(ptr == root){
            if(ptr -> left == nullptr && ptr -> right == nullptr){
                root = nullptr;
                delete ptr;
                return true;
            }
            else{
                if(ptr -> left != nullptr && ptr -> right != nullptr){
                    Node* successor = getSuccessorNode(ptr -> card);
                    root -> card  = successor -> card;
                    if(successor -> right != nullptr){
                        if(successor -> parent -> left == successor){
                            successor -> parent -> left = successor -> right;
                        }
                        else{
                            successor -> parent -> right = successor -> right;
                        }
                        successor -> right -> parent = successor -> parent;
                    }
                    else{
                        if(successor -> parent -> left == successor){
                            successor -> parent -> left = nullptr;
                        }
                        else{
                            successor -> parent -> right = nullptr;
                        }
                    }
                    delete successor;
                    return true;
                }
                else if(ptr -> right){
                    root = ptr -> right;
                    root -> parent = nullptr;
                    delete ptr;
                    return true;
                }
                else{
                    root = ptr -> left;
                    root -> parent = nullptr;
                    delete ptr;
                    return true;
                }
            }
        }
        else{
            if(ptr -> left != nullptr && ptr -> right != nullptr){
                Node* successor = getSuccessorNode(ptr -> card);
                ptr -> card = successor -> card;
                if(successor -> right != nullptr){
                    if(successor -> parent -> left == successor){
                        successor -> parent -> left = successor -> right;
                    }
                    else{
                        successor -> parent -> right = successor -> right;
                    }
                    successor -> right -> parent = successor -> parent;
                }
                else{
                    if(successor -> parent -> left == successor){
                        successor -> parent -> left = nullptr;
                    }
                    else{
                        successor -> parent -> right = nullptr;
                    }
                }
                delete successor;
                return true;
            }
            else if(ptr -> left == nullptr && ptr -> right == nullptr){
                if(ptr -> parent -> right == ptr){
                    ptr -> parent -> right = nullptr;
                }
                else{
                    ptr -> parent -> left = nullptr;
                }
                delete ptr;
                return true;
            }
            else{
                if(ptr -> left != nullptr){
                    if(ptr -> parent -> right == ptr){
                        ptr -> parent -> right = ptr -> left;
                        ptr -> left -> parent = ptr -> parent;
                        delete ptr;
                        return true;
                    }
                    else{
                        ptr -> parent -> left = ptr -> left;
                        ptr -> left -> parent = ptr -> parent;
                        delete ptr;
                        return true;
                    }
                }
                else{
                    if(ptr -> parent -> right == ptr){
                        ptr -> parent -> right = ptr -> right;
                        ptr -> right -> parent = ptr -> parent;
                        delete ptr;
                        return true;
                    }
                    else{
                        ptr -> parent -> left = ptr -> right;
                        ptr -> right -> parent = ptr -> parent;
                        delete ptr;
                        return true;
                    }
                }
            }
        }
    
    return false;
}

CardBST::Iterator& CardBST::Iterator::operator++(){
    if(this -> ptr != nullptr){
    this -> ptr =  this -> deck -> getSuccessorNode(this -> ptr -> card);
    }
        return *this;
}

CardBST::Iterator& CardBST::Iterator::operator--(){
    if(this -> ptr != nullptr){
    this -> ptr = this -> deck -> getPredecessorNode(this -> ptr -> card);
    }
        return *this;
    
}

CardBST::Iterator CardBST::Iterator::operator++(int){
    Iterator temp = *this;
    ++(*this);
    return temp;
}

CardBST::Iterator CardBST::Iterator::operator--(int){
    Iterator temp = *this;
    --(*this);
    return temp;
}

Card CardBST::Iterator::operator*(){
    return this -> ptr -> card;
}

Card* CardBST::Iterator::operator->(){
    return &(this -> ptr -> card);
}

bool CardBST::Iterator::operator==(const Iterator& other){
   return this-> ptr == other.ptr;
    
}

bool CardBST::Iterator::operator!=(const Iterator& other){
   return this -> ptr != other.ptr;
    
}

CardBST::Iterator CardBST::begin()const{ 
    Node* n = root;
        while(n && n -> left != nullptr){
            n = n -> left;
        }
        
    return Iterator(n,this);
}
CardBST::Iterator CardBST::end()const{ 
    return Iterator(nullptr, this);
}
CardBST::Iterator CardBST::rbegin()const{ 
    Node* n = root;
        while(n && n -> right != nullptr){
            n = n -> right;
        }
        
    return Iterator(n,this);
}
CardBST::Iterator CardBST::rend()const{ 
    return Iterator(nullptr, this);
}

void CardBST::printDeck() const{
    
    for(auto it = begin(); it != end(); it++){
        cout << *it << endl;
    }
}

bool alicesTurn(CardBST& aCards, CardBST& bCards){
    bool found = false;
    Card temp;
    for(auto it = aCards.begin(); it != aCards.end(); ++it){
        if(bCards.contains(*it)){ // if card in Alices hand is found in Bobs hand
            cout << "Alice picked matching card " << *it << endl; // print theres a match
            temp = *it;
            found = true;
            break;
        }  
}
    if(found){
        aCards.remove(temp); //remove match from both hands
        bCards.remove(temp);
    }
    return found;
}

bool bobsTurn(CardBST& bCards, CardBST& aCards){
    bool found = false;
    Card temp;
    for(auto it = bCards.rbegin(); it != bCards.rend(); ++it){
        if(aCards.contains(*it)){ // if card in Bobs hand is found in Alices hand
            cout << "Bob picked matching card " << *it << endl; // print theres a match
            temp = *it;
            found = true;
            break;
        }  
}
    if(found){
        aCards.remove(temp); //remove match from both hands
        bCards.remove(temp);
    }
    return found;
}

void playGame(CardBST& aCards, CardBST& bCards){
    bool runningGame = true;
    while(runningGame){
      bool alicematched = alicesTurn(aCards, bCards);
      bool bobmatched = bobsTurn(bCards,aCards);
      runningGame = alicematched || bobmatched;
    }
    cout << endl;
    cout << "Alice's cards:" << endl;
    aCards.printDeck();
    cout << endl;
    cout << "Bob's cards:" << endl;
    bCards.printDeck();
     
}