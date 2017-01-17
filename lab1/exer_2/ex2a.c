#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
	if(argc < 3 || argc > 3){
		printf("Invalid Arguments");
		exit(1);	
	}
	char temp[100];
	FILE *f1 = fopen(argv[1], "r"), *f2 = fopen(argv[2], "w");	
	if(f1 == NULL || f2 == NULL){
		printf("ERROR!");
		exit(1);
	}
	while(!feof(f1)){
		fscanf(f1, "%s", temp);
		fprintf(f2, "%s\n", temp);
	}
}
