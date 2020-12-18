#include <iostream> // predefined header file (defined for you)
#include <string>
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	headOne = nullptr;
	headTwo = nullptr;
}

SLL::SLL(string demo)
{
	headOne = nullptr;
	headTwo = nullptr;
	if (demo == "demo")
	{
		string def[]= {"che","the","fluffy","cat"};
		insert(nullptr, def[0]);
		for(int i=1;i<4;i++)
		{
				Node* prev = search(def[i-1]);
				insert(prev, def[i]);
		}
	}
	else{
		insert(nullptr, demo);
	}
}

SLL::~SLL(){
    // To do
    std::cout << std::endl;
    std::cout << "Deallocating memory" << endl;
    Node *pres = headOne;
    while(pres != NULL)
    {
        std::cout << "Deallocating memory from First Linked List: Node->key = [" << pres->key << "]" << std::endl;
        Node *next = pres->next;
        delete pres;
        pres = next;
    }
    headOne = nullptr;
    std::cout << "----" << std::endl;
    pres = headTwo;
    while(pres != NULL)
    {
        std::cout << "Deallocating memory from Second Linked List: Node->key = [" << pres->key << "]" << std::endl;
        Node *next = pres->next;
        delete pres;
        pres = next;
    }
    headTwo = nullptr;
}

Node* SLL::search(string sKey){

    Node* crawler = headOne;

    while( crawler != nullptr && crawler->key != sKey){
        crawler = crawler->next;
    }

    return crawler;

}

void SLL::displayList(){
    Node* crawler = headOne;
    cout<< "LL1:";
    while( crawler != nullptr ){
        cout << crawler->key << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;

    crawler = headTwo;
    cout<< "LL2:";
    while( crawler != nullptr ){
        cout << crawler->key << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;
}


void SLL::insert(Node* afterMe, string newValue){

    if(headOne == nullptr){
        // first case: empty list
        // add new node and make headOne point to it
        headOne = new Node;
        headOne->key = newValue;
        headOne->next = nullptr; // what if we forget this line?
    }
    else if(afterMe == nullptr){
        // This condition implies that the list is not empty, but
        // the caller wants to add node before the headOne node
        Node* newNode = new Node;
        newNode->key = newValue;
        newNode->next = headOne;
        headOne = newNode;
        // at this point, we can test our code for this use case

    }
    else{
        Node* newNode = new Node;
        newNode->key = newValue;
        newNode->next = afterMe->next;
        afterMe->next = newNode;
    }


}

void SLL::deleteNode(string sKey)
{
    Node *deleteNode = search(sKey);
    if( deleteNode != nullptr)
    {
        // check if deleteNode is headOne
        if( deleteNode == headOne ){
            headOne = headOne->next;
            delete deleteNode;
        }
        //traverse the list:
        else
        {
            Node* crawler = headOne;
            // Stop at node prior the node to be deleted
            while(crawler->next != deleteNode){
                crawler = crawler->next;
            }

            // reconnect the LL around the node about to
            // be removed
            crawler->next = crawler->next->next;

            // deallocate
            delete deleteNode;
        }

    }
    else{
        cout << "Node doesn't exist. Nothing to do." << endl;
    }
}

int SLL::split(string searchKey)
{
    if(headOne == nullptr && headTwo == nullptr)
    {
        std::cout << "headOne and headTwo are empty linked list" << std::endl;
        return 1;
    }
    else if (headTwo != nullptr)
    {
        std::cout << "headTwo is already pointing a node" << std::endl;
        return 2;
    }
    
    else if(search(searchKey) == nullptr)
    {
        std::cout << "The searchKey['" << searchKey << "'] does not exist within the Linked List." << std::endl;
        return 1;
    }
    else if(search(searchKey) == headOne)
    {
        cout << "The search key is at the head." << endl;
        headTwo = headOne;
        headOne = nullptr;
    }
    else
    {
        Node *pres = headOne;
        Node *prev = NULL;
        bool isFound = false;
        while(pres != NULL && !isFound)
        {
            if(pres->key == searchKey)
            {
                isFound = true;
            }
            if(!isFound)
            {
                prev = pres;
                pres = pres->next;
            }
        }

        // cout << "-----" << endl;
        // cout << "search key: " << pres->key << endl;
        // cout << "behind the search key: " << prev->key << endl;
        // cout << "-----" << endl;
        headTwo = pres;
        prev->next = NULL;
    }
    std::cout << "Linked list has been split into 2." << std::endl;
    return 0;
}
