#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define COUNT 10
using namespace std;


// Helper Functions

MovieNode *addNode(MovieNode *node, int ranking, string title, int year, float rating)
{
  if(node == NULL)
  {
    MovieNode *newNode = new MovieNode;
    newNode->ranking = ranking;
    newNode->title = title;
    newNode->year = year;
    newNode->rating = rating;

    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  std::string title_newNode = title;
  int compareVal = title_newNode.compare(node->title);
  if(compareVal < 0)
  {
    node->left = addNode(node->left, ranking, title, year, rating);
  }
  if(compareVal > 0)
  {
    node->right = addNode(node->right, ranking, title, year, rating);
  }
  if(compareVal == 0)
  {
    std::cout << title_newNode << " == " << node->title << std::endl;
    std::cout << "compareVal: " << compareVal << std::endl;
    std::cout << "Hmm, that shouldn't happen. We got a returned value from compareVal that is zero. Meaning we have 2 of the same movie titles." << std::endl; 
  }
  return node;
}

void inOrder_printMovieInventory(MovieNode *node)
{
  if(node == NULL) return;
  inOrder_printMovieInventory(node->left);
  std::cout << "Movie: " << node->title << " " << node->rating << std::endl;
  inOrder_printMovieInventory(node->right);
}

MovieNode *searchForMovie(MovieNode *node, std::string title)
{
  if(node == NULL) return NULL;
  if(node->title == title) return node;

  int compareVal = title.compare(node->title);
  if(compareVal < 0)
    return searchForMovie(node->left, title);
  else
    return searchForMovie(node->right, title);
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
    return;
  }
  inOrder_printLevelNodes(node->left, level-1);
  inOrder_printLevelNodes(node->right, level-1);
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

// void print2DUtil(MovieNode *root, int space)
// {
//     // Base case
//     if(root == NULL) return;

//     // Increase distance between levels
//     space += COUNT;

//     // Process right child first
//     print2DUtil(root->right, space);

//     // Print current node after space
//     // count
//     printf("\n");
//     for (int i = COUNT; i < space; i++)
//         printf(" ");
//     printf("%s\n", (root->title).c_str());

//     // Process left child
//     print2DUtil(root->left, space);
// }
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
  root = NULL;
}

void MovieTree::printMovieInventory() {
   //write your code
  if(root == NULL)
  {
    std::cout << "Tree is Empty. Cannot print" << std::endl;
    return;
  }
  inOrder_printMovieInventory(root);
  // print2DUtil(root, 0);
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  root = addNode(root, ranking, title, year, rating);
}

void MovieTree::findMovie(string title) {
  //write your code
  MovieNode *movie = searchForMovie(root, title);
  if(movie == NULL)
  {
    std::cout << "Movie not found." << std::endl;
    return;
  }
  std::cout << "Movie Info:" << std::endl;
  std::cout << "==================" << std::endl;
  std::cout << "Ranking:" << movie->ranking << std::endl;
  std::cout << "Title  :" << movie->title << std::endl;
  std::cout << "Year   :" << movie->year << std::endl;
  std::cout << "rating :" << movie->rating << std::endl;
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
  if(root == NULL)
    std::cout << "Tree is Empty. Cannot query Movies" << std::endl;
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
    return;
  }
  float sum = 0;
  int numMovies = 0;
  preOrder_averageRating(root, &sum, &numMovies);
  float average = sum / numMovies;
  std::cout << "Average rating:" << average << std::endl;
}

void MovieTree::printLevelNodes(int level) {
  //write your code
  inOrder_printLevelNodes(root, level);
}
