/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "bucketSort.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = stdin;

	// Declare a pointer to a linked list (head) and allocate memory to it.
	li lis = (li) malloc(sizeof(struct list));
	tu tup;
	int choice, lim, i, xlo, xhi, ylo, yhi, x, y;
	//printf("%d", head -> count);

	// In a loop read the file and insert elements into the linkedList.
	// read the next element and store into the temp variable.
	scanf("%d", &choice);
	while(choice != -1){
		switch(choice){
			case 0: 
				scanf("%d %d %d %d %d", &lim, &xlo, &xhi, &ylo, &yhi);
				tup = malloc(sizeof(struct tuple) * lim);
				for(i = 0; i< lim; i++){
					scanf("%d %d", &x, &y);
					(tup + i) -> x = x;
					(tup + i) -> y = y; 
				}
				lis -> count = lim;
				lis -> xlo = xlo;
				lis -> ylo = ylo;
				lis -> xhi = xhi;
				lis -> yhi = yhi;
				lis -> tup = tup;
				//printlist(lis);
				break;
			case 1: 
				buckSort(lis);
				exit(0);
				break;
			case 2: 
				buckSort(lis);				
				exit(0);
				break;
		}
	//printf("%d", head -> count);
		scanf("%d", &choice);
	
	}
}
