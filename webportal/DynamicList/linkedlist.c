/* linkedlist.c */
#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

//insert first item
void insertInFront(struct linkedList * head, int ele){
	//create a node
	struct node *link = (struct node*) malloc (sizeof(struct node)); 
	/* by this you are creating a node whose address is being stored in the link pointer. */
	
	link->element = ele;

	//point it to old first node
	link->next = head->first;

	//point first to new first node
	head -> first = link;
	head -> count ++;
	
	//traverse(head);
}

//delete first item
void deletFromFront(struct linkedList *head){
	//exercise to implement this operation
	//printf("%d", (head->count));
	if(head -> count != 0){
		struct node *temp  = head -> first;
		head -> first = temp -> next;
		head -> count --;
		//printf("%d\n", temp -> element);
		free(temp);
	}else{
		printf("-2\n");
	}
}

//insert first item
void insertAtEnd(struct linkedList * head, int ele){
	if(head -> count == 0){
		insertInFront(head, ele);
	}else{
	//create a node
	struct node *ptr = head->first;
	struct node *link = (struct node*) malloc (sizeof(struct node)); 
	/* by this you are creating a node whose address is being stored in the link pointer. */
	
	//start from the beginning
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	
	link->element = ele;
	link->next = NULL;
	ptr->next = link;
	head -> count ++;
	//traverse(head);
	}	
}

//delete first item
void deleteAtEnd(struct linkedList *head){
	//exercise to implement this operation
	if(head -> count == 1){
		deletFromFront(head);
	}else if(head -> count != 0){
		struct node *ptr = head->first;
		while((ptr->next)->next != NULL){
			ptr = ptr->next;
		}	
		struct node *temp = ptr -> next;
		ptr -> next = NULL;
		head -> count --;
		printf("%d\n", temp -> element);
		free(temp);
	}else{
		printf("-2\n");
	}
}

//display the list
void traverse(struct linkedList * head){
	struct node *ptr = head->first;

	//start from the beginning
	while(ptr != NULL){
		printf("%d\t", ptr->element);
		ptr = ptr->next;
	}
	printf("-2\n");
}

void deleteAll(struct linkedList * head){
	if(head -> count == 0){
		printf("%d\n", -3);
	}else{
		while(head -> count != 0){
			deletFromFront(head);
		}
		traverse(head);
	}
}

