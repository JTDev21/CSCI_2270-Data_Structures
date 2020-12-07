#include <iostream>
#include <fstream>
#include <string>

//Uncomment the lines and implement the TODOs in the resizing logic
int* resize(int* arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times
	int newCapacity = capacity * 2;
    std::cout << "Resizing from "<< capacity << " to " << newCapacity << std::endl;

	// TODO dynamically allocate an array of size newCapacity
	int *newArray = new int[newCapacity];

	// TODO copy all data from oldArray to newArray
	for(int i = 0; i < capacity; i++)
	{
		newArray[i] = arrayPtr[i];
	}

	// TODO free the memory associated with oldArray
	delete[] arrayPtr;

	capacity = newCapacity;

	// TODO return the newArray
	return newArray;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		return -1;
	}
	std::string filename = argv[1];
	std::ifstream data;
	data.open(filename.c_str());

	int capacity = 10;
	int *arrayPtr;

	// TODO Dynamically allocate space here for the array
	arrayPtr = new int[capacity];
	int numOfElement = 0;
	std::string temp;

	if(data.is_open())
	{
		while(std::getline(data, temp))
		{
			int toBeInsert = std::stoi(temp);
			if(numOfElement == capacity)
			{
				// Complete this function
				arrayPtr = resize(arrayPtr, capacity);
			}
			arrayPtr[numOfElement] = toBeInsert;
			numOfElement++;
		}
		data.close();
	}

	for(int i = 0; i < numOfElement; i++)
	{
		std::cout << "Num: " << arrayPtr[i] << std::endl;
	}
	return 0;
}
