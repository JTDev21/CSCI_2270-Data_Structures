/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
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
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom)
{
    CUBuilding *newBuilding = new CUBuilding;
    if(previous == NULL)
    {
        std::cout << "adding: " << buildingName << " (HEAD)" << std::endl;
        newBuilding->next = head;
        head = newBuilding;
    }
    else
    {
        std::cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << std::endl;
        newBuilding->next = previous->next;
        previous->next = newBuilding;
    }
    newBuilding->name = buildingName;
    newBuilding->totalRoom = numOfroom;
}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    string buildingNames[6] = {"FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT"};
    int totalRooms[6] = {2, 10, 6, 5, 4, 9};

    addBuildingInfo(NULL, buildingNames[0], totalRooms[0]);
    for(int i = 1; i < 6; i++)
    {
        addBuildingInfo(searchForBuilding(buildingNames[i-1]), buildingNames[i], totalRooms[i]);
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
    CUBuilding *temp = head;
    while(temp != NULL)
    {
        if(temp->name == buildingName)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver)
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
    }
    else
    {
        CUBuilding *current = head;
        bool quickScan = false;
        while(!quickScan && current != NULL)
        {
            if(current->name == receiver)
            {
                quickScan = true;
            }
            current = current->next;
        }

        if(!quickScan)
        {
            std::cout << "Building not found" << std::endl;
        }
        else
        {
            bool found = false;
            current = head;
            while(!found && current != NULL)
            {
                if(current->name == receiver)
                {
                    found = true;
                }
                current->numberMessages += 1;
                current->message = "available room at";
                std::cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << " " << current->name << " is " << current->totalRoom << std::endl;
                current = current->next;
            }
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    std::cout << "== CURRENT PATH ==" << std::endl;
    if(head == NULL)
    {
        std::cout << "nothing in path" << std::endl;
    }
    else
    {
        CUBuilding *current = head;
        while(current != NULL)
        {
            std::cout << current->name << "(" << current->totalRoom << ") -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
    std::cout << "===" << std::endl;
}
