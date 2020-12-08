#include "heapsort.hpp"
#include <iostream>
#include <math.h>
#define DEFAULT_VAL 0

HeapSort::HeapSort(int size)
{
    SIZE = size;
    numElements = 0;
    arr = new int[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = DEFAULT_VAL;
    }
}

HeapSort::~HeapSort()
{
    // std::cout << "deleting arr[" << numElements << "]" << std::endl;
    delete[] arr;
}

void HeapSort::insert(int key)
{
    if(numElements <= SIZE)
    {
        arr[numElements] = key;
        ++numElements;
    }
}

bool HeapSort::search(int key)
{
    for(int i = 0; i < numElements; ++i)
    {
        if(arr[i] == key)
            return true;
    }
    return false;
}

void HeapSort::display()
{
    for(int i = 0; i < numElements; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void HeapSort::maxHeapify(int x)
{
    int largest = x;
    int left = 2*x + 1;
    int right = 2*x + 2;

    if(left < SIZE && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < SIZE && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != x)
    {
        // Swap
        int temp = arr[x];
        arr[x] = arr[largest];
        arr[largest] = temp;
        maxHeapify(largest);
    }
}

void HeapSort::heapSort()
{
    for(int i = floor(numElements / 2) - 1; i >= 0; i--) // Building heap is O(n)
    {
        maxHeapify(i);
        // std::cout << i << ' ' << arr[i] << std::endl;
    }

    for(int i = numElements - 1; i > 0; --i) // Heapify is O(log n)
    {
        // Pop off head, by switching head with last node and decrease heapSize
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        --SIZE;
        maxHeapify(0); // Rebuild heap starting at head
    }
}

void HeapSort::checkSort()
{
    for(int i = 0 ; i < numElements-1; ++i)
    {
        if(arr[i] > arr[i+1])
        {
            std::cout << arr[i] << " > " << arr[i+1] << std::endl;
            std::cout << "Sorting Array has failed" << std::endl;
            break;
        }
    }
}