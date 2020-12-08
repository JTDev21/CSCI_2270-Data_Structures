#ifndef DLL_HPP
#define DLL_HPP

struct Node
{
    int key;
    Node *next;
    Node *prev;
};

class DLL
{
    private:
        Node *head;
    public:
        ~DLL();
        DLL();
        
        void insert(int key);
        bool search(int key);
        void display();
};

#endif