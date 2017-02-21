/* linkedlist.h */
#include <stdio.h>


// structure definitions
// structure of a linked list node. It contains an element
typedef struct node {
	int ele;
	struct node * next;
} * no;



/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */
typedef struct linkedlist {
	int count;
	struct node * first;
} * ll;

void insertInto(struct linkedlist * head, int val);
/* inserts in sorted order */


/* End of linkedlist.h */
