//
//  main.cpp
//  c++Exercise
//  Name: AIMI ROSS
//  Class (CECS 282-05)
//  Project Name(Prog 1 - Solitaire Prime)
//  Due Date (09/17/2019)
//
#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std;

void showingOptions();
int getPickedNum();
int isPrime(int num);

int main()
{
    int pickedNum = 0;
    int pileValue = 0;
    int count = 0;
    cout << "Welcome to Solitaire Prime!" << endl;
    showingOptions();
    pickedNum = getPickedNum();
    Deck ugh;
    while (pickedNum != 5){
        if(pickedNum == 1){
            ugh.refreshDeck();
            cout << endl;
            showingOptions();
            pickedNum = getPickedNum();
        }else if (pickedNum == 2){
            ugh.showDeck(); // it should be Space: AS, 2S, 3S,… 10S, JS, QS, KS and keep going with Heart, Diamond, Clover
            cout << endl;
            showingOptions();
            pickedNum = getPickedNum();
        }else if(pickedNum == 3){
            ugh.shuffle(); // display shuffled deck
            cout << endl;
            showingOptions();
            pickedNum = getPickedNum();
        }else if(pickedNum == 4){
            cout << "Playing Solitaire Prime!!!!" << endl << endl;
            // cout << ugh.cardLeft() << " cards are in the deck before" << endl;  //*checking the how many cards in the deck
            while (ugh.cardLeft()>0){
                Card eww = ugh.deal();
                eww.showCard();
                pileValue += eww.getValue();
                // cout << "pilevalue is " << pileValue << endl;
                if (isPrime(pileValue) == 1){
                    cout << "Prime: " << pileValue << endl;
                    pileValue = 0;
                    count++;
                }
            }
            if (ugh.cardLeft() == 0){
                if(isPrime(pileValue) == 1){
                    cout << "Winner in " << count << " piles!" << endl << endl;
                showingOptions();
                pickedNum = getPickedNum();
                }else {
                cout << "\nLooser. \nThe last pile's value was " << pileValue << "." <<endl << endl;
                showingOptions();
                pickedNum = getPickedNum();
                }}
        }else {
            cout << "Invalid number. Please try again!" << endl << endl;
            showingOptions();
            pickedNum = getPickedNum();
        }
    }
    if (pickedNum == 5){
        cout << "The game will be terminated, good bye!" << endl << endl;
        cin.get();
    }
    return 0;
}


void showingOptions(){
    cout << "Please pick number from the following option." << endl;
    cout << "1) New Deck" << endl;
    cout << "2) Display Deck" << endl;
    cout << "3) Shuffle Deck" << endl;
    cout << "4) Play Solitaire Prime" << endl;
    cout << "5) Exit" << endl;
}

int getPickedNum(){
    int pickedNum = 0;
    cout << "---------------Your choice: ";
    cin >> pickedNum;
    return pickedNum;
}

int isPrime(int pileValue){
    if (pileValue ==1 ){
        return 0;
    }
    for(int z = 2; z <= pileValue/2; z++){
        if(pileValue%z ==0){
            return 0;
        }
    }
    return 1;
}
