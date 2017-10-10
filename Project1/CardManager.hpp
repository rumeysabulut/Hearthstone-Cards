//
//  CardManager.hpp
//  Project1
//
//  Created by Rumeysa Bulut on 10.10.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#ifndef CardManager_hpp
#define CardManager_hpp

#include <string>
#include <vector>
#include "Card.hpp"
using namespace std;
class CardManager{
private:
    vector<Card> newCardDeck;
public:
    CardManager(const char *, const char *,const char *,const char * );      //It reads from file to cardDeck so it creates cardDeck.
    void decideProcedure(string, string);
    void fullSort(string&);
    void filterSort(string&);
    void full_insertion(long);
    void full_merge(long, long);
    void full_mergeSort(long, long, long);
    void filter_insertion(long);
    void filter_merge(long, long);
    void filter_mergeSort(long, long, long);
    void writeSorted_toFile(const char *);
};
#endif /* CardManager_hpp */
