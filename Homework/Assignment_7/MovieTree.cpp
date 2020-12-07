#include <iostream>
#include <fstream>
#include "MovieTree.hpp"
#define COUNT 10

using namespace std;

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}
/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}
/* ------------------------------------------------------ */

void _grader_inorderTraversal(TreeNode * root) {
		if (root == NULL) {
			return;
		}

		_grader_inorderTraversal(root->leftChild);
		cout << root->titleChar << " ";
		_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* ------------------------------------------------------ */
/* ------------------------------------------------------ */

void inOrder_TreeNode_deletetion(TreeNode *node)
{
	if(node == NULL) return;
	inOrder_TreeNode_deletetion(node->leftChild);
	inOrder_TreeNode_deletetion(node->rightChild);

	if(node->head != NULL)
	{
		LLMovieNode *pres = node->head;
		while(pres != NULL)
		{
			LLMovieNode *toBeDeleted = pres;
			node->head = pres;
			delete toBeDeleted;
			
			pres = pres->next;

		}
	}
	delete node;
}

MovieTree::~MovieTree()
{
	inOrder_TreeNode_deletetion(root);
}

/* ------------------------------------------------------ */
/* -------------Show Movie Collection Function----------- */

void inOrder_showMovieCollection(TreeNode *t)
{
	if(t == NULL) return;
	inOrder_showMovieCollection(t->leftChild);

	std::cout << "Movies starting with letter: " << t->titleChar << std::endl;
	LLMovieNode *m = t->head;
	while(m != NULL)
	{
		std::cout << " >> " << m->title << " " << m->rating << std::endl;
		m = m->next;
	}
	inOrder_showMovieCollection(t->rightChild);
}


void MovieTree::showMovieCollection()
{
	inOrder_showMovieCollection(root);
}
/* ------------------------------------------------------ */
/* ---------------Insert Movie/Tree Node----------------- */
TreeNode *insert_TreeNode_insertMovie(TreeNode *t, TreeNode *insertNode)
{
	if(t == NULL) return insertNode;
	insertNode->parent = t;
	
	if(insertNode->titleChar < t->titleChar)
	{
		t->leftChild = insert_TreeNode_insertMovie(t->leftChild, insertNode);
	}
	else if(insertNode->titleChar > t->titleChar)
	{
		t->rightChild = insert_TreeNode_insertMovie(t->rightChild, insertNode);
	}
	return t;
}

void insert_MovieNode_insertMovie(TreeNode *ParentTree, LLMovieNode *new_m)
{
	LLMovieNode *pres = ParentTree->head;
	LLMovieNode *prev = NULL;
	while(pres != NULL)
	{
		int compareVal = new_m->title.compare(pres->title);
		if(compareVal > 0)
		{
			// std::cout << new_m->title << " < " << pres->title << std::endl;
			prev = pres;
			pres = pres->next;
		}
		else if(compareVal < 0)
		{
			// std::cout << new_m->title << " > " << pres->title << std::endl;
			if(prev == NULL)
			{
				// std::cout << "[OLD HEAD]" << ParentTree->head->title << " -> [NEW HEAD]"<< new_m->title << std::endl;
				new_m->next = ParentTree->head;
				ParentTree->head = new_m;
			}
			else
			{
				// std::cout << "---------------" << std::endl;
				// std::cout << "Inserting: " << new_m->title << std::endl;
				// std::cout << prev->title << " -> " << prev->next->title << std::endl;
				prev->next = new_m;
				new_m->next = pres;
				// std::cout << prev->title << " -> " << prev->next->title << " -> " << prev->next->next->title << std::endl;
				// std::cout << "---------------" << std::endl;
			}
			return;
		}
	}
	// If the function fails to return itself when it reaches the end of LL.
	// Then, the list is in alphebetical order and the new node should be inserted at the end.
	prev->next = new_m;
}

void MovieTree::insertMovie(int ranking, std::string title, int year, float rating)
{
	// Add a movie node to linked list
	LLMovieNode *new_MovieNode = new LLMovieNode;
	new_MovieNode->ranking = ranking;
	new_MovieNode->title = title;
	new_MovieNode->year = year;
	new_MovieNode->rating = rating;
	new_MovieNode->next = NULL;
	
	if(searchCharNode(title[0]) == NULL)
	{
		// Add a tree node
		TreeNode *new_TreeNode = new TreeNode;
		new_TreeNode->head = new_MovieNode;
		new_TreeNode->titleChar = title[0];
		new_TreeNode->parent = NULL;
		new_TreeNode->leftChild = NULL;
		new_TreeNode->rightChild = NULL;

		root = insert_TreeNode_insertMovie(root, new_TreeNode);
	}
	else
	{
		TreeNode *ParentTree = searchCharNode(title[0]);
		insert_MovieNode_insertMovie(ParentTree, new_MovieNode);
	}
}
/* ------------------------------------------------------ */
/* ---------------Remove Movie/Tree Node----------------- */
TreeNode *getMinValueNode(TreeNode *node)
{
	if(node->leftChild == NULL) return node;
	getMinValueNode(node->leftChild);
}

TreeNode *deleteTreeNode(TreeNode *t, char value)
{
	// std::cout << "Deleting: " << value << std::endl;
	if(t == NULL)
	{
		return NULL;
	}
	else if(int(value) < int(t->titleChar))
	{
		// std::cout << int(value) << " < " << int(t->titleChar) << std::endl;
		t->leftChild = deleteTreeNode(t->leftChild, value);
	}
	else if(int(value) > int(t->titleChar))
	{
		// std::cout << int(value) << " > " << int(t->titleChar) << std::endl;
		t->rightChild = deleteTreeNode(t->rightChild, value);
	}
	else
	{
		// std::cout << int(value) << " == " << int(t->titleChar) << std::endl;
		if(t->leftChild == NULL && t->rightChild == NULL)
		{
			// std::cout << "TreeNode[" << t->titleChar << "] has no child" << std::endl;
			delete t;
			return NULL;
		}
		else if(t->leftChild == NULL)
		{
			// std::cout << "Node[" << t->titleChar << "] has only the right child Node[" << t->rightChild->titleChar << "]" << std::endl;
			TreeNode *rightNode = t->rightChild;
			rightNode->parent = t->parent;
			delete t;
			return rightNode;
		}
		else if(t->rightChild == NULL)
		{
			// std::cout << "Node[" << t->titleChar << "] has only the left child Node[" << t->leftChild->titleChar << "]" << std::endl;
			TreeNode *leftNode = t->leftChild;
			leftNode->parent = t->parent;
			delete t;
			return leftNode;
		}
		else
		{
			TreeNode *minRight = getMinValueNode(t->rightChild);
			t->head = minRight->head;
			t->titleChar = minRight->titleChar;
			t->rightChild = deleteTreeNode(t->rightChild, minRight->titleChar);
		}
	}
}

void MovieTree::removeMovieRecord(std::string title)
{
	TreeNode *ParentTree = searchCharNode(title[0]);
	if(ParentTree == NULL)
	{
		std::cout << "Movie not found." << std::endl;
	}
	else
	{
		LLMovieNode *pres = ParentTree->head;
		LLMovieNode *prev = NULL;
		bool isFound = false;
		while(pres != NULL && !isFound)
		{
			if(pres->title == title)
			{
				isFound = true;
			}
			else
			{
				prev = pres;
				pres = pres->next;
			}
		}
		if(isFound)
		{
			// std::cout << pres->title << std::endl;
			LLMovieNode *toBeDeleted = pres;
			if(pres == ParentTree->head)
			{
				ParentTree->head = pres->next;
			}
			else
			{
				prev->next = pres->next;
			}
			delete toBeDeleted;
		}
		else
		{
			std::cout << "Movie not found." << std::endl;
		}
		if(ParentTree->head == NULL)
		{
			// std::cout << "Linked List is Empty" << std::endl;
			root = deleteTreeNode(root, ParentTree->titleChar);
		}
	}
}
/* ------------------------------------------------------ */
/* -------------------Left Rotation---------------------- */
void print2DUtilHelper(TreeNode *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->rightChild, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", currNode->titleChar);

    // Process left child
    print2DUtilHelper(currNode->leftChild, space);
}

void MovieTree::leftRotation(TreeNode* curr)
{
	TreeNode *currParent = curr->parent;
	TreeNode *rightNode = curr->rightChild;
	
	curr->rightChild = rightNode->leftChild;

	if(rightNode->leftChild != NULL)
		rightNode->leftChild->parent = curr;

	rightNode->leftChild = curr;
	curr->parent = rightNode;
	rightNode->parent = currParent;

	if(currParent != NULL)
	{
		if(currParent->leftChild == curr)
			currParent->leftChild = rightNode;
		else
			currParent->rightChild = rightNode;
	}
	else
	{
		root = rightNode;
		root->parent = NULL;
	}
}