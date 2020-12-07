#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define COUNT 10
using namespace std;


// Helper Functions

void inOrder_printMovieInventory(MovieNode *node)
{
  if(node == NULL) return;
  inOrder_printMovieInventory(node->left);
  std::cout << "Movie: " << node->title << " " << node->rating << std::endl;
  inOrder_printMovieInventory(node->right);
}

void preOrder_queryMovies(MovieNode *node, float rating, int year)
{
  if(node == NULL) return;
  if(node->rating >= rating && node->year > year)
  {
    std::cout << node->title << "(" << node->year << ") " << node->rating << std::endl; 
  }
  preOrder_queryMovies(node->left, rating, year);
  preOrder_queryMovies(node->right, rating, year);
}

void preOrder_averageRating(MovieNode *node, float *sum, int *numMovies)
{
  // This function counts for the number of nodes in the BST
  if(node == NULL) return;
  *numMovies += 1;
  *sum += node->rating;
  preOrder_averageRating(node->left, sum, numMovies);
  preOrder_averageRating(node->right, sum, numMovies);
}

void inOrder_printLevelNodes(MovieNode *node, int level)
{
  if(node == NULL) return;
  if(level == 0)
  {
    std::cout << "Movie: " << node->title << " " << node->rating << std::endl;
  }
  else
  {
    inOrder_printLevelNodes(node->left, level-1);
    inOrder_printLevelNodes(node->right, level-1);
  }
}

void deconstructor_MovieTree(MovieNode *node)
{
  //Using postOrder
  if(node == NULL) return;
  deconstructor_MovieTree(node->left);
  deconstructor_MovieTree(node->right);
  // std::cout << "deleting: " << node->title << std::endl;
  delete node;
}

void print2DUtil(MovieNode *root, int space)
{
    // Base case
    if(root == NULL) return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", (root->title).c_str());

    // Process left child
    print2DUtil(root->left, space);
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
  deconstructor_MovieTree(root);
}

void MovieTree::printMovieInventory() {
   //write your code
  if(root == NULL)
  {
    std::cout << "Tree is Empty. Cannot print" << std::endl;
  }
  else
  {
    inOrder_printMovieInventory(root);
    // print2DUtil(root, 0);
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode *node = new MovieNode;
  node->ranking = ranking;
  node->title = title;
  node->year = year;
  node->rating = rating;

  node->left = NULL;
  node->right = NULL;
  
  if(root == NULL)
  {
    root = node;
  }
  else
  {
    MovieNode *pres = root;
    std::string title_newNode = title;
    while(pres != NULL && pres != node)
    {
      std::string title_presNode = pres->title;
      int compareVal = title_newNode.compare(title_presNode);
      if(compareVal < 0)
      {
        if(pres->left == NULL)
        {
          pres->left = node;
        }
        else
        {
          pres = pres->left;
        }
      }
      else if(compareVal > 0)
      {
        if(pres->right == NULL)
        {
          pres->right = node;
        }
        else
        {
          pres = pres->right;
        }
      }
      else
      {
        std::cout << title_newNode << " == " << title_presNode << std::endl;
        std::cout << "compareVal: " << compareVal << std::endl;
        std::cout << "Hmm, that shouldn't happen. We got a returned value from compareVal that is zero. Meaning we have 2 of the same movie titles." << std::endl; 
      }
    }
  }
}

void MovieTree::findMovie(string title) {
  //write your code
  MovieNode *pres = root;
  std::string searchTitle = title;
  bool isFound = false;
  while(pres != NULL)
  {
    std::string title_presNode = pres->title;
    int compareVal = searchTitle.compare(title_presNode);
    if(compareVal < 0)
    {
      pres = pres->left;
    }
    else if(compareVal > 0)
    {
      pres = pres->right;
    }
    else
    {
      std::cout << "Movie Info:" << std::endl;
      std::cout << "==================" << std::endl;
      std::cout << "Ranking:" << pres->ranking << std::endl;
      std::cout << "Title  :" << pres->title << std::endl;
      std::cout << "Year   :" << pres->year << std::endl;
      std::cout << "rating :" << pres->rating << std::endl;
      pres = NULL;
      isFound = true;
    }
  }
  if(!isFound)
  {
    std::cout << "Movie not found." << std::endl;
  }
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
  if(root == NULL)
  {
    std::cout << "Tree is Empty. Cannot query Movies" << std::endl;
  }
  else
  {
    std::cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    preOrder_queryMovies(root, rating, year);
  }
}

void MovieTree::averageRating() {
  //write your code
  if(root == NULL)
  {
    std::cout << "Average rating:0.0" << std::endl;
  }
  else
  {
    float sum = 0;
    int numMovies = 0;
    preOrder_averageRating(root, &sum, &numMovies);
    float average = sum / numMovies;
    std::cout << "Average rating:" << average << std::endl; 
  }
}

void MovieTree::printLevelNodes(int level) {
  //write your code
  inOrder_printLevelNodes(root, level);
}
