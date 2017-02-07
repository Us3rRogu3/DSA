/* driver.c */
#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = stdin;

	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	head -> first = NULL;
	head -> count = 0;
	int choice, val;
	//printf("%d", head -> count);

	// In a loop read the file and insert elements into the linkedList.
	// read the next element and store into the temp variable.
	scanf("%d", &choice);
	while(choice != -1){
		switch(choice){
			case 0: 
				scanf("%d", &val);
				while(val != -1){
					insertAtEnd(head, val);
					scanf("%d", &val);
				}
				traverse(head);
				break;
			case 1: 
				traverse(head);
				break;
			case 2: 
				deleteAll(head);
				//traverse(head);
				break;
			default: 
				break;
		}
		//printf("%d", head -> count);
		scanf("%d", &choice);
	}
}
