#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

class BubbleSort
{
    private:
        int SIZE;
        int numElements;
        int *arr;
    public:
        BubbleSort(int size);
        ~BubbleSort();

        void insert(int id);
        int search(int id);
        void display();
        void sort();

        void chechSorted();
};

#endif