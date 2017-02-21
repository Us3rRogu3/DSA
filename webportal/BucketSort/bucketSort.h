#include "linkedlist.h"

typedef struct tuple{
	int x;
	int y;
} * tu;

typedef struct bucket{
	int ele;
	ll head;
} * bu;

typedef struct list{
	int xhi;
	int yhi;
	int xlo;
	int ylo;
	int count;
	tu tup;
} * li;

void buckSort(li lis);
/* bucketSort function for case 1 */

void addToBucket(bu buck, int val);
/* add to a certain bucket */ 


void printlist(li lis);
/* print list */
