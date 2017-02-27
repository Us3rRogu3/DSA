#include<stdio.h>
#include<stdlib.h>
#include "qsort.h"

int main(){
	FILE *fptr = stdin;
	stu ls = NULL;
	stu ls2;
	int choice = 0, max, i;
	while(choice != -1){
		scanf("%d", &choice);
		switch(choice){
			case 0:
				scanf("%d", &max);				
				ls = (stu) malloc(sizeof(struct student) * max);
				for(i = 0; i < max; i++){
					scanf("%s", (ls+i)->name);
					scanf("%u", &(ls+i)->marks);
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
				free(ls2);
				break;
			case 2:
				ls2 = (stu) malloc(sizeof(struct student) * max);
				for(i = 0; i < max; i++){
					*(ls2+i) = *(ls+i);
				}
				scanf("%d", &i);
				switch(i){
				case 1:
					quickSort(ls2, 0, max-1);
					printList(ls2, 0, max-1);
					break;
				case 2:
					quickSort2(ls2, 0, max-1);
					printList(ls2, 0, max-1);
					break;
				case 3:
					quickSort(ls2, 0, max-1);
					printList(ls2, 0, max-1);
					break;
				case 4:
					quickSort(ls2, 0, max-1);
					printList(ls2, 0, max-1);
					break;
				default: 
					break;
				}
				free(ls2);
				break;
			default:
				break;

		}
	}

}
