/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char *argv[])
{
	JobQueue cirArrQueue;
	int option = 0;
	do
	{
		menu();
		cin >> option;
		switch(option)
		{
			case 1:
			{
				int numEnqueue = 0;
				std::cout << "Enter the number of jobs to be created: " << std::endl;
				cin >> numEnqueue;
				for(int i = 0; i < numEnqueue; i++)
				{
					std::cout << "job" << i+1 << ":" << std::endl;
					string jobName;
					cin >> jobName;
					cirArrQueue.enqueue(jobName);
				}
			}
			break;
			case 2:
			{
				int numDequeue = 0;
				std::cout << "Enter the number of jobs to be dispatched:" << std::endl;
				cin >> numDequeue;
				for(int i = 0; i < numDequeue; i++)
				{
					if(cirArrQueue.isEmpty())
					{
						std::cout << "No more jobs to be dispatched from queue" << std::endl;
					}
					else
					{
						std::cout << "Dispatched: " << cirArrQueue.peek() << std::endl;
						cirArrQueue.dequeue();
					}
				}
			}
			break;
		}
	} while (option != 3);
	std::cout << "Number of jobs in the queue:" << cirArrQueue.queueSize() << std::endl;
	return 0;
}



// int main(int argc, char const *argv[])
// {
// 	cout << "Enqueue 20 things, dequeue 10, enqeue 7" << endl;
// 	JobQueue jq;
// 	for(int i=0; i<20; i++)
// 		jq.enqueue("aaa");
// 	for(int i=0; i<10; i++)
// 		jq.dequeue();
// 	for(int i=0; i<7; i++)
// 		jq.enqueue("bbb");
// 	cout << "Queue front index: " << jq.getQueueFront() << endl;
// 	cout << "Queue back index: " << jq.getQueueEnd() << endl;
// 	cout << "Queue size: " << jq.queueSize() << endl;
// }