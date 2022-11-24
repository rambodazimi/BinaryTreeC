
//Include statements
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bTree.h"



//Definitions of constants
#define LENGTH 8000
#define false 0
#define true !false

//An array of type char to hold the resulting string

int main(void){


	// Some guides to be shown at the beginning of the program
	printf("Text Sorting Program - ECSE202 - Assignment 5\n");
	printf("By: Rambod Azimi - 260911967\n\n");
	printf("Please enter as many text as you wish, line by line.\n");
	printf("Blank line terminates the program.\n");
	printf("You can also cut and paste text into the console:\n");

	//Initialize a tree
	initTree();


	while(true){

		char *buffer = (char *)malloc(sizeof(LENGTH));
		fgets(buffer, LENGTH, stdin);


		if(strlen(buffer) <= 1) break;;	//Blank line to terminate the program

		if(buffer == NULL){
			printf("Can't allocate buffer.\n");
			return -1;
		}

		buffer[strlen(buffer)-1] = '\0';

		addNode(buffer);

	}	//End of while loop

	int n = getNumNodes(); //n is a variable that has stored the number of nodes added
	int i;	//Used in For loops

	printf("Text in sort order:\n");
	//func1();
	char** array;
	array = makeSortIndex('a');
	for(i = 0 ; i < n ; i++){
		printf("%s\n" , *(array+i));
	}


	//Deallocate array
	//free(array);

	printf("\nText in reverse order:\n");
	//func2();
	char** array2;
	array2 = makeSortIndex('d');
	for(i = n-1 ; i >= 0 ; i--){
		printf("%s\n" , *(array+i));
	}

	free(array2);

	//Deallocate all the nodes and the tree itself
	deleteTree();


}	//End of main function
