//
//  main.cpp
//  Project1
//
//  11.10.2017
// Rumeysa Bulut
//

#include <iostream>
#include <string>
#include "CardManager.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    CardManager cardDeck = CardManager(argv[3], argv[1], argv[2], argv[4] );    //Constructor of CardManager takes all arguments.
    
    return 0;
}
