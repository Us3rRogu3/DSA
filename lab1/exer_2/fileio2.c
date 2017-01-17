#include<stdio.h>
#include<stdlib.h>

int main(){
	int num;
	FILE *f = fopen("program.txt", "r");	

	if(f == NULL){
		printf("Error!");
		exit(1);	
	}

	fscanf(f, "%d", &num);

	printf("value is %d", num);
	fclose(f);
	
	return 0;
}


