/* driver.c */
#include <stdio.h>
#include<stdlib.h>
#include "sort.h"

int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = stdin;

	int lim = 0, i = 0, temp;
	scanf("%d", &lim);
	//printf("%d\n", lim);
	int * arr = (int *) malloc(sizeof(int) * lim);
	while(i < lim){
		scanf("%d", &temp);
		*(arr + i) = temp;
		i++;
	}
	mergeins(arr, 0, lim);
	i = 0;
	while(i < lim){
		printf("%d\n", *(arr + i));
		i++;
	}
}
