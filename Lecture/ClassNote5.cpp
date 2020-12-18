// pointers
    //  Up to this point, we have used pointers to manipulate data only into memory spaces that were created using other variables. 
        // In other words, the pointer manipulated data into existing memory spaces.
    // So, let's learn about "dynamic variables". We're going to allocate and deallocate memory during program execution using pointers
    // Use new and delete operators to create and destroy dynamic variables, which are reserver words in c++

// Heap Memory (Dynamic memory allocation)
    // The heap is a region of your computer's memory that is not managed automatically for you, and is not as tighly managed by the CPU
        // To allocate memory on the heap, you are responsible for deleting it using delete operator to deallocate that memory once you don't need it any more.
    // How the heap is managed is really up to the runtime environment!
    // If you don't deallocate memory , your program will have what is known as a "memory leak". That is , memory on the heap will still be set aside (and won't be available to other processes).
    // There are debuggers (valgrind) that can help you detect memory leaks.
    // Unlike the stack, the heap does not have size restriction on variable size

    // To use a heap in c++, use the keywords "new" and "delete"


// Activation record ask record frame
#include <iostream>

int main()
{
    int *p;
    p = new int;
    *p = 28;
    delete p;
    return 0;
}