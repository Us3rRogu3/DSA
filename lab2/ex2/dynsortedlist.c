#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int currcount = 0;
int currsize = 2;
int *array;

void addbin(int e){
	int l = 0, h = currcount;
	while(l < h){
		int m = (l+h)/2;
		if(*(array + m) > e){
			h = m;
		}else{
			l = m + 1;
		}
	}
	for(int i = currcount; i >= l; i--){
		*(array + i + 1) = *(array + i);
	}
	*(array + l) = e;
}

void add(int e){
	time_t start = time(NULL);
	if(currcount < currsize){
		printf("case1\n");
		addbin(e);
		currcount++;
	}else{
		currsize = currsize * 2;
		int *array2 = (int *) malloc(currsize * sizeof(int));
		for( int i = 0; i < currsize; i++){
			*(array2 + i) = *(array + i); 
		}
		free(array);
		array = array2;
		printf("case2\n");
		addbin(e);
		currcount++;
	}  
	time_t end = time(NULL);
	printf("Time taken: %f\n", difftime(end, start));
}

int main(){
	array = (int *) malloc(currsize * sizeof(int));
	int choice = 0;
	int val = 0;
	while(choice != 3){
		printf("1.add, 2.print, 3.exit\n Enter: ");
		scanf("%d", &choice);
		if(choice == 1){
			printf("Enter: ");
			scanf("%d", &val);
			add(val);
		}else if (choice == 2){
			for(val = 0; val<currcount; val++){
				printf("%d, ", *(array+val));
			}
			printf("\n");
		}else{}
	}

}
