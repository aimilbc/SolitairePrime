//
//  Deck.h
//  c++Exercise
//
//  Created by AIMI ROSS on 9/14/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#ifndef Deck_h
#define Deck_h
#include "Card.h"

#include <string>
using namespace std;

class Deck
{
public:
    Deck();
    void showDeck();
    void shuffle();
    int cardLeft();
    Card deal();
    void refreshDeck();
    ~Deck();
private:
    string storage[52];
    int top;
};

#endif /* Deck_h */
