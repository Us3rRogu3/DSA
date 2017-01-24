#include "cstack.h"
#include<stdio.h>
#include<stdlib.h>

//top element
Ele top1(CircularStack c){
	return c -> bottom;
}

//push
void cpush(CircularStack c, int e){
	Ele link = (Ele) malloc(sizeof(Ele));
	link -> element = e;
	link -> next = NULL;
	if(c -> count == 0){
		c -> top = c -> bottom = link;
		c -> top -> next = c -> bottom;
		c -> bottom -> next = c-> top;
		c -> count++;
	}else if(c -> count < c -> maxCount){
		link -> next = c -> top;
		c -> bottom ->	next = link;
		c -> count++;
		c -> bottom = link;
	}else{
		Ele temp = c -> top;
		link -> next = c -> top -> next;
		c -> bottom -> next = link;
		c -> top = link -> next;
		free(temp);
	}
		printf("count   %d 1 %d 2 %d", c -> count, c-> top -> element, c -> bottom -> element);
}

//pop
Ele cpop(CircularStack c){
	if(c -> count = 0){
		printf("Invalid");
	}else{
		Ele temp = c -> bottom;
		while( temp -> next != c -> bottom){
			temp = temp -> next;
		}
		Ele temp2 = temp -> next;
		temp -> next = c -> top;
		c -> bottom = temp;
		c -> count --;
		return temp2;
	}
}

//print
void cprint(CircularStack c){
	Ele temp = c -> bottom;
	do{
		printf("%d, ", temp -> element);
		temp = temp -> next;
	}while( temp != c -> bottom);
	printf("\n");
}

//fixsize
void csize(CircularStack c,int size){
	c -> maxCount = size;
	c -> top = NULL;
	c -> bottom = NULL;
	c -> count = 0;
}

