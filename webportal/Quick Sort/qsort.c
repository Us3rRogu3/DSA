#include<stdio.h>
#include<stdlib.h>
#include "qsort.h"


/*quick sort main*/
void quickSort(stu ls, int lo, int hi){
	int p;	
	if(lo < hi){
		p = part(ls, lo, hi, pivot(ls, lo, hi));
		quickSort(ls, lo, p-1);
		quickSort(ls, p+1, hi);
	}		
}


/*quick sort main*/
void quickSort2(stu ls, int lo, int hi){
	int p;	
	if(lo < hi){
		p = part(ls, lo, hi, pivot(ls, lo, hi));
		if(p-1-lo >= 2)
			quickSort2(ls, lo, p-1);
		if(hi-p-1 >= 2)
			quickSort2(ls, p+1, hi);
	}		
}

/*quick sort main*/
void quickSort3(stu ls, int lo, int hi){
	int p;	
	if(lo < hi){
		p = part(ls, lo, hi, pivot(ls, lo, hi));
		if(p-1-lo >= 2)
			quickSort2(ls, lo, p-1);
		if(hi-p-1 >= 2)
			quickSort2(ls, p+1, hi);
	}		
}

/*quick sort main*/
void quickSort4(stu ls, int lo, int hi){
	int p;	
	if(lo < hi){
		p = part(ls, lo, hi, pivot(ls, lo, hi));
		if(p-1-lo >= 2)
			quickSort2(ls, lo, p-1);
		if(hi-p-1 >= 2)
			quickSort2(ls, p+1, hi);
	}		
}

/*quick sort main partial*/
void partialQuickSort(stu ls, int lo, int hi, int t){
	int p;	
	if(hi-lo+1 < t){
		//printf("It is lower %d\n", hi-lo); 
	}else if(lo < hi){
		p = part(ls, lo, hi, pivot(ls, lo, hi));
		partialQuickSort(ls, lo, p-1, t);
		partialQuickSort(ls, p+1, hi, t);
	}		
}

/*pivot*/
int pivot(stu ls, int lo, int hi){
	return hi;
}


/*partioning*/
int part(stu ls, int lo, int hi, int p){
	struct student temp, piv;
	piv = *(ls+p);
	*(ls+p) = *(ls+hi);
	*(ls+hi) = piv;
	int i, curr = lo;
	for(i = lo; i < hi; i++){			
		if(piv.marks > (ls+i)->marks){
			if(curr != i){
				temp = *(ls+i);
				*(ls+i) = *(ls+curr);
				*(ls+curr) = temp;
				curr++;
			}else{
				curr++;			
			}
		}
	}
	temp = *(ls+hi);
	*(ls+hi) = *(ls+curr);	
	*(ls+curr) = temp;
	return curr;
}	


/*prints the list*/
void printList(stu ls, int lo, int hi){
	int i;
	for(i = lo; i <= hi; i++){
		printf("%s %u\n", (ls+i)->name, (ls+i)->marks);
	}
}

