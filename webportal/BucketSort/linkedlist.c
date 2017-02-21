/* linkedlist.c */
#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

/* inserts in sorted order */
void insertInto(struct linkedlist * head, int val){
	//printf("\n start %d %d\n", head -> count, val);
	no temp = (no) malloc(sizeof(struct node));
	temp -> ele = val;
	temp -> next = NULL;	
	if(head -> count == 0){
		//printf("first");
		head -> first = temp;
	}else if(head -> count == 1){
		//printf("second");
		if(head -> first -> ele > val){
			temp -> next = head -> first;
			head -> first = temp;
		}else{
			head -> first -> next = temp;	
		}
	}else{
		//printf("third");
		no ptr = head -> first;
		if(ptr -> ele > val){
			temp -> next = head -> first;
			head -> first = temp;
		}else{
			while(ptr -> next != NULL){
				if(ptr -> next -> ele > val){
					break;
				}
				ptr = ptr -> next;
			}
			//printf("between %d %d\n", val, ptr -> ele);
			temp -> next = ptr -> next;
			ptr -> next = temp;			 
		}
	}
	head -> count ++;
	//printf("\n end %d %d\n", head -> count, val);
	
}

