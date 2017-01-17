/* driver.c */
#include <stdio.h>
#include<stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	
	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));

	// In a loop read the file and insert elements into the linkedList.
	// read the next element and store into the temp variable.
	int temp;			
	fscanf(fileptr, "%d", &temp);	
	do
	{
		// insert temp into the linked list.
		push(head, temp);
		fscanf(fileptr, "%d", &temp);	
	}while (!feof(fileptr));

	// close the file pointer
	fclose(fileptr);

	int choice = 0;
	while(choice != 4){
		printf("1.Push\n 2.Pop\n 3.Print\n 4.Exit \n Enter Choice : ");
		scanf("%d", &choice);
		if(choice == 1){
			int inp;
			printf("Enter Element: ");
			scanf("%d", &inp);
			push(head, inp);		
		}else if(choice == 2){
			printf("Popped %d \n", pop(head) -> element); 		
		}else if(choice == 3){
			printList(head);
			// print the linked list to a new file.
			FILE * out = fopen("output.txt", "w");
			struct node * temp2 = head -> first;
			while(temp2 != NULL){
				fprintf(out, "%d\n", temp2 -> element);
				temp2 = temp2 -> next;
			}
			fclose(out);
		}
		else{
			exit(1);
		}
	}	
}
