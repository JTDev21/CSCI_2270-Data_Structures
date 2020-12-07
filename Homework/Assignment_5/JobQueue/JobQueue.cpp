#include <iostream>
#include <string>
#include "JobQueue.hpp"

JobQueue::JobQueue()
{
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}

// JobQueue::~JobQueue()
// {

// }

bool JobQueue::isEmpty()
{
    return (counter == 0);
}

bool JobQueue::isFull()
{
    return (counter == SIZE);
}

void JobQueue::enqueue(std::string job)
{
    if(isFull())
    {
        std::cout << "Queue full, cannot add new job" << std::endl;
    }
    else
    {
        if(isEmpty())
        {
            queue[queueFront] = job;
        }
        else
        {
            if(queueEnd == SIZE)
            {
                queueEnd = 0;
            }
            queue[queueEnd] = job;
        }
        queueEnd++;
        counter++;
    }
}

void JobQueue::dequeue()
{
    if(isEmpty())
    {
        std::cout << "Queue empty, cannot dequeue a job" << std::endl;
    }
    else
    {
        if(queueFront == SIZE)
        {
            queueFront = 0;
        }
        queue[queueFront] = "";
        queueFront++;
        counter--;
    }
}

std::string JobQueue::peek()
{
    if(isEmpty())
    {
        std::cout << "Queue empty, cannot peek" << std::endl;
        return "";
    }
    return queue[queueFront];
}

int JobQueue::queueSize()
{
    return counter;
}