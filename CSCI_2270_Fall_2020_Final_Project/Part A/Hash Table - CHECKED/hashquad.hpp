#ifndef HASHQUAD_H
#define HASHQUAD_H

class HashTable
{
    private:
        int tableSize;  // No. of buckets (linked lists)
        
        // Pointer to an array containing buckets
        int *table;
        int numOfcollision = 0;

    public:
        HashTable(int bsize);  // Constructor
        ~HashTable();

        // inserts a key into hash table
        bool insert(int key);
        int searchItem(int key); // Search for a key

        // hash function to map values to key
        unsigned int hashFunction(int key);

        void printTable();
        int getNumOfCollision();
};

#endif