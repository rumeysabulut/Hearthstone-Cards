//
//  Card.hpp
//  Project1
//
//  11.10.2017
// Rumeysa Bulut
//

#ifndef Card_hpp
#define Card_hpp
#include <string>
using namespace std;
class Card{
private:
    string name;
    string className;
    string rarity;
    string set;
    string type;
    string cost;
public:
    Card();
    Card(string);
    string getname();
    string getClassname();
    string getRarity();
    string getCardset();
    string getType();
    string getCost();
    void setname(string);
    void setclassName(string);
    void setrarity(string);
    void setCardset(string);
    void setType(string);
    void setcost(string);
    
};

#endif /* Card_hpp */
