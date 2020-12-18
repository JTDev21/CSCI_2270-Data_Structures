// ADT
    // Is like an interface/contract
    //  Defines operations that will support it
    // Doesn't define the algorithmn(s)
    //  No implementation details

#include <iostream>

struct SingleNode {
    int data;
    SingleNode *next;
};

int main()
{
    SingleNode *head = NULL;
    SingleNode *node1 = NULL;
    SingleNode *node2 = NULL;
    SingleNode *node3 = NULL;


    node1 = new SingleNode();
    node2 = new SingleNode();
    node3 = new SingleNode();
    head = node1;

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = nullptr;
    

    SingleNode *current = head;
    while(current != NULL)
    {
        std::cout << "Address of node: " << current << " | Key Value: " << current->data << " | " << "Tail:" << current->next << std::endl;
        current = current->next;
    }
    return 0;
}