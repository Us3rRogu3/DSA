/* driver.c */
#include <stdio.h>
#include<stdlib.h>
#include "cstack.h"

int main()
{
	// Declare a pointer to a linked list (head) and allocate memory to it.
	CircularStack head = (CircularStack) malloc (sizeof(struct cstack1));

	// In a loop read the file and insert elements into the linkedList.
	// read the next element and store into the temp variable.
	csize(head, 5);

	int choice = 0;
	while(choice != 4){
		printf("\n 1.Push\n 2.Pop\n 3.Print\n 4.Exit\n 5.Size\n 6.top\n Enter Choice : ");
		scanf("%d", &choice);
		if(choice == 1){
			int inp;
			printf("Enter Element: ");
			scanf("%d", &inp);
			cpush(head, inp);		
		}else if(choice == 2){
			printf("Popped %d \n", cpop(head) -> element); 		
		}else if(choice == 3){
			cprint(head);
		}else if(choice == 5){
			int inp;
			printf("Enter size: ");
			scanf("%d", &inp);		
			csize(head, inp);
		}else if(choice == 6){
			printf("Top %d \n", (top1(head) -> element)); 		
		}
		else{
			exit(1);
		}
	}	
	return 0;
}
