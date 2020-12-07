/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of Building structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network between the building *previous and the building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    // if we are passed an empty list, just create a new head node, and return

    if (head == NULL)
    {
        cout << "adding: " << buildingName << " (HEAD)" << endl;
        head = new CUBuilding;
        head->name = buildingName;
        head->numberMessages = 0;
        head->totalRoom = numOfroom;

        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        cout << "adding: " <<buildingName<< " (HEAD)" << endl;
        CUBuilding *c = new CUBuilding;
        c->name = buildingName;
        c->numberMessages = 0;
        c->next = head;
        c->totalRoom = numOfroom;

        head = c;
    }else{
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
        CUBuilding *newBuilding = new CUBuilding;
        newBuilding->name = buildingName;
        newBuilding->numberMessages = 0;
        newBuilding->next = previous->next;
        newBuilding->totalRoom = numOfroom;

        previous->next = newBuilding;
    }
}

/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    int num_buildings = 6;
    string buildings[] = {"FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT"};
    int rooms[] = {2,10,6,5,4,9};
    head = NULL;
    CUBuilding* prev = NULL;
    for(int i = 0; i < num_buildings; i++)
    {
        addBuildingInfo(prev, buildings[i],rooms[i]);
        prev = searchForBuilding(buildings[i]);
    }
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    // Search until the head is NULL, or we find the building
    CUBuilding* ptr = head;
    while (ptr != NULL && ptr->name != buildingName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUBuilding* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->totalRoom << ")" <<" -> ";
            ptr = ptr->next;
        }
        //cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
  }

/*
 * Purpose: delete the building in the network with the specified name.
 * @param buildingName name of the building to delete in the network
 * @return none
 */
void CUBuildingNetwork::deleteCUBuilding(string buildingName) {
    //TODO: Complete this function
    CUBuilding *pres = head;
    CUBuilding *prev = NULL;
    bool isFound = false;
    while(pres != NULL)
    {
        if(pres->name == buildingName && pres == head)
        {
            CUBuilding *temp = pres;
            head = pres->next;
            delete temp;
            isFound = true;
        }
        else if(pres->name == buildingName)
        {
            prev->next = pres->next;
            delete pres;
            isFound = true;
        }
        prev = pres;
        pres = pres->next;
    }
    if(!isFound)
    {
        std::cout << "Building does not exist." << std::endl;
    }
}

/*
* Purpose: Creates a loop from last node to the building specified.
* @param buildingName name of the building to loop back
* returns the last node before loop creation (to break the loop)
*/
CUBuilding* CUBuildingNetwork::createLoop(string buildingName) {
    //TODO: Complete this function
    CUBuilding *pres = head;
    while(pres->next != NULL)
    {
        pres = pres->next;
    }
    if(searchForBuilding(buildingName) != NULL)
    {
        pres->next = searchForBuilding(buildingName);
    }
    return pres;
}

/*
 * Purpose: deletes all buildings in the network starting at the head building.
 * @param: none
 * @return: none
 */
void CUBuildingNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    CUBuilding *pres = head;
    while(pres != NULL)
    {
        std::cout << "deleting: " << pres->name << std::endl;
        head = pres->next;
        delete pres;
        pres = head;
    }
    std::cout << "Deleted network" << std::endl;
}

/*
 * Purpose: to detect loop in the linkedlist
 * @return: true if loop is detected.
 */
bool CUBuildingNetwork::detectLoop() {
    //TODO: Complete this function
    CUBuilding *skipOne = head;
    CUBuilding *skipTwo = head;
    // If skipOne or skipOne->next or skipTwo equal to NULL, then there is no loop since there exists a tail.
    while(skipOne != NULL && skipOne->next != NULL && skipTwo != NULL)
    {
        skipOne = skipOne->next;
        skipTwo = skipTwo->next->next;
        if(skipOne == skipTwo)
        {
            return true;
        }
        // std::cout << "skipOne: " << skipOne << " | skipTwo: " << skipTwo << " | skipOne->next: " << skipOne->next << std::endl;
    }
    return false;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk at the end of the List
 * @param: start index, end index
 * @return: none
 */
void CUBuildingNetwork:: readjustNetwork(int start_index, int end_index)
{
    //TODO: Complete this function
    if (isEmpty())
    {
        std::cout << "Linked List is Empty" << std::endl;
    }
    else
    {
        int numNode = 0;
        CUBuilding *pres = head;
        while(pres != NULL)
        {
            numNode++;
            pres = pres->next;
        }

        if(end_index < 0 || numNode <= end_index)
        {
            std::cout << "Invalid end index" << std::endl;
        }
        else if(start_index < 0 || numNode <= start_index)
        {
            std::cout << "Invalid start index" << std::endl;
        }
        else if(start_index > end_index)
        {
            std::cout << "Invalid indices" << std::endl;
        }
        else
        {
            numNode = 0;
            pres = head;
            CUBuilding *before_startNode_idx = NULL;
            CUBuilding *startNode_idx = NULL;
            CUBuilding *endNode_idx = NULL;
            CUBuilding *tailNode = NULL;
            
            while(pres != NULL)
            {
                if(numNode == start_index - 1)
                {
                    before_startNode_idx = pres;
                    startNode_idx = pres->next;
                }
                if(numNode == end_index)
                {
                    endNode_idx = pres;
                }
                if(pres->next == NULL)
                {
                    tailNode = pres;
                }
                numNode++;
                pres = pres->next;
            }
            // std::cout << startNode_idx->name << std::endl << endNode_idx->name << std::endl;
            // std::cout << before_startNode_idx->name << std::endl;
            if(start_index == 0)
            {
                startNode_idx = head;
                head = endNode_idx->next;
            }
            else
            {
                before_startNode_idx->next = endNode_idx->next;
            }
            tailNode->next = startNode_idx;
            endNode_idx->next = NULL;
        }
    }
}