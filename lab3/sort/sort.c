#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void insertsort(int *val){
	int i, j, temp;
	for(i = 1; i< 10000; i++){
		temp = *(val + i); 
		j = i - 1;
		while(j >= 0 && temp < *(val+j)){
			*(val + j + 1) = *(val + j);
			j--;
		}
		*(val + j + 1) = temp;
	}
}

int main(){
	FILE *fptr = fopen("input.txt", "r");
	FILE *fptr2;
	char *file = (char*) malloc(sizeof(char)*10);
	int i, j, temp, *val = (int*) malloc(sizeof(int)*100000);
	for(i = 0; i< 1000; i++){
		sprintf(file, "%df.txt", i+1);
		fptr2 = fopen(file, "w");
		for(j = 0; j< 10000; j++){
			fscanf(fptr, "%d", &temp);
			*(val + j) = temp;					
		}
		insertsort(val);
		for(j = 0; j< 10000; j++){
			fprintf(fptr2, "%d\n", *(val+j));					
		}
		printf("%s done \n", file);
	}
	free(val);
}


