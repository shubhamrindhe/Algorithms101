#include<stdio.h>
#include<stdlib.h>

long long* fib_list (long long n) {
	long long* data = (long long*) malloc( sizeof(long long) * n ); 
	for (unsigned i=0; i < n; ++i) {
		if (i==0 || i==1) {
			data[i] = 1;
		} else  {
			data[i] = data[i-1] + data[i-2];
		}
		printf(" %ld ",data[i]);
	}
	return data;
}

long long fib_ele (long long n) {
	long long last,second_last,current;
	for (unsigned i=0; i < n; ++i) {
		if (i==0) {
			last = 1;
			current = last;
		} if (i==1) {
			second_last = 1;
			current = second_last;
		} else {
			current = second_last + last;
			second_last = last;
			last = current;
		}
		printf(" %ld ",current);
	}
	return current;
}

int main() {
	printf(" \n\n\n\n ");
	
	fib_list(10);
	
	printf(" \n\n\n\n ");
	
	fib_ele(10);
	
	return 0;
}