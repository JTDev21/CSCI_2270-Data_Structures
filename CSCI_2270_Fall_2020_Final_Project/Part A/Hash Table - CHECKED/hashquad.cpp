#include "hashquad.hpp"
#include <iostream>
#define DEFAULT_EMPTY 0

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new int[tableSize];
    for(int i = 0; i < tableSize; ++i)
    {
        table[i] = DEFAULT_EMPTY;
    }
}

HashTable::~HashTable()
{
    delete[] table;
    table = nullptr;
}

// hash function to map values to key
unsigned int HashTable::hashFunction(int key)
{
    return key % tableSize;
}

int HashTable::searchItem(int key) // Search for a key
{
    int idx = hashFunction(key);    
    if(table[idx] == key)
        return 0;

    for(int i = 0; i < tableSize; ++i)
    {
        ++numOfcollision;
        int quadProbing = (idx + (i*i)) % tableSize;
        if(table[quadProbing] == key)
            return 0;

    }
    std::cout << "Could not find key[" << key << "]" << std::endl;
    return -1;
}

bool HashTable::insert(int key)
{
    int idx = hashFunction(key);
    if(table[idx] == DEFAULT_EMPTY)
    {
        table[idx] = key;
        return true;
    }

    // Using quadratic probing
    // std::cout << "Key[" << key << "] to insert | Collision[i:" << hashFunction(key) << "][Key: " << table[hashFunction(key)] << "]" << std::endl;
    for(int i = 0; i < tableSize; ++i)
    {
        ++numOfcollision;
        int quadProbing = (idx + (i*i)) % tableSize;
        if(table[quadProbing] == DEFAULT_EMPTY)
        {
            table[quadProbing] = key;
            return true;
        }
    }
    return false;
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) 
    {
        std::cout << i << " " << table[i] << std::endl;
    }
}

int HashTable::getNumOfCollision()
{
    // std::cout << "Number of collisions: " << numOfcolision << std::endl;
    int temp = numOfcollision;
    numOfcollision = 0;
    return temp;
}