#pragma once
#include <iostream>
#include <vector>

struct Node {
    int key;
    int value;
    Node* next;
    Node(int key = 0, int value = 0, Node* next = nullptr) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class HashTable {
private:
    std::vector<int> order;
    Node* arr;
    int buffer;
    int size;
    int hashFunc(int key) {
        return key % buffer;
    }
public:
    HashTable();
    HashTable(const HashTable&);
    HashTable(HashTable&&);
    ~HashTable();
    HashTable& operator=(HashTable& hashTable)
    {
        if (this != &hashTable) {
            HashTable local(hashTable);
            std::swap(arr, local.arr);
            std::swap(buffer, local.buffer);
            std::swap(size, local.size);
        }
        return *this;
    }
    HashTable& operator=(HashTable&& hashTable)
    {
        if (this != &hashTable) {
            std::swap(arr, hashTable.arr);
            std::swap(buffer, hashTable.buffer);
            std::swap(size, hashTable.size);
        }
        return *this;
    }
    void add(int, int);
    void remove(int);
    Node* indexOf(int);
    void empty();
    bool isEmpty();
    Node* getArr();
    int getLength();
    int getBuffer();
    std::vector<int> getOrder();
    void print();
};