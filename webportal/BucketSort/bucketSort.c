#include<stdio.h>
#include<stdlib.h>
#include "bucketSort.h"

/* bucketSort function for case 1 */
void buckSort(li lis){
	int i = 0, m = lis -> xhi - lis -> xlo, n = lis -> yhi - lis -> ylo, lim = lis -> count, j = 0;
	//printf("%d %d", m , n);
	tu temp = lis -> tup;
	bu bucky;
	if(m <= n){
		bucky = malloc(sizeof(struct bucket) * m);
		for(i = 0; i< m; i++){
			(bucky + i) -> ele = lis -> xlo + i;
			(bucky + i) -> head = NULL;
		}
		//printf("alloc done\n");
		for(i = 0; i< lim; i++){		
			int c = (temp + i) -> x;
			addToBucket((bucky + c - lis -> xlo), (temp + i) -> y);
		}
		//printf("sort done");
		for(i = 0; i< m; i++){
			if((bucky + i) -> head != NULL){
				no ptr = (bucky + i) -> head -> first;
				while(ptr != NULL){
					(temp + j) -> x = (bucky + i) -> ele;
					(temp + j) -> y = ptr -> ele;
					j++;
					ptr = ptr -> next;
				}
			}
		}
	}else{
		bucky = malloc(sizeof(struct bucket) * n);
		for(i = 0; i< n; i++){
			(bucky + i) -> ele = lis -> ylo + i;
			(bucky + i) -> head = NULL;
		}
		for(i = 0; i< lim; i++){		
			int c = (temp + i) -> y;
			addToBucket((bucky + c - lis -> ylo), (temp + i) -> x);
		}
		for(i = 0; i< n; i++){
			if((bucky + i) -> head != NULL){
				no ptr = (bucky + i) -> head -> first;
				while(ptr != NULL){
					(temp + j) -> y = (bucky + i) -> ele;
					(temp + j) -> x = ptr -> ele;
					j++;
					ptr = ptr -> next;
				}
			}
		}
		//printf("else case");
	}
	printlist(lis);
}

//add to bucket
void addToBucket(bu bucky, int val){
	//printf("bucky is %d\n",bucky -> ele); 
	if(bucky -> head == NULL){
		//printf("bucy head is null");
		ll temp = (ll) malloc(sizeof(struct linkedlist));
		temp -> first = NULL;
		temp -> count = 0;
		bucky -> head = temp;
		//printf("this should run");
	}
	//printf("before insertInto");
	insertInto(bucky -> head, val);
}


//traverse list
void printlist(li lis){
	tu temp = lis -> tup;
	int i = 0, lim = lis -> count;
	for(i = 0;i < lim; i++){
		printf("%d %d\n", (temp + i) -> x, (temp + i) -> y);
	}
}
