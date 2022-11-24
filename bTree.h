/*
* bTree.h
*  Created on: Nov. 15, 2020
*  Updated on: Mar. 28, 2021 // Changes to match A2, Winter 2021
*      Author: ferrie
*/

// Any program that uses the bTree class must include "bTree.h" to access the
//object templatfor bNode and the corresponding function (method)
//definitions.


#include <stdio.h>
#include <stdlib.h>
#ifndef BTREE_H_
#define BTREE_H_


// Parameters

#define false 0  // Definitions for true and false
#define true !false  


// Structure Templates

typedef struct bN {
char *data;		// Pointer to string
struct bN *left;  // Left successor
struct bN *right; // Right successor
} bNode;

// Prototypes: The signature for each method(function) is defined here so
//that the compiler can check against a formal definition.

void initTree();  // Initialize the bTree

void addNode(char *data);  // Adds a new node to the bTree.

bNode *makeNode(char *data);  // Function that allocates a bNode

char **makeSortIndex(char arg);  // Returns an array of pointers to strings in sort order

void inOrder(bNode *root);  // The recursive function that performs inorder traversal

void inReverseOrder(bNode *root);  // Same as InOrder with order of recursion reversed

void deleteTree();  // Deletes the bTree (all allocated nodes)

void postOrder(bNode *root);  // Post order traversal used to delete tree nodes

int getNumNodes();  // Getter returns the number of nodes in the tree.

void func1();

void func2();

#endif /* BTREE_H_ */