#include <stdio.h>
#include "search.h" 

int main () {

	int arr_int[5] = {1,2,3,4,5};
	double arr_float[] = {1.0,2.0,3.0,4.0,5.0};

	int i = 3;
	double f = 3.0;	
	
	printf(" %d %d %d %d\n",sizeof(i),sizeof(f),sizeof(arr_int),sizeof(arr_float));
	//printf(" %f",arr_float[0]);
	printf(" HelloWorld %d",linear_search(arr_int,&i));
	
	//printf(" HelloWorld %d",linear_search(a,&item));

}