//
//  CardManager.cpp
//  Project1
//
//  Created by Rumeysa Bulut on 10.10.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

//FULL INSERTION, FULL MERGE, FILTER MERGE KALDI. ZAMANI YAZMA KALDI

#include <iostream>
#include <fstream>
#include <sstream>
#include "CardManager.hpp"
using namespace std;
CardManager::CardManager(const char *filename, const char *procedure, const char *sortAlgo, const char *outputFile){
    // vector<Card> newCardDeck;
    ifstream inputFile;
    inputFile.open(filename);
    string line;

    if(!inputFile)
        cout<< "Error opening output file" << endl;
    
    while(getline(inputFile,line)){
        cout <<" ---"<<endl;
        newCardDeck.push_back(Card(line));
    }
    
    decideProcedure(procedure, sortAlgo);
}
void CardManager::decideProcedure(string procedure, string sortType){
    if( procedure == "-full"){
//        cout<< "Full Sort"<<endl;
        fullSort(sortType);
    }
    if( procedure == "-filter" ){
//        cout<< "Filter Sort"<<endl;
        filterSort(sortType);
    }
}

void CardManager::fullSort(string& sortType){
    if(sortType == "-i"){
//        cout<<"Insertion"<<endl;
        full_insertion(newCardDeck.size());
        
    }
    else{
//        cout<<"Merge"<<endl;
        full_merge(0, newCardDeck.size()-1);
    }
}
void CardManager::filterSort(string& sortType){
    if(sortType == "-i"){
//        cout<<"Icerdeyim"<<endl;
//        cout<<"Insertion"<<endl;
        filter_insertion(newCardDeck.size());
    }
    else{
 //       cout<<"Merge"<<endl;
        filter_merge(0, newCardDeck.size()-1);
    }
}
void CardManager::full_insertion(long n){
    
}
void CardManager::full_merge(long p, long r ){
    
}
void CardManager::filter_insertion(long n){         //only by type
    Card key;
    int i;
    for(int j=1; j<n; j++){
        key = newCardDeck[j];
        i = j-1;
        while(i >= 0 && newCardDeck[i].getType() > key.getType()){
            newCardDeck[i+1] = newCardDeck[i];
            i--;
        }
        newCardDeck[i+1] = key;
    }
    writeSorted_toFile("sorted.txt");
}

void CardManager::filter_merge(long p, long r){
    
}
void CardManager::writeSorted_toFile(const char *outputFname){
    /* FOR DEBUG
    cout <<"I am in writing to file function"<<endl;
    for(int i=0; i<newCardDeck.size(); i++)
        cout<<newCardDeck[i].getType()<<endl;
    */
    
    ofstream outputFile;
    outputFile.open(outputFname);
    
    for (int i = 0; i < newCardDeck.size() ; i++ ) {
        outputFile << newCardDeck[i].getname() << '\t' << newCardDeck[i].getClassname() << '\t' << newCardDeck[i].getRarity() << '\t' << newCardDeck[i].getCardset() << '\t' << newCardDeck[i].getType() << '\t' << newCardDeck[i].getCost() << endl;
    }
}
