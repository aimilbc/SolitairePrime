//
//  Deck.cpp
//  c++Exercise
//
//  Created by AIMI ROSS on 9/14/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include <stdio.h>
#include "Deck.h"
#include "Card.h"
#include <time.h>
//#include <string>
using namespace std;

Deck::Deck()
{
    top= 0;
    Card();
    int x = 0;
    char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suit[] = {'S', 'H', 'D', 'C'};
    for (int s=0; s < 4; s++)
    {
        for(int r = 0; r < 13; r++)
        {
            if (r==9){
                storage[x]= string() + "10" + suit[s];
            }else
                storage[x]= string() + ranks[r] + suit[s];
            Card::setCard(ranks[r], suit[s]);
            x++;
        }
        
    }
}
Deck::~Deck(){};
void Deck::showDeck()
{
    for(int x = 0; x < 52 ; x++){
        if (x != 12 && x != 25 && x != 38 && x != 51){
            cout << storage[x] << " ";
        }
        else
            cout << storage[x] << endl;
    }
}
void Deck::shuffle(){
    srand (static_cast<unsigned int>(time(NULL)));//define the seed number to generate random first before the for loop.also can put a large integer.
    
    for (int i = 0; i < 10000; i++){
        int x = rand()%52; // will give us random numbers between 0 through 51
        int y = rand()%52;
        string temp = storage[x];
        storage[x] = storage[y];
        storage[y] = temp;
    }
    cout << "The deck has been shuffled....!!!" << endl;
    // showDeck(); // display to check the shuffled deck
}

Card Deck::deal(){
    //cout << storage[top] << endl;
    string temp1 = storage[top];
    char temp2[3];
    temp1.copy(temp2,3);
    char r = temp2[0];
    char s = ' ';
    // cout << r << " " << s << endl;  // check the value of char r&s.
    if (r=='1'){
        r = 'T';
        s = temp2[2];
    }else{
        r = temp2[0];
        s = temp2[1];
    }
    top++;
    return Card(r,s);
}

int Deck::cardLeft(){
    return 52 - top;
}

void Deck::refreshDeck(){
    top= 0;
    Card();
    int x = 0;
    char ranks[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suit[] = {'S', 'H', 'D', 'C'};
    for (int s=0; s < 4; s++)
    {
        for(int r = 0; r < 13; r++)
        {
            if (r==9){
                storage[x]= string() + "10" + suit[s];
            }else
                storage[x]= string() + ranks[r] + suit[s];
            Card::setCard(ranks[r], suit[s]);
            x++;
        }
        
    }
}
