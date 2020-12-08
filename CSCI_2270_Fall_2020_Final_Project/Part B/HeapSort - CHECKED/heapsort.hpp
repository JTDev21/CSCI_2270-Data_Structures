#ifndef HEAPSORT_H
#define HEAPSORT_H

class HeapSort
{
    private:
        int SIZE;
        int *arr;
        int numElements;
        void maxHeapify(int x); // int x is a valid index of the array
    public:
        ~HeapSort();
        HeapSort(int size);
        
        void insert(int key);
        bool search(int key);
        void display();
        void heapSort();
        void checkSort();
        
};

#endif