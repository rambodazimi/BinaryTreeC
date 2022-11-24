//Assignment 5 - ECSE 202 - Winter 2021
//Author: Rambod Azimi
//Student ID: 260911967
//Porting from Java to C

//Include statements
#include<stdio.h>
#include<stdlib.h>
#include"bTree.h"
#include<string.h>


// "Instance" Variables - global to all functions in the bTree.c file.
bNode *root = NULL;	// bTree root node
int numNodes = 0;	    // Number of nodes in tree
int recCount = 0;    // Count variable for use in recursions
char **indexArray;  // index array for tree sort


//This method is used to initialize a tree.
//It sets root to NULL and numNodes to 0
void initTree(){
	root = NULL;
	numNodes = 0;
}



void addNode(char *newValue){

	numNodes ++;	//Increment this variable each time a new node is added

	bNode *newNode = (bNode*)malloc(sizeof(bNode));	//create an instance called newNode
	newNode->data = newValue;
	bNode *currentNode = (bNode*)malloc(sizeof(bNode));  //create an instance called currentNode
	currentNode = root;



	if (currentNode == NULL){
		root = newNode;
		return;
	}

	//Infinite loop
	while(1){

		int compare = strcasecmp(newValue, currentNode->data);

		if(compare < 0){

			if(currentNode->left == NULL){
				currentNode->left = newNode;
				break;
			} else{
				currentNode = currentNode->left;
			}
		} else {
			if(currentNode->right == NULL){
				currentNode->right = newNode;
				break;
			} else{
				currentNode = currentNode->right;
			}
		}

	}  //End of while loop


}	//End of addNode function


//This function allocates a memory for indexArray
//Then, it calls inOrder or inReverseOrder functions to sort the nodes
//Then, it returns an array of pointers to strings in sort order
char **makeSortIndex(char arg){

	indexArray = (char **)malloc(sizeof(char *) * numNodes);
	char c1 = 'd';
	char c2 = 'D';
	if(arg == c1 || arg == c2){  //inReverseOrder
		inReverseOrder(root);
	} else {  //inOrder
		inOrder(root);
	}

	return indexArray;

}


//Simple function that calls inOrder function
void func1 (){
	inOrder(root);
}

//Simple function that calls inReverseOrder function
void func2 (){
	inReverseOrder(root);
}




//Left Node , Current Node , Right Node
void inOrder(bNode *root){

	if(root != NULL){
		inOrder(root->left);
		indexArray[recCount++] = root->data;
	//	printf("%s\n" , root->data);
		inOrder(root->right);

	}
} //End of inOrder function


//Exactly reverse of inOrder sort
//Right Node , Current Node , Left Node
void inReverseOrder(bNode *root){

	if(root != NULL){
		inReverseOrder(root->right);
		indexArray[recCount++] = root->data;
	//	printf("%s\n" , root->data);
		inReverseOrder(root->left);
	}

}	//End of inReverseOrder function


//Left Node , Right Node , Current Node
//This function is used in order to deallocate each node added into the bTree
void postOrder(bNode *root){

	if(root->left != NULL){
		postOrder(root->left);
	}
	if(root->right != NULL){
		postOrder(root->right);
	}
	free(root->data);	//Deallocate buffer
	free(root);		//Deallocate bNode


}


//A simple getter function to return the number of nodes in the tree
int getNumNodes(){
	return numNodes;
}

//A function to delete the entire tree, by calling postOrder function
void deleteTree(){
	postOrder(root);
}



