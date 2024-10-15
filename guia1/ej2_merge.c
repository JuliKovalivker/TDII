#include <stdio.h>
#include <stdlib.h>


int* merge(int* A, int sizeA, int* B, int sizeB) {

	int lon = sizeA + sizeB;
    int* c = (int*) malloc( sizeof(int) * lon); 
	int i = 0;
	int j = 0;
	while(A[i]!=0){
		c[i] = A[i];
		i++;
	}
	while(B[j]!=0){
		c[i+j] = B[j];
		j++;
	}
	c[i+j] = 0;
	
	int menor = 0;
	int temp = 0;
	for (int i = 0; i<lon; i++){
		menor = i;
		for(int j = i; j<lon; j++){
			if (c[menor] > c[j]){
				menor = j;
			}
		}
		temp = c[i];
		c[i] = c[menor];
		c[menor] = temp;
	}
    
    return c;
}

int main() {

    int a[5] = {4,5,6,7,8};
    int b[5] = {1,2,-2,9,6};

    int* result = merge(a, 5, b, 5);

    printf("Result:");
    for(int i=0; i<10; i++) {
        printf(" %i", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
