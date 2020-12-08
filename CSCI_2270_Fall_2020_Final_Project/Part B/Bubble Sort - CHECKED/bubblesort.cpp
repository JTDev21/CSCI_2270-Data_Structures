#include "bubblesort.hpp"
#include <iostream>

BubbleSort::BubbleSort(int size)
{
    SIZE = size;
    numElements = 0;
    arr = new int[size];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = 0;
    }
}

BubbleSort::~BubbleSort()
{
    // std::cout << "Deleting arr[" << SIZE << "]" << std::endl;
    SIZE = 0;
    numElements = 0;
    delete[] arr;
}

void BubbleSort::insert(int id)
{
    if(SIZE > numElements) // Insertion time should be O(1). Since, we know the position of the next empty slot.
    {
        arr[numElements] = id;
        ++numElements;
        return;
    }
    std::cout << "Array is maxed!" << std::endl;
}

int BubbleSort::search(int id)
{
    for(int i = 0; i < numElements; ++i)
    {
        if(arr[i] == id)
            return 0;
    }
    std::cout << "Could not find id " << id << std::endl;
    return -1;
}

void BubbleSort::display()
{
    for(int i = 0; i < numElements; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void BubbleSort::sort()
{
    for(int i = 0; i < numElements-1; ++i)
    {
        for(int j = 0; j < numElements - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                /*
                    if (1 > 0) is true, then swap the values 
                    such that if(0 > 1) is false.
                */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // display();
            }
        }
    }
}

void BubbleSort::chechSorted()
{
    for(int i = 0 ; i < numElements-1; ++i)
    {
        if(arr[i] > arr[i+1] || arr[i] == arr[i+1])
        {
            std::cout << "Sorting Array has failed" << std::endl;
            break;
        }
    }
}