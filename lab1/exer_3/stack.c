/* linkedlist.c */
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

//insert first item
void push(struct linkedList * head, int ele){
	insertFirst(head, ele);
}

//delete first item
struct node* pop(struct linkedList *head){
	return deleteFirst(head);
}

