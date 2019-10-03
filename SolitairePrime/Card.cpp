//
//  Card.cpp
//  c++Exercise
//
//  Created by AIMI ROSS on 9/10/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(){
    rank = ' ';
    suit = ' ';
}
Card::Card(char r, char s){
    rank = r;
    suit = s;
    // cout << r << " and " << s << ", and " << rank << " and " << suit << " in Card(char r, char s)" << endl;
}
void Card::setCard(char r, char s){
    Card(r, s);
    // cout << r << " and " << s << " in setCard" << endl;
}
int Card::getValue(){
    
    // cout << "In getValue, the rank is " << rank << endl; // check if rank stores the correct value
    
    // pass rank's value when its called.
    if (rank == '2' || rank == '3' || rank == '4' || rank == '5' || rank == '6' || rank == '7' || rank == '8' || rank == '9')
        return rank - 48;
    else if (rank == 'A')
        return 1;
    else
        return 10;
}
void Card::showCard(){
    // int rValue = getValue();  USE THIS TO GET VALUE OF RANK
    
    if (rank != 'T'){
        cout << rank << suit << ", ";
    }else
        cout << rank - 74 << suit<< ", ";
}
