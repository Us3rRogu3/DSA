#include "linkedlist.h"
#include<stdio.h>

//circular stack
typedef struct cstack1{ 
	int count;
	int maxCount;
	Ele top;
	Ele bottom;
} * CircularStack;

//top element
Ele top1(CircularStack c);

//push
void cpush(CircularStack c, int e);

//pop
Ele cpop(CircularStack c);

//print
void cprint(CircularStack c);

//fixsize
void csize(CircularStack c,int size);

