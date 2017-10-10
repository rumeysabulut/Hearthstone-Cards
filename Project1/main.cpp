//
//  main.cpp
//  Project1
//
//  Created by Rumeysa Bulut on 10.10.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#include <iostream>
#include <string>
#include "CardManager.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    //To control arguments, Delete them at the end
    cout << "Full or filter: " << argv[1]<< endl;
    cout << "Insertion or merge: " << argv[2] << endl;
    cout << "Input file: " << argv[3] << endl;
    cout << "Output File:" << argv[4] << endl;
    
   
    string procedure = argv[1];
    string sortAlgo = argv[2];
    CardManager cardDeck;
    cardDeck.decideProcedure(procedure, sortAlgo);
    
    return 0;
}
