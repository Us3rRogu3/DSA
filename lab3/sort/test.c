
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	double i = 1;
	int *ptr = (int * ) calloc(i ,sizeof(int));
	while(i != 0){
		int *temp = ptr;
		i = i*2;
		ptr = (int*) calloc(i, sizeof(int));
		printf("%lf\n", i);
		free(temp);
	}
}
