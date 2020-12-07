// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"

using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash value
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    node *pres = table[index];
    while(pres != NULL) 
    {
        if(pres->key == key) 
        {
            return pres;
        }
        pres = pres->next;
    }
    return pres;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        node *n = new node;
        n->key = key;

        int idx = hashFunction(key);
        if(table[idx] == nullptr)
        {
            table[idx] = n;
        }
        else
        {
            // Inserting new node at head because O(1) and not tail because O(n)
            node *oldHead = table[idx];
            table[idx] = n;
            n->next = oldHead;
        }
    }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i << " | ";
        node *pres = table[i];
        while(pres != NULL)
        {
            std::cout << pres->key << " ";
            pres = pres->next;
        }
        std::cout << std::endl;
    }
}
