//
// Created by ASUS on 11/6/2018.
//

#include "hashtable.h"
#include <iostream>
#include <time.h>

using namespace std;

hashtable::hashtable() {
    for (int x = 0; x < tablesize; x++) //Inicializar la hash
    {
        HashTable[x] = new item;
        HashTable[x]->name = "empty";
        HashTable[x]->drink = "empty";
        HashTable[x]->next = nullptr;
    }
}


int hashtable::Hash(string key) { //Genera el codigo hash
    int hash = 0;
    int index;

    for (int x = 0; x < key.length(); x++)
    {
        hash = hash + (int)key[x];
    }

    index = hash % tablesize;

    return index;
    //Retorna el numero hash
}

void hashtable::addItem() {
    cout << "\nName: ";
    string name;
    cin >> name;

    cout << "Drink: ";
    string drink;
    cin >> drink;

    int index = Hash(name); //Llama a la funcion con el key (que es el nombre)

    if (HashTable[index]->name == "empty") //Si esta vacio, lo agrega
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item *ptr = HashTable[index]; //Temporal
        item *newitem = new item; //Nuevo item
        newitem->name = name;
        newitem->drink = drink;
        newitem->next = nullptr;

        while (ptr->next != nullptr)//recoger hasta que sea nulo
        {
            ptr = ptr->next;
        }

        ptr->next = newitem;//Le doy la posicion newitem para que se ingrese ahi
    }

}

void hashtable::searchItem() {
    cout << "\nName: ";
    string name;
    cin >> name;

    for (int x = 0; x < tablesize; x++)
    {
        item *ptr = HashTable[x]; //temporal, que empieza al principio
        while (ptr != nullptr) //Recoger hasta que sea nulo
        {
            if(ptr->name == name)//Si son iguales imprime la informacion
            {
                cout << "\nNumber: " << x + 1 << endl;
                cout << ptr->name << endl;
                cout << ptr->drink << endl;
                cout << "" << endl;
            }
            ptr = ptr->next;//avanza al siguiente, hasta encontrarlo
        }
    }
}

void hashtable::deleteItem() {
    cout << "\nName: ";
    string name;
    cin >> name;

    item *tmp = nullptr;

    for (int x = 0; x < tablesize; x++)
    {
        item *ptr = HashTable[x];
        if (ptr->name == name)
        {
            ptr->name = "empty";
            ptr->drink = "empty";
        }
       else
        {
            while (ptr != nullptr)
            {
                if (ptr->name == name)
                {
                    tmp->next = nullptr;
                    cout << "ERASE!" << endl;
                    break;
                }
                tmp = ptr;
                ptr = ptr->next;
            }
        }
    }
}

void hashtable::printHashTable() {
    for (int x = 0; x < tablesize; x++)
    {
        item *ptr = HashTable[x];
        cout << "\nNumber: " << x + 1 << endl;
        while (ptr != nullptr)
        {
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "" << endl;
            ptr = ptr->next;
        }

    }
}

