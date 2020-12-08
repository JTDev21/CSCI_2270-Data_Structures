#include "bubblesort.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <string>
#define INTERVAL 100

// g++ -std=c++11 bubblesort.cpp bubblesortdriver.cpp
// ./a.out dataSetA.csv

// // Test Case 1
// int main()
// {
//     BubbleSort bubblesort(13);
//     bubblesort.insert(4);
//     bubblesort.insert(8);
//     bubblesort.insert(1);
//     bubblesort.insert(3);
//     bubblesort.insert(15);
//     bubblesort.insert(11);
//     bubblesort.insert(13);
//     bubblesort.insert(12);
//     bubblesort.insert(6);
//     bubblesort.insert(10);
//     bubblesort.insert(2);
//     bubblesort.insert(7);
//     bubblesort.insert(9);
//     bubblesort.sort();
//     bubblesort.chechSorted();
//     bubblesort.display();
//     return 0;
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
    float sort[100]; // Array to hold the average sorting time
    
    int factor = 1;
    while(factor * INTERVAL <= 10000)
    {
        int n = factor * INTERVAL; // the variable n is considered the max size of the "tempArr"
        BubbleSort bubbleSort(n); // Each time the while loop restart create a new class and increase the size to n. Note, deconstructor has been implemented.

        for(int i = 0; i < n; ++i) // The while loop will increase the number of inserted elements from o to 100 200 300 400 ... 10000
        {
            bubbleSort.insert(testData[i]);
        }

        auto start = std::chrono::steady_clock::now();

            bubbleSort.sort(); // Measure sorting time of 100 200 ... 10000 elements. We should expect O(n^2) because we have 2 for loops.

        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        auto avgSearchTime = duration / INTERVAL;
        // std::cout << "Average Search Time [" << factor << "] - " << avgSearchTime << " ns" << std::endl;
        sort[(n / INTERVAL) - 1] = avgSearchTime; // Add average sorting time to sortDeltas array

        bubbleSort.chechSorted(); // Wouldn't be much of a sorting program if it couldn't sort from ascending order
        // bubbleSort.display();
        factor += 1;
    }


    // ----------------------Write delta records into csv file
    std::ofstream myFile;
    myFile.open("BubbleSort Deltas.csv", std::ios::app);
    for(int i = 0; i < INTERVAL; ++i)
    {
        myFile << sort[i] << '\n';
    }
    
    return 0;
}