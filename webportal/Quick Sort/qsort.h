#include<stdio.h>

typedef struct student{
	unsigned int marks;
	char name[20];	
} * stu;

/*quick sort main*/
void quickSort(stu ls, int lo, int hi);

/*quick sort main*/
void quickSort2(stu ls, int lo, int hi);

/*quick sort main*/
void quickSort3(stu ls, int lo, int hi);

/*quick sort main*/
void quickSort4(stu ls, int lo, int hi);

/*quick sort main partial*/
void partialQuickSort(stu ls, int lo, int hi, int t);

/*prints the list*/
void printList(stu ls, int lo, int hi);

/*pivot*/
int pivot(stu ls, int lo, int hi);

/*partitioning*/
int part(stu ls, int lo, int hi, int p);

