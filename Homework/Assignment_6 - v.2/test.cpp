#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "A";
    string str2 = "A";

    int value = str1.compare(str2);
    std::cout << value << std::endl;
    return 0;
}