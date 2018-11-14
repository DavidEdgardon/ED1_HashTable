//
// Created by ASUS on 11/6/2018.
//

#ifndef ED1HASHTABLE_HASHTABLE_H
#define ED1HASHTABLE_HASHTABLE_H

#include <string>
using namespace std;

class hashtable {

private:
    static const int tablesize = 5;

    struct item{
        string name;
        string drink;
        item *next;
    };

    item *HashTable[tablesize];

public:
    hashtable();
    int Hash(string);
    void addItem();
    void searchItem();
    void deleteItem();
    void printHashTable();
    void totalTiempo();

};


#endif //ED1HASHTABLE_HASHTABLE_H
