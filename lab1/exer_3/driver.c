/* driver.c */
#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	FILE * out = fopen("output.txt", "w");

	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));

	// In a loop read the file and insert elements into the linkedList.
	// read the next element and store into the temp variable.
	int temp;			
	fscanf(fileptr, "%d", &temp);	
	do
	{
		// insert temp into the linked list.
		insertFirst(head, temp);
		fscanf(fileptr, "%d", &temp);	
	}while (!feof(fileptr));

	// close the file pointer
	fclose(fileptr);

	// print the linked list.
	printList(head);
	
	// delete the first element of the linked list.
	printf("Deleted first element: %d\n", deleteFirst(head) -> element); 

	// print the linked list again to check if delete was successful.
	printList(head);

	// print the linked list to a new file.
	struct node * temp2 = head -> first;
	while(temp2 != NULL){
		fprintf(out, "%d\n", temp2 -> element);
		temp2 = temp2 -> next;
	}
	fclose(out);
}
