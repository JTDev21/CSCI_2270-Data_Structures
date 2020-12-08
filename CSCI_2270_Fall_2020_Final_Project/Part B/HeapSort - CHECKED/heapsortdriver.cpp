#include "heapsort.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <string>
#define INTERVAL 100

// g++ -std=c++11 heapsort.cpp heapsortdriver.cpp
// ./a.out dataSetA.csv

// int main()
// {
//     HeapSort HS(7);
//     for(int i = 0; i < 7; ++i)
//     {
//         HS.insert(i);
//     }
//     HS.heapSort();
//     HS.checkSort();
// }


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
    float sort[100];
    
    int factor = 1;
    
    while(factor * INTERVAL <= 10000)
    {
        int maxSize = factor * INTERVAL;
        HeapSort HS(maxSize);

        for(int i = 0; i < maxSize; ++i)
        {
            HS.insert(testData[i]);
        }


        auto start = std::chrono::steady_clock::now();

            HS.heapSort();
        
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        auto avgSearchTime = duration / INTERVAL;
        // std::cout << "Average Search Time [" << factor << "] - " << avgSearchTime << " ns" << std::endl;
        sort[(maxSize / INTERVAL) - 1] = avgSearchTime;
        
        HS.checkSort();

        factor += 1;
    }

    // ----------------------Write delta records into csv file
    std::ofstream myFile;
    myFile.open("HeapSort Deltas1.csv", std::ios::app);
    for(int i = 0; i < INTERVAL; ++i)
    {
        myFile << sort[i] << '\n';
    }
    
    return 0;
}