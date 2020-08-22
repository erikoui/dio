// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
int decksize = 52*4;
int handsize = 4;

void printhand(std::vector<int>& hand) {
    int i;
    for (i = 0; i < hand.size(); i++) {
        std::cout << hand[i] << " ";
    }
    std::cout << std::endl;
}
void filldeck(std::vector<int>& deck) {
    deck.clear();
    deck.resize(decksize);
    int i;
    for (i = 0; i < decksize; i++) {
        deck[i] = i %13+1;
    }
}

void shuffledeck(std::vector<int>& deck, std::vector<int>& scarts) {
    int i, i1, i2, temp;
    scarts.clear();
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

void deal(std::vector<int>& deck, std::vector<int>& hand) {
    hand.clear();
    int i;
    for (i = 0; i < handsize; i++) {
        hand.push_back(deck[0]);
        deck.erase(deck.begin());
    }
}

class player {
    int playstyle;
    int points;
    player() {
        playstyle = 0;
        points = 0;
    }

    void play(std::vector<int>& hand, std::vector<int>& deck) {
        if (playstyle == 0) {//random moves
            std::cout << "aa";
        }
    }
};


int main()
{
    srand(time(NULL));
    std::cout << "Hello World!\n";
    std::vector<int> deck, RANDhand, MAXhand, MIDhand, scarts;
    int MAXsum, RANDsum;
    int i;
    int max_turns = 1;
    for(max_turns=1;max_turns<100;max_turns++){
        MAXsum = 0;
        RANDsum = 0;
        for (i = 0; i < 1000; i++) {
            //shuffle and deal
            filldeck(deck);
            shuffledeck(deck, scarts);
            deal(deck, RANDhand);
            deal(deck, MAXhand);
            deal(deck, MIDhand);

            int j;
            //play the game
            for (j = 0; j < max_turns; j++) {
                //rando plays
                int r = rand() % 2;
                int s = rand() % 4;
                if (r == 1) {//draw from deck
                    scarts[0]=RANDhand[s];
                    RANDhand[s] = deck[0];
                    deck.erase(deck.begin());
                }
                else {
                    int t = scarts[0];
                    scarts[0] = RANDhand[s];
                    RANDhand[s] = t;
                }

                //max diff plays
                int c;
                if (scarts[0] < 7) {//pick it up
                    c = scarts[0];
                }
                else {
                    c = deck[0];
                    deck.erase(deck.begin());
                }

                if ((MAXhand[0] - c) > (6.5 - c)) {//put in left better option than mid
                    if ((MAXhand[3] - c) > (MAXhand[0] - c)){//put in right better option than left
                        scarts[0] = MAXhand[3];
                        MAXhand[3] = c;
                    }
                    else {
                        scarts[0] = MAXhand[0];
                        MAXhand[0] = c;
                    }
                }
                else {//put it in some random place cuz i cba to keep track of it
                    if (c < 7) {
                        s = rand() % 2 + 1;
                        scarts[0] = MAXhand[s];
                        MAXhand[0] = c;
                    }
                    else {
                        scarts[0] = c;
                    }
                }
            }
            //add up stats
            for (j = 0; j < 4; j++) {
                RANDsum += RANDhand[j] > 10 ? 10 : RANDhand[j];
                MAXsum += MAXhand[j] > 10 ? 10 : MAXhand[j];
            }
        }
        std::cout << "For " << max_turns << " turns, max diff has " << MAXsum / 100 << " points and rando has " << RANDsum / 100 << " points on average" << std::endl;
    }
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
