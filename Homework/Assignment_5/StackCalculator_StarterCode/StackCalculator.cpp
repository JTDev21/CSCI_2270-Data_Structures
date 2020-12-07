#include <iostream>
#include <string>
#include "StackCalculator.hpp"


using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' && !point) point = true;
      else if(s[i]=='.' && point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  //TODO:
  stackHead = nullptr;
}

StackCalculator::~StackCalculator()
{
  //TODO:
  Operand *pres = stackHead;
  while(pres != NULL)
  {
    Operand *temp = pres;
    pres = pres->next;
    stackHead = pres;
    delete temp;
  }
}

bool StackCalculator::isEmpty()
{
	//TODO:
  return (stackHead == NULL);
}

void StackCalculator::push(float number)
{
  //TODO:
  Operand *node = new Operand;
  node->number = number;
  if(isEmpty())
  {
    node->next = nullptr;
  }
  else
  {
    node->next = stackHead;
  }
  stackHead = node;
}

void StackCalculator::pop()
{
	//TODO:
  if(isEmpty())
  {
    std::cout << "Stack empty, cannot pop an item." << std::endl;
  }
  else
  {
    Operand *toBeDeleted = stackHead;
    stackHead = stackHead->next;
    delete toBeDeleted;
  }
}

Operand* StackCalculator::peek()
{
	//TODO:
  if(isEmpty())
  {
    std::cout << "Stack empty, cannot peek." << std::endl;
  }
  return stackHead;
}

bool StackCalculator:: evaluate(string* s, int size)
{
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
  for(int i = size-1; i >= 0; i--)
  {
    if(isNumber(s[i]))
    {
      push(std::stof(s[i]));
      // std::cout << "peek(): " << peek()->number << std::endl;
    }
    else
    {
      if(s[i] == "+" || s[i] == "*")
      {
        if(isEmpty() || stackHead->next == NULL)
        {
          std::cout << "err: not enough operands" << std::endl;
          return false;
        }

        Operand *operand1 = stackHead;
        Operand *operand2 = stackHead->next;

        float x = operand1->number;
        float y = operand2->number;
        pop();
        pop();
        (s[i] == "+") ? push(x+y) : push(x*y);
      }
      else
      {
        std::cout << "err: invalid operation" << std::endl;
        return false;
      }
    }
  }
  return true;
}
