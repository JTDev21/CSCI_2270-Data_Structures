#include<iostream>
#include<cmath>
#include<iomanip>
#include <string>
#include "StackCalculator.hpp"

using namespace std;

int main()
{
  // stack to hold the operands
  StackCalculator stack;

  int numElement = 0;
  string* inparr = new string[50];

  // enter a number
  string number;
  cout << "Enter the operators and operands ('+', '*') in a prefix format" << endl;

  bool isEqual = false;
  while(!isEqual)
  {
    /* TODO
      1. Read input (operators and operands) until you encounter a "="
      2. store them in inparr
    */
    cout << "#> ";
    getline(cin, number);

    if(number == "=")
    {
      isEqual = true;
    }
    else
    {
      inparr[numElement] = number;
      numElement++;
    }
  }
  
  /* TODO - If the inparr is empty then print "No operands: Nothing to evaluate"
            else call the evaluate function
  */
  if(numElement == 0)
  {
    std::cout << "No operands: Nothing to evaluate" << std::endl;
  }
  else
  {
    /* TODO - Validate the expression
      1. If valid then print the result cout << "Result= "<<result << endl;
      2. Else, print "Invalid expression"*/
    if(stack.evaluate(inparr, numElement))
    {
      std::cout << "Result= "<< stack.peek()->number << std::endl;
    }
    // else
    // {
    //   std::cout << "Invalid expression" << std::endl;
    // }
  }
  return 0;
}


// int main()
// {
//   StackCalculator calc;
//   string *s = new string[50];
//   s[0] = "*";
//   s[1] = "+";
//   s[2] = "1.4";
//   s[3] = "1.4";
//   s[4] = "100";
//   calc.evaluate(s, 5);
//   cout << "(1.4 + 1.4) * 100 = " << calc.peek()->number << endl;
//   calc.pop();
//   if(!calc.peek()) cout << "Correct!" << endl;
//   else cout << "Nope." << endl;

//   return 0;
// }