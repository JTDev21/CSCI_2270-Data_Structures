#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;
    }
  }


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0) {
        //TODO
        Node *temp = head;
        head = temp->next;
        delete temp;
        isDeleted = true;
        return isDeleted;
    }

  Node *pres = head;
	Node *prev = NULL;

    // TODO
    int idx = 0;
    while(pres != NULL)
    {
      if(n == idx)
      {
        prev->next = pres->next;
        delete pres;

        isDeleted = true;
        return isDeleted;
      }
      prev = pres;
      pres = pres->next;
      idx++;
    }

	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
    }
    else
    {
      // TODO (take care of the edge case when your linkedlist has just 2 nodes)
      Node *tail = head;
      Node *secondToLast = NULL;
      while(tail->next != NULL)
      {
        secondToLast = tail;
        tail = tail->next;
      }

      Node *temp = head;
      if(head == secondToLast)
      {
        // There's only 2 elements within the linked list
        head = tail;
        head->next = temp;
        temp->next = NULL;
        isSwapped = true;
      }
      else
      {
        // There's more than 2 elements within the linked list
        head = tail;
        head->next = temp->next;
        tail = temp;
        secondToLast->next = tail;
        temp->next = NULL;
        isSwapped = true;
      }
    }
    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
