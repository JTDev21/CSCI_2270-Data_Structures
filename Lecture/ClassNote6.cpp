// Pointers vs reference
    // References are less powerful than pointers.
    // References cannot be used for implementing data structures.
    // Pointer can be assigned to NULL, but references cannot.

// Parameter passing
    // pass by name
    // pass by value-result
    // pass by value
    // pass by reference
    // pass by array
    // pass by pointer


#include <iostream>
using namespace std;

// int main()
// {
//     int arrSize = 100;
//     int *arr = new int[arrSize];
//     int numElements = 0;

//     for(int i = 0; i < arrSize; i++)
//     {
//         arr[i] = 0;
//         numElements++;
//     }

//     arrSize *= 2;
//     int *temp_arr = new int[arrSize*2];
//     for(int i = 0; i < numElements; i++)
//     {
//         temp_arr[i] = arr[i];
//     }
//     for(int i = numElements; i < arrSize*2; i++)
//     {
//         temp_arr[i] = 1;
//     }
//     delete[] arr;
//     arr = temp_arr;
//     delete[] temp_arr;

//     numElements = 0;
//     for(int i = 0; i < arrSize; i++)
//     {
//         cout << arr[i] << endl;
//         numElements++;
//     }
//     cout << "numElements: " << numElements << endl;
//     return 0;
// }