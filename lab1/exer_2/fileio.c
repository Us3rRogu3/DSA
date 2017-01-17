#include<stdio.h>
#include<stdlib.h>

int main(){
	int num;
	FILE *f = fopen("program.txt", "w");	

	if(f == NULL){
		printf("Error!");
		exit(1);	
	}

	printf("Enter num: ");
	scanf("%d", &num);

	fprintf(f, "%d", num);
	fclose(f);
	
	return 0;
}


