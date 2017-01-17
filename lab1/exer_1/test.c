#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int isint(char a[]){
	int i = 0;
	for(int i = 0; a[i] != '\0'; i++){
		if(!isdigit(a[i]))
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[]){
	int i = 0, temp;
	printf("%d entries\n", argc); 
	for(i = 1; i< argc; i++){
		if(isint(argv[i])){
			temp = atoi(argv[i]);
			printf("Integer - %i\n", temp);
		}
		else
			printf("String - %s\n", argv[i]);
	}
	printf("is the entry. \n");
}
