#include "iterator.h"
#include "hashtable.h"
#include <iostream>

Iterator::Iterator(HashTable& hashTable) {
    arr = hashTable.getArr();
    order = hashTable.getOrder();
    buffer = hashTable.getBuffer();
    length = hashTable.getLength();
    length = hashTable.getOrder().size();
}

void Iterator::start() {
    index = 0;
    if (length != 0) {
        while (arr[index].next == nullptr) {
            index++;
        }
        elem = arr[index].next;
    }
}

void Iterator::next() {
    if (!finish()) {
        if (elem->next == nullptr) {
            index++;
            while (index < buffer && arr[index].next == nullptr) {
                index++;
            }
            elem = arr[index].next;
        }
        else {
            elem = elem->next;
        }
    }
}

bool Iterator::finish() {
    return index > length;
}

int Iterator::getValue() {
    return elem->value;
}