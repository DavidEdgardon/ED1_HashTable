#include <conio.h>
#include <iostream>
#include "hashtable.h"

using namespace std;

int main()
{
    hashtable HT;
    HT.addItem();
    HT.addItem();
    HT.addItem();
    HT.printHashTable();
    HT.deleteItem();
    HT.printHashTable();
  //  HT.searchItem();
    HT.totalTiempo();
    _getch();
}