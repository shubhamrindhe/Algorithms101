 
int linear_search (int *collection, void* data) {
	int size = sizeof(collection);
	int index = -1;
	
	printf("\n\nsize %d %d \n\n",size,sizeof(*data));
	
	for (int idx=0;idx<size;++idx) {
		
		printf(" %d %d \n",sizeof( *((int*)collection+idx) ),*((int *)collection+idx));
		
		
		//printf(" %d ",*(collection+idx));
		if (*((int *)data) == *((int *)collection + idx)) {
			index = idx;
			break;
		}
		
	}
	
	return index;
}

int binary_search (int *collection, int* data) {
	
	
	
}

