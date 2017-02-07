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
		scanf("%d", &val);
		//printf("Inserting %d %d\n", choice, val);
		insert(head, val, choice);
		//printf("%d", head -> count);
		scanf("%d", &choice);
	}
	haretort(head);
}
