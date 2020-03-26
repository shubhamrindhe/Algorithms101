#include<stdio.h>
#include<stdlib.h>

void tower_of_hanoi (long long n, char source, char auxillary, char destination) {
	if (n==0) {
		return;
	}
	
	tower_of_hanoi(n-1, source, destination, auxillary);
	printf("move disk from %c to %c.\n", source, destination);
	tower_of_hanoi(n-1, auxillary, source, destination);
}

int main() {
	
	printf("dcjsnjjc");
	tower_of_hanoi(5,'A','B','C');
	
	return 0;
}