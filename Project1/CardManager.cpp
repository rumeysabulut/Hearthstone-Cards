//
//  CardManager.cpp
//  Project1
//
//  11.10.2017
// Rumeysa Bulut
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "CardManager.hpp"
using namespace std;

CardManager::CardManager(const char *filename, const char *procedure, const char *sortAlgo, const char *outputFile){
    
    ifstream inputFile;
    inputFile.open(filename);
    setoutputFile(outputFile);
    string line;

    if(!inputFile)
        cout<< "Error opening output file" << endl;
    
    while(getline(inputFile,line)){
        newCardDeck.push_back(Card(line));
    }
    
    decideProcedure(procedure, sortAlgo);
    
}
void CardManager::setoutputFile(const char *outputname ){
    this->outputFile = outputname;
}
const char* CardManager::getOutputFile(){
    return outputFile;
}
void CardManager::decideProcedure(string procedure, string sortType){
    if( procedure == "-full"){
        fullSort(sortType);
    }
    if( procedure == "-filter" ){
        filterSort(sortType);
    }
}

void CardManager::fullSort(string& sortType){
    if(sortType == "-i"){
        clock_t start = clock();
        full_insertion(newCardDeck.size());
        clock_t end = clock();
        double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
        cout << "Time elapsed for full insertion sort:" << elapsed_time << " seconds" << endl;
    }
    
        
    else{
        clock_t start = clock();
        full_mergeSort(0, newCardDeck.size()-1);
        clock_t end = clock();
        double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
        cout << "Time elapsed for full merge sort:" << elapsed_time << " seconds" << endl;
    }
    
    
    writeSorted_toFile();
}

void CardManager::filterSort(string& sortType){
    if(sortType == "-i"){
        clock_t start = clock();
        filter_insertion(newCardDeck.size());
        clock_t end = clock();
        double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
        cout << "Time elapsed for filter insertion sort:" << elapsed_time << " seconds" << endl;

    }
    
    
    else{
        clock_t start = clock();
        filter_mergeSort(0, newCardDeck.size()-1);
        clock_t end = clock();
        double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
        cout << "Time elapsed for filter merge sort:" << elapsed_time << " seconds" << endl;
    }
    writeSorted_toFile();
}

void CardManager::full_insertion(long n){
    Card key;
    long i;
    for(long j=1; j<n; j++){
        key = newCardDeck[j];
        i = j-1;
        while(i >= 0 ){
            if(newCardDeck[i].getClassname() > key.getClassname()){
                newCardDeck[i+1] = newCardDeck[i];
            }
            else if(newCardDeck[i].getClassname() == key.getClassname()){    //If class names are same
                if(stoi(newCardDeck[i].getCost()) > stoi(key.getCost())){           //Then compares costs
                    //If I compare them as strings, then string "2" is greater than string "10"
                    newCardDeck[i+1] = newCardDeck[i];
                }
                else if(stoi(newCardDeck[i].getCost()) == stoi(key.getCost())){          //If costs are same
                    if(newCardDeck[i].getname() > key.getname()){       //Then compares names
                        newCardDeck[i+1] = newCardDeck[i];
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }   //end of classname if
            else {
                break;
            }
            i--;
        } //end of while
        newCardDeck[i+1] = key;
    } //end of for
}
void CardManager::full_mergeSort(long p, long r){
    if(p < r){
        long q = (p + r)/2;
        full_mergeSort(p, q);
        full_mergeSort(q+1, r);
        full_merge(p, q, r);
    }
}
void CardManager::full_merge(long p, long q, long r ){
    long n1 = q-p+1;
    long n2 = r-q;
    vector<Card>L;
    vector<Card>R;
    long i,j;
    
    for(i=0; i<n1; i++){
        L.push_back(newCardDeck[p+i]);
    }
    
    for(j=0; j<n2; j++){
        R.push_back(newCardDeck[q+j+1]);
    }
    L.push_back(Card());        //This is the last card on the deck. All attributes are 'zz' so the
    R.push_back(Card());        //function can compare the actual last card with this 'zz' card.
                                //It is like INT_MAX when sorting integer values
    i=j=0;
    for(long k=p; k<=r; k++){
        
        if(L[i].getClassname() < R[j].getClassname()){
            newCardDeck[k] = L[i];
            i++;
        }
        else if(L[i].getClassname() == R[j].getClassname()){
            if(stoi(L[i].getCost()) < stoi(R[j].getCost())){
                newCardDeck[k] = L[i];
                i++;
            }
            else if(stoi(L[i].getCost()) == stoi(R[j].getCost())){
                if(L[i].getname() < R[j].getname()){
                    newCardDeck[k] = L[i];
                    i++;
                }
                else{
                    newCardDeck[k] = R[j];
                    j++;
                }
            }
            else{
                newCardDeck[k] = R[j];
                j++;      //second else if
            }
        }
        else{
            newCardDeck[k] = R[j];
            j++;      //first else if
        }
    }
}

void CardManager::filter_insertion(long n){         //only by type
    Card key;
    long i;
    for(long j=1; j<n; j++){
        key = newCardDeck[j];
        i = j-1;
        while(i >= 0 && newCardDeck[i].getType() > key.getType()){
            newCardDeck[i+1] = newCardDeck[i];
            i--;
        }
        newCardDeck[i+1] = key;
    }
    
}

void CardManager::filter_mergeSort(long p, long r){
    if(p < r){
        long q = (p + r)/2;
        filter_mergeSort(p, q);
        filter_mergeSort(q+1, r);
        filter_merge(p, q, r);
    }
}

void CardManager::filter_merge(long p, long q, long r){
    long n1 = q-p+1;
    long n2 = r-q;
    vector<Card>L;
    vector<Card>R;
    long i,j;
    
    for(i=0; i<n1; i++){
        L.push_back(newCardDeck[p+i]);
    }
    
    for(j=0; j<n2; j++){
        R.push_back(newCardDeck[q+j+1]);
    }
    L.push_back(Card());        //This is the last card on the deck. All attributes are 'zz' so the
    R.push_back(Card());        //function can compare the actual last card with this 'zz' card.
                                //It is like INT_MAX when sorting integer values
    i=j=0;
    for(long k=p; k<=r; k++){
        if(L[i].getType() <= R[j].getType()){
            newCardDeck[k] = L[i];
            i++;
        }
        else{
            newCardDeck[k] = R[j];
            j++;
        }
    }
    
}


void CardManager::writeSorted_toFile(){
    ofstream outputFile;
    const char* outputFname = getOutputFile();
    outputFile.open(outputFname);
    
    for (int i = 0; i < newCardDeck.size() ; i++ ) {
        outputFile << newCardDeck[i].getname() << '\t' << newCardDeck[i].getClassname() << '\t' << newCardDeck[i].getRarity() << '\t' << newCardDeck[i].getCardset() << '\t' << newCardDeck[i].getType() << '\t' << newCardDeck[i].getCost() << endl;
    }
}

