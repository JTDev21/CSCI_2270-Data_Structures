#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// C++ program to find the execution time of code
int main()
{
   using namespace std::chrono;
   
   auto start = chrono::steady_clock::now();

   this_thread::sleep_for(std::chrono::seconds(4));
   // what you want to time goes in here
   // e.g. call to bubble sort

   auto end = steady_clock::now();

   cout << "Elapsed time in nanonsecond : "
        << duration_cast<nanoseconds>(end-start).count()
        << " ns" << endl;

   cout << "Elapsed time in microseconds: "
        << duration_cast<microseconds>(end-start).count()
        << " µs" << endl;

   cout << "Elapsed time in milliseconds : "
        << duration_cast<milliseconds>(end-start).count()
        << " ms" << endl;

   cout << "Elapsed time in seconds : "
        << duration_cast<seconds>(end-start).count()
        << " sec" << endl;

   return 0;
}

