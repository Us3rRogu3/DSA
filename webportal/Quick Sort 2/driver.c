#include<stdio.h>
#include<stdlib.h>
#include "qsort.h"

int main(int argc, char *argv[]){
	FILE *fileptr = stdin;
	stu ls;
	stu ls2;
	int choice = 0, max, i;
	scanf("%d", &choice);	
	while(choice != -1){
		switch(choice){
			case 0:
				scanf("%d", &max);	
				//printf("%d", max);			
				ls = (stu) malloc(sizeof(struct student) * max);
				for(i = 0; i < max; i++){
					scanf("%s", (ls+i)->name);
					scanf("%lf", &(ls+i)->marks1);
					scanf("%lf", &(ls+i)->marks2);
					(ls+i)->total = (ls+i)->marks1 + (ls+i)->marks2;
				}
				//printList(ls, 0, max-1);
				break;
			case 1:
				ls2 = (stu) malloc(sizeof(struct student) * max);
				for(i = 0; i < max; i++){
					*(ls2+i) = *(ls+i);
				}
				scanf("%d", &i);
				partialQuickSort(ls2, 0, max-1, i);
				printList(ls2, 0, max-1);
				//printf("\n\n");
				free(ls2);
				break;
			case 2:
				ls2 = (stu) malloc(sizeof(struct student) * max);
				for(i = 0; i < max; i++){
					*(ls2+i) = *(ls+i);
				}
				quickSort(ls2, 0, max-1);
				printList(ls2, 0, max-1);
				free(ls2);
				break;
			default:
				break;

		}
	scanf("%d", &choice);	
	}
}
