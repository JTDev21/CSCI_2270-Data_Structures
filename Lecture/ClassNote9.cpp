#include <iostream>
#include <string>

// Goal: Creating a node dynamically
struct Node
{
    int value;
    std::string message;
    Node *next;
};

class Messenger
{
    private:
        Node *head;
    public:
        Messenger();
        void addNode();
};

Messenger::Messenger()
{
    head = NULL;
}

void Messenger::addNode()
{

}

int main()
{
    
    return 0;
}