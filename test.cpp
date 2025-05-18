#include "card.h"
#include "card_list.h"
#include <iostream>
using namespace std;




int main(){
    CardBST empty;
    CardBST singleNode;
    Card c1('h',"a");
    Card c2('s',"10");
    Card c3('c',"q");
    Card c4('d',"5");
    Card c5('s',"k");

    cout << "****TESTING****" << endl;
    
    cout<< endl;
    cout << "-SINGLE CARD DECK TESTING-" << endl;
    cout << "TEST - Inserting Card into empty tree" << endl;
    if(singleNode.insert(c2)){ //test #1 on insert()| should return true
        cout << "Test passed: successfully inserted card into empty tree" << endl;
    }
    else{
        cout << "Test failed: unsuccessfully inserted card into empty tree" << endl;
    }
    cout << endl;
    cout << "Now printing deck" << endl;
    cout << "Single Card Deck:" << endl;
    singleNode.printDeck(); 
    cout << endl;
    cout << "Does deck contain h a ??" << endl;
    if(singleNode.contains(c1)){ // contains test #1
        cout << "contains() test failed: deck does not contain h a " << endl;
    }
    else{
        cout << "contains() test passed: h a not found" << endl;
    }
    cout << "Does deck contain s 10 ??" << endl; 
    if(singleNode.contains(c2)){ // contains test #2
        cout << "contains() test passed: deck does contain s 10 " << endl;
    }
    else{
        cout << "contains() test failed: deck contains s 10" << endl;
    }
    cout << endl;
    cout << endl;
    cout << "TEST - Trying to insert duplicate card" << endl;
    if(singleNode.insert(c2)){ //test #2 on insert()                  | should return false
        cout << "insert() test failed:  duplicate card returned true"<< endl;
    }
    else{
        cout << "insert() test passed:  duplicate card returned false"<< endl;
    }
    cout << endl;
    cout << "Now printing deck" << endl;
    cout << "Single Card Deck:" << endl;
    singleNode.printDeck();
    cout << endl;
    cout << "TEST - Trying to remove a card that doesnt exist" << endl;
    if(singleNode.remove(c3)){; // test #1 on remove()                 |should return false
    cout << "remove() test failed:  returned true when removing a card that doesnt exist" << endl;
    }
    else{
    cout << "remove() test passed:  returned false when removing a card that doesnt exist" << endl;
    }
    cout << endl;
    cout << "TEST - Trying to remove a card that does exist (card deck now empty)" << endl;
    if(singleNode.remove(c2)){ // test #2 on remove()                 |should return true
    cout << "remove() test passed:  returned true when removing a card that exists" << endl;
    }
    else{
    cout << "remove() test failed:  returned false when removing a card that exists" << endl;    
    }
    cout << "Now printing deck (should now be empty)" << endl;
    cout << endl;
    cout << "Single Card Deck:" << endl;
    singleNode.printDeck(); 
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-EMPTY DECK TESTING-" << endl;
    cout << "Now printing deck" << endl;
    cout << "Empty Deck:" << endl;
    cout << endl;
    empty.printDeck(); 
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "TEST - Checking if any card values will return true on an empty deck" << endl;
    cout << "Does deck contain s k ??" << endl;
    if(singleNode.contains(c5)){ // contains test #3
        cout << "contains() test failed: deck does not contain s k " << endl;
    }
    else{
        cout << "contains() test passed: s k not found" << endl;
    }
    cout << endl;
    cout << "Does deck contain d 5 ??" << endl;
    if(singleNode.contains(c4)){ // contains test #4
        cout << "contains() test failed: deck does not contain d 5 " << endl;
    }
    else{
        cout << "contains() test passed: d 5 not found" << endl;
    }
   cout << endl;
   cout << "-------------------------------------------------------------------------------------" << endl;
   cout <<"-INSERTING INTO EMPTY DECK-" << endl;
   cout << endl;
   cout << "Now inserting 'h a' 'd 5' 's k' " << endl;
   cout << "TEST -  Inserting values into an empty deck" << endl;
   cout << "inserting 'h a'" << endl;
   if(empty.insert(c1)){; // insert #2
    cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   cout << "Deck after insert: " << endl;
   empty.printDeck(); 
   cout << "inserting 'd 5'" << endl;
   if(empty.insert(c4)){; // insert #3
    cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   cout << "Deck after insert: " << endl;
   empty.printDeck(); 
   cout << "inserting 's k'" << endl;
   if(empty.insert(c5)){;// insert #4
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   cout << "Deck after insert: " << endl;
   empty.printDeck(); 
   cout << "Inserting d 8, d 5, d q, h q, s 9, d 6, s a, s 7, h 7, c 8, h 3" << endl;
   if(empty.insert(Card('d',"8"))){;// insert #5
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if( empty.insert(Card('d',"5"))){;// insert #6
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if(empty.insert(Card('d',"q"))){;// insert #7
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if(empty.insert(Card('h',"q"))){;// insert #8
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if(empty.insert(Card('s',"9"))){;// insert #9
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if(empty.insert(Card('d',"6"))){;// insert #10
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if( empty.insert(Card('s',"a"))){;// insert #11
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if( empty.insert(Card('s',"7"))){;// insert #12
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if( empty.insert(Card('h',"7"))){;// insert #13
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
  if( empty.insert(Card('c',"8"))){;// insert #14
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   if( empty.insert(Card('h',"3"))){;// insert #15
     cout << "insert() test passed: successfully inserted card" << endl;
   }
   else{
    cout << "insert() test failed: unsuccessfully inserted card" << endl;
   }
   cout << endl;
   cout << "Deck after inserts: " << endl;
   empty.printDeck(); 
   cout << endl;
   cout << endl;
   if(empty.remove(Card('h',"3"))){ // test #3 on remove()                
    cout << "remove() test passed:  returned true when removing a card that exists" << endl;
    }
    else{
    cout << "remove() test failed:  returned false when removing a card that exists" << endl;    
    }
    cout << "Deck after removing 'h 3': " << endl;
    empty.printDeck(); 
    cout << endl;
    cout << endl;
    if(empty.remove(Card('c',"a"))){ // test #4 on remove()                 
    cout << "remove() test failed:  returned true when removing a card that doesnt exists" << endl;
    }
    else{
    cout << "remove() test passed:  returned false when removing a card that doesnt exists" << endl;    
    }
     if(empty.remove(Card('c',"2"))){ // test #5 on remove()                 
    cout << "remove() test failed:  returned true when removing a card that doesnt exists" << endl;
    }
    else{
    cout << "remove() test passed:  returned false when removing a card that doesnt exists" << endl;    
    }
   empty.printDeck();
   cout << endl;
   cout << endl;
   cout << "-------------------------------------------------------------------------------------" << endl;
   cout << "TEST- Checking Predeccessor and Successor functions" << endl;
   cout << "Testing h a predecessor" << endl;
   cout << endl;
   if((empty.getPredecessorNode(c1)) -> card == Card('s',"k")){
    cout << "getPredecessorNode test passed: The correct card is returned" << endl;
   }
   else{
    cout << "getPredecessorNode test failed: The incorrect card is returned" << endl;
     
   }
   cout << "Testing c 8 predecessor" << endl;
   cout << endl;
   if((empty.getPredecessorNode(Card('c',"8")))  == nullptr){
    cout << "getPredecessorNode test passed: The correct card is returned" << endl;
   }
   else{
    cout << "getPredecessorNode test failed: The incorrect card is returned" << endl;
     
   }
   cout << "Testing d q predecessor" << endl;
   cout << endl;
   if((empty.getPredecessorNode(Card('d',"q"))) -> card == Card('d',"8")){
    cout << "getPredecessorNode test passed: The correct card is returned" << endl;
   }
   else{
    cout << "getPredecessorNode test failed: The incorrect card is returned" << endl;
     
   }
   cout << "Testing d 5 predecessor" << endl;
   cout << endl;
   if((empty.getPredecessorNode(Card('d',"5")) -> card) == Card('h',"8")){
    cout << "getPredecessorNode test failed: The incorrect card is returned" << endl;
   }
   else{
    cout << "getPredecessorNode test passed: The correct card is returned" << endl;
     
   }
   cout << "Testing h 7 predecessor" << endl;
   cout << endl;
   if((empty.getPredecessorNode(Card('h',"7")) -> card) == Card('h',"8")){
    cout << "getPredecessorNode test failed: The incorrect card is returned" << endl;
   }
   else{
    cout << "getPredecessorNode test passed: The correct card is returned" << endl;
     
   }
   cout << "-------------------------------------------------------------------------------------" << endl;
   cout << "TESTING ITERATOR CLASS" << endl;
   cout << endl;

   CardBST empty2;
   if(empty2.begin() == empty2.end()){ 
    cout << "Iterator test passed: begin() and end() of empty class equal "<< endl;
   }
   else{
    cout << "Iterator test failed: begin() and end() of empty class not equal " << endl;
   }
   cout << endl;

   if(empty2.rend() != empty2.end()){ 
    cout << "Iterator test failed: end() and rend() of empty class not equal "<< endl;
   }
   else{
    cout << "Iterator test passed: end() and rend() of empty class  equal " << endl;
   }
   cout << endl;
   CardBST single;
single.insert(Card('c', "5"));

auto it = single.begin();
if (*it == Card('c', "5")) {
    cout << "single node test passed: correct card returned" << endl;
} else {
    cout << "single node test failed: incorrect card returned" << endl;
}

++it;
if (it == single.end()) {
    cout << "increment after single node test passed" << endl;
} else {
    cout << "increment after single node test failed" << endl;
}

--it;
if (*it == Card('c', "5")) {
    cout << "decrement back to single node test passed" << endl;
} else {
    cout << "decrement back to single node test failed" << endl;
}

cout << "-------------------------------------------------------------------------------------" << endl;
   cout << "TESTING PLAYGAME" << endl;
CardBST b1;
CardBST a1;
CardBST a2;



a1.insert(c1);
a1.insert(c2);
a1.insert(c3);
a1.insert(c4);
a1.insert(c5);
b1.insert(c1);
b1.insert(c2);
b1.insert(c3);
b1.insert(c4);
b1.insert(c5);
a2.insert(Card('d',"4"));
a2.insert(Card('d',"6"));
a2.insert(Card('d',"7"));
a2.insert(Card('d',"8"));
a2.insert(Card('d',"9"));
cout << "Testing on two identical decks" << endl;

playGame(a1, b1);
if(!a1.contains(c1)&&!b1.contains(c1)&&!a1.contains(c2)&&!b1.contains(c2)&&!a1.contains(c3)&&!b1.contains(c3)&&!a1.contains(c4)&&!b1.contains(c4)&&!a1.contains(c5)&&!b1.contains(c5)){
    cout << "playGame() common card game passed: both the decks are the empty after" << endl;
}
else{
    cout <<  "playGame() common card game failed: there are still cards that are remaining " << endl;
}

}
