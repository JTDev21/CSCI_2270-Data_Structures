#include <iostream>
#include <string>
using namespace std;

void printString(string *str, int size)
{
    for(int i = size-1; i >= 0; i--)
    {
        std::cout << str[i] << std::endl;
        // std::cout << *(str + i) << std::endl;
    }
}

int main()
{
    string *s = new string[50];
    s[0] = "+";
    s[1] = "2";
    s[2] = "1";
    printString(s, 3);
    return 0;
}