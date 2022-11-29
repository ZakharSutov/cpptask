#include <iostream>
#include "hashtable.h"
#include "iterator.h"
using namespace std;

int main()
{
    HashTable table;
    table.add(4, 20);
    table.add(2, 10);
    table.add(12, 15);
    table.add(22, 14);
    table.add(24, 30);
    cout << "key 24: " << table.indexOf(24)->value << endl;
    table.remove(4);
    cout << "deleted key 4: " << (table.indexOf(4) == nullptr) << endl;
    cout << "key 24: " << table.indexOf(24)->value << endl;
    table.add(44, 40);
    cout << "key 44: " << table.indexOf(44)->value << endl;

    table.print();

    Iterator* iter = new Iterator(table);
    iter->start();
    cout << iter->getValue() << " ";
    while (!iter->finish()) {
        iter->next();
        cout << iter->getValue() << " ";
    }
    cout << "\n";

    cout << "Is empty: " << table.isEmpty() << endl;
    table.empty();
    cout << "Is empty: " << table.isEmpty() << endl;
    return 0;
}