#include "dll.hpp"
#include <iostream>

DLL::DLL()
{
    head = nullptr;
}

DLL::~DLL()
{
    /*
        Deconstructor for when the program ends
        Deletes all nodes in the linked list O(n)
    */
    Node *pres = head;
    while(pres != NULL)
    {
        Node *toBeDeleted = pres;
        pres = pres->next;
        // std::cout << "Deleting " << toBeDeleted->key << std::endl;
        delete toBeDeleted;
    }
    head = nullptr;
}

void DLL::insert(int key)
{
    /*
        Insert a new node at the head of the unsorted linked list with an O(1).
    */
    Node *newNode = new Node;
    newNode->key = key;
    newNode->prev = nullptr;
    if(head == NULL)
    {
        newNode->next = nullptr;
        head = newNode;
    }
    else
    {
        /*
        NewNode next pointer will point to heads.
        The node head prev pointer will point to the newNode.
        While we reassign head to equal newNode.
        */
        newNode->next = head;
        newNode->next->prev = newNode;
        head = newNode;
    }
    // std::cout << "Inserting " << head->key << std::endl;
}

// void DLL::insert(int key)
// {
//     // Inserting node at the tail. O(n)
//     Node *n = new Node;
//     n->key = key;
//     n->next = nullptr;
//     if(head == NULL)
//     {
//         n->prev = nullptr;
//         head = n;
//         return;
//     }
//     Node *pres = head;
//     while(pres->next != NULL)
//     {
//         pres = pres->next;
//     }
//     n->prev = pres;
//     pres->next = n;
// }

bool DLL::search(int key)
{
    Node *pres = head;
    while(pres != NULL)
    {
        // Searches through the linked list
        // A condition is made such that if the current node visited has the same key as our requested key then return the node.
        if(pres->key == key) return true;
        pres = pres->next;
    }
    std::cout << "Could not find " << key << std::endl;
    return false;
}

void DLL::display()
{
    Node *pres = head;
    while(pres != NULL)
    {
        std::cout << pres->key << " -> ";
        pres = pres->next;
    }
    std::cout << "NULL" << std::endl;
}