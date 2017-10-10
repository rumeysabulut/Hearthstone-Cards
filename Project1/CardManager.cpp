//
//  CardManager.cpp
//  Project1
//
//  Created by Rumeysa Bulut on 10.10.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#include <iostream>
#include "CardManager.hpp"


void CardManager::decideProcedure(string procedure, string sort){
    if( procedure == "-full"){
        cout<< "Full Sort"<<endl;
    //    decideSort(sort);
    }
    if( procedure == "filter" ){
        cout<< "Filter Sort"<<endl;
   //     decideSort(sort);
    }
}
/*
void CardManager::decideSort(string sort){
    if(strcmp(sort.c_str(), "-i") == 0){
        
    }
}
*/
