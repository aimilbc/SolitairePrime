//
//  Card.h
//  c++Exercise
//
//  Created by AIMI ROSS on 9/10/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
    Card();
    Card(char r, char s);
    static void setCard(char r, char s);
    int getValue();
    void showCard();
private:
    char rank;
    char suit;
};
#endif /* Card_h */

