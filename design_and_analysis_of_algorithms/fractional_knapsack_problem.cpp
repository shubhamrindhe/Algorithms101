#include<stdio.h>
#include<stdlib.h>

void swap(double* x,double* y){
	double temp = *x;
	*x = *y;
	*y = temp;
}

double getMaxPrice(int n,double* w,double* v,double sackSize){
	double maxPrice = 0;
	double sackFill = 0;
	
	double* v_per_w;
	v_per_w = (double*) malloc(sizeof(double)*n);
	
	for(int i=0;i<n;++i)
		*(v_per_w+i) = *(v+i) / *(w+i);
			
	for(int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j)
			if(*(v_per_w+i) < *(v_per_w+j) )
			{	
				swap(v_per_w+i,v_per_w+j);
				swap(w+i,w+j);
				swap(v+i,v+j);
			}
	
	for(int i=0;i<n;++i){
		if(sackFill<sackSize){
			if(*(w+i)>(sackSize-sackFill)){
				maxPrice += ((sackSize-sackFill))*(*(v_per_w+i));
				sackFill += (sackSize-sackFill);
			}else{
				maxPrice += (*(w+i)) * (*(v_per_w+i));
				sackFill += *(w+i);	
			}
		}else{
			
		}	
	}
	free(v_per_w);
	return maxPrice;
}

int main(){
	int choice;
	int n;
	double* weight;
	double* value;
loop :	
	printf("\n [1] to use default values.\n [2] to enter your own weights and values. ");
	printf("\n Enter choice : ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			n=3;
			weight = (double*) malloc(sizeof(double)*n);
			value  = (double*) malloc(sizeof(double)*n);
			
			*(weight) = 18;		//weights = {18,15,10};
			*(weight+1) = 15;
			*(weight+2) = 10;
			
			*(value) = 25;		//values  = {25,24,15};
			*(value+1) = 24;
			*(value+2) = 15;
			
			break;
		case 2:
			printf("\n Enter number of Stoleables : ");
			scanf("%d",&n);
			
			weight = (double*) malloc(sizeof(double)*n);
			value  = (double*) malloc(sizeof(double)*n);
			
			printf("\n Enter %d weight-values pairs :  \n",n);
			for(int i=0;i<n;++i)
				scanf("%lf%lf",(weight+i),(value+i));
				
			for(int i=0;i<n;++i)
				printf("\n %f %f",*(weight+i),*(value+i));	
				
			break;	
	}
	printf("\n maxPrice : %.10f",getMaxPrice(n,weight,value,20));
	free(weight);
	free(value);

	return 0;
}
