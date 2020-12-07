#include <iostream>
#include <fstream>
#include <string>

int addToArrayAsc(float sortedArray[], int numElements, float newValue)
{
    bool sorted_status = false;
    int newValue_pos = numElements;
    while (!sorted_status)
    {
        if(sortedArray[newValue_pos - 1] <= newValue || newValue_pos == 0)
        {
            sortedArray[newValue_pos] = newValue;
            sorted_status = true;
        }
        else
        {
            // When the last element is greater than the new value, the last element will move up +1 in the array
            sortedArray[newValue_pos] = sortedArray[newValue_pos - 1];
            // Switch the value that is greater than the new value with the new value
            newValue_pos -= 1;
            sortedArray[newValue_pos] = newValue;
        }
    }
    return numElements + 1;
}


int main(int argc, char* argv[])
{
    std::string filename = argv[1];
    
    std::ifstream myFile;
    myFile.open(filename);

    if(!myFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
    }

    std::string line;
    int numElements = 0;
    const int SIZE = 100;
    float sortedArray[SIZE];

    while(std::getline(myFile, line))
    {
        numElements = addToArrayAsc(sortedArray, numElements, std::stof(line));
        for(int i = 0; i < numElements; i++)
        {
            std::cout << sortedArray[i];
            if(i < numElements - 1)
            {
                std::cout << ",";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}




// int main()
// {
//     float sortedArray[100];
//     const int listsize = 6;
//     float list[listsize] = {29.5, 44.0 ,35.1 ,16.2, 9,200.4};

//     int numElements = 0;

//     while(numElements != listsize)
//     {
//         numElements = addToArrayAsc(sortedArray, numElements, list[numElements]);
//         for(int i = 0; i < numElements; i++)
//         {
//             std::cout << sortedArray[i];
//             if(i < numElements - 1)
//             {
//                 std::cout << ",";
//             }
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }