#include <iostream>
using namespace std;

// int main()
// {
//     int x = 25;
//     int &q = x;

//     q = 100;

//     cout << &x << endl;
//     cout << &q << endl;
//     cout << x << endl;
//     return 0;
// }

// Passing by reference
    // use *& to create a reference to the pointer we passed in

// Returning Pointers
    // int* createArray()
    // {
    //     int arr_ca[2];
    //     arr_ca[0] = 50;
    //     arr_ca[1] = 100;
    //     return arr_ca;
    // }

    // int main()
    // {
    //     int *arr = createArray();
    //     cout << arr[0] << endl;
    //     cout << arr[1] << endl;
    // }
// // ------------------------------------------------------------------------
// int* createArray()
// {
//     int*arr_ca = new int[2]; // Allocate some memory in heap
//     arr_ca[0] = 50;
//     arr_ca[1] = 100;
//     return arr_ca;
// }

// int main()
// {
//     int *arr = createArray();
//     cout << arr[0] << endl;
//     cout << arr[1] << endl;

//     // When the function finish the createArray function will still have memory allocated in the heap
//     // We must delete it, by using delete[] arr
//     // Once finished we must set the pointer (*arr) into a nullptr
//     delete[] arr;
//     arr = nullptr;
// }

// // ------------------------------------------------------------------------
// Return Reference to pointer
double *& getNum()
{
    double num = 1000.00;
    static double *x = &num; // the address of num is stored into the variable x
    return x; // Return the address of x
}

int main()
{
    double N = *getNum(); // dereference the address of x and stored it into the double variable N
    cout << N << endl; // 1000.00
    return 0;
}