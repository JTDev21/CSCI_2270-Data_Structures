#include "hashquad.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <string>
#define INTERVAL 100

// g++ -std=c++11 hashquad.cpp hashquaddriver.cpp
// ./a.out dataSetA.csv

int main(int argc, char *argv[])
{
    char *fileName = argv[1]; // Takes a command line argument, filename.
    if(argc != 2)
    {
        std::cout << "[FileName] One command line argument is expected." << std::endl;
        return -1;
    }

    // -------------------Populate testData array-------------------------
    int counter = 0;
    int testData[10000]; // Array to store 10,000 ints

    std::fstream inFile; // Open and read file
    inFile.open(fileName);
    
    if(!inFile.is_open())
    {
        std::cout << "Failed to open file " << fileName << std::endl;
        return -1;
    }

    std::string line;
    while(std::getline(inFile, line, ' ')) // Take whitespace and newline as delimiter
    {
        std::stringstream ss(line); // Convert line into stringstream
        while(std::getline(ss, line, ',')) // Remove comma delimiter
        {
            testData[counter] = stoi(line); // Convert and add test data into testData array
            ++counter;
        }
    }
    
    
    // ------------------------Record delta for insert/search----------
    float insert[100];
    float search[100];
    int insertCollision[100];
    int searchCollision[100];
    
    int factor = 1;
    HashTable hashTable(40009);
    while(factor * INTERVAL <= 10000)
    {
        int maxSize = factor * INTERVAL;
        auto start = std::chrono::steady_clock::now();
        for(int i = maxSize - INTERVAL; i < maxSize; ++i)
        {
            hashTable.insert(testData[i]);
        }
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        auto avgInsertTime = duration / INTERVAL;
        // std::cout << "Avg. insert time [" << (currElement / INTERVAL) << " records] - " << avgInsertTime << " ns" << std::endl;
        insert[(maxSize / INTERVAL) - 1] = avgInsertTime;
        insertCollision[(maxSize / INTERVAL) - 1] = hashTable.getNumOfCollision();

        int randIdx[10000];
        for(int i = 0; i < maxSize; ++i) // Populate randIdx from 0 to maxSize(100 200 300 ... 10000)
        {
            randIdx[i] = i;
        }

        srand(time(NULL));
        for(int i = 0; i < maxSize; ++i) // Shuffle randIdx
        {
            int idx = (rand() + i) % maxSize;
            int temp = randIdx[i];
            randIdx[i] = randIdx[idx];
            randIdx[idx] = temp;
        }

        start = std::chrono::steady_clock::now();
        for(int i = 0; i < INTERVAL; ++i) // Going through 100 elements of randIdx with a random index value for testData
        {
            hashTable.searchItem(testData[randIdx[i]]);
        }
        end = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        auto avgSearchTime = duration / INTERVAL;
        // std::cout << "Average Search Time [" << testData_idx-INTERVAL << " - " << testData_idx << "] - " << avgSearchTime << " ns" << std::endl;
        search[(maxSize / INTERVAL) - 1] = avgSearchTime;
        searchCollision[(maxSize / INTERVAL) - 1] = hashTable.getNumOfCollision();

        factor += 1;
    }
    // hashTable.printTable();

    // ----------------------Write delta records into csv file
    std::ofstream myFile;
    myFile.open("HashTable Deltas1.csv", std::ios::app);
    for(int i = 0; i < INTERVAL; ++i)
    {
        myFile << insert[i] << ',' << search[i] << ',' << insertCollision[i] << ',' << searchCollision[i] << '\n';
    }
    return 0;
}