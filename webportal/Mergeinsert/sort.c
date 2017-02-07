#include <stdio.h>
#include "sort.h"

void mergeins(int* arr, int l, int h){
	if(l == h - 1){
		return;
	}else{
		//printf("run %d, %d: \n",l, h); 
		int m = (l+h)/2;
		mergeins(arr, l, m);
		mergeins(arr, m, h);
		int i = m, j = l, k = 0, temp;
		while(i < h && j < h && j < i){
			if(*(arr + j) > *(arr + i)){
				temp = *(arr + i);
				for(k = i; k > j; k--){
					*(arr + k) = *(arr + k - 1);
				}
				*(arr + j) = temp;
				i++;
				j++;
			}else{
				j++;			
			}
		}	
		/*i = l;
		while(i < h){
			printf("%d\n", *(arr + i));
			i++;
		}
		printf("run complete %d, %d: \n",l, h); */
	}
}

