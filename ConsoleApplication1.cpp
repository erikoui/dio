// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
int decksize = 52;
int handsize = 4;

void printhand(vector<int>& hand) {
    int i;
    for (i = 0; i < hand.size(); i++) {
        cout << hand[i] << " ";
    }
    cout << endl;
}
void filldeck(vector<int>& deck) {
    deck.clear();
    deck.resize(decksize);
    int i;
    for (i = 0; i < decksize; i++) {
        deck[i] = i %13+1;
    }
}

void shuffledeck(vector<int>& deck,vector<int>& scarts) {
    int i, i1, i2, temp;
    for (i = 0; i < 3 * deck.size(); i++) {
        i1 = rand() % deck.size();
        i2 = rand() % deck.size();
        //printf("Swapping %d with %d\n",i1,i2);
        if (i1 != i2) {
            temp = deck[i1];
            deck[i1] = deck[i2];
            deck[i2] = temp;
        }
    }
    scarts.push_back(deck[0]);
    deck.erase(deck.begin());
}

void deal(vector<int>& deck, vector<int>& hand) {
    int i;
    for (i = 0; i < handsize; i++) {
        hand.push_back(deck[0]);
        deck.erase(deck.begin());
    }
}

class player{
    int playstyle;
    int points;
    player() {
        playstyle = 0;

    }

    void play(std::vector<int>& hand, std::vector<int>& deck) {
        if (playstyle == 0) {//random moves
            cout << "aa";
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> deck, hand, scarts;
    filldeck(deck);
    shuffledeck(deck,scarts);
    deal(hand, deck);
    printhand(hand);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
