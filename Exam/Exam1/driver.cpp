#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "SLL.hpp"

int main()
{
  SLL s1("demo");
  // SLL s1; // // Uninitialized for empty linked list test case
  cout<< "before"  << endl;
  s1.displayList();
  std::cout << std::endl;

  // // split string into headOne and headTwo
  string searchKey = "fluffy";

  // // Check for non existing value
  // string searchKey = "non-existin node";

  // // Check search key in the beginneing
  // string searchKey = "che";

  // // Test Cases
  // string searchKey = "the";

  // int result = 666;
  std::cout << "-----" << std::endl;
  int result = s1.split(searchKey);
  // result = s1.split(searchKey); // // headTwo must be not empty
  std::cout << "Returned Value: " << result << std::endl;
  std::cout << "-----" << std::endl;
  std::cout << std::endl;
  cout<< "after: " << endl;
  s1.displayList();

  return 0;
}


// int main()
// {
//   SLL s2;
//   string def[]= {"0","1","2","3","4","5","6","7"};
//   s2.insert(nullptr, def[0]);
//   for(int i=1;i<8;i++)
//   {
//       Node* prev = s2.search(def[i-1]);
//       s2.insert(prev, def[i]);
//   }
//   s2.displayList();
//   s2.split("7");
//   std::cout << "---" << std::endl;
//   s2.displayList();
// }