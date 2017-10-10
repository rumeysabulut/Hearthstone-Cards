//
//  Card.cpp
//  Project1
//
//  Created by Rumeysa Bulut on 10.10.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <vector>
#include "Card.hpp"
using namespace std;
Card::Card(){
    this->name = "zz";
    this->className = "zz";
    this->rarity = "zz";
    this->set = "zz";
    this->type = "zz";
    this->cost = "zz";
}
Card::Card(string line){
    vector<string> CardAttributes;
    stringstream fullLine(line);
    string attribute;
    while(getline(fullLine, attribute, '\t')){
        CardAttributes.push_back(attribute);
    }
    setname(CardAttributes[0]);
    setclassName(CardAttributes[1]);
    setrarity(CardAttributes[2]);
    setCardset(CardAttributes[3]);
    setType(CardAttributes[4]);
    setcost(CardAttributes[5]);
    
    
    //Reading from the file for debug
    for(int i=0; i<CardAttributes.size(); i++)
        cout<<CardAttributes[i]<<"\t";
    
    
}

string Card::getname(){
    return name;
}
string Card::getClassname(){
    return className;
}
string Card::getRarity(){
    return rarity;
}
string Card::getCardset(){
    return set;
}
string Card::getType(){
    return type;
}
string Card::getCost(){
    return cost;
}
void Card::setname(string name){
    this->name = name;
}
void Card::setclassName(string classname){
    this->className = classname;
}
void Card::setrarity(string rarity){
    this->rarity = rarity;
}
void Card::setCardset(string set){
    this->set = set;
}
void Card::setType(string type){
    this->type = type;
}
void Card::setcost(string cost){
    this->cost = cost;
}

