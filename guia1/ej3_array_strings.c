#include <stdio.h>
#include <stdlib.h>

char* longest(char* v[], int size) {

	int l[size];
	for(int i = 0; i<size; i++){
		l[i] = 0;
		int j = 0;
		while(v[i][j] != 0){
			j++;
		}
		l[i] = j;
	}
	int mayor = 0;
	for (int i = 1; i<size; i++){
		if (l[i] > l[mayor]){
			mayor = i;
		}
	}
	printf("%i",l[mayor]);
	char* c = (char*) malloc( sizeof(char) * (l[mayor])); 
	
	for(int i=0;i<l[mayor];i++) { 
		c[i] = v[mayor][i];
	}
	c[l[mayor]]=0;
	
	return c;
}

char* superConcatenate(char* v[], int size) {
	int cont = 0;
	int i = 0;
	int j = 0;
	while(v[i]!= 0){
		while(v[i][j]!=0){
			j++;
		}
		i++;
		cont += j;
		j = 0;
	}
	
	char* c = (char*) malloc( sizeof(char) * (cont)); 
	i = 0;
	j = 0;
	int x = 0;
	while(v[i]!= 0){
		while(v[i][j]!=0){
			c[x]= v[i][j];
			j++;
			x++;
		}
		i++;
		j = 0;
	}
	c[x] = 0;
	return c;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {
	int cont = 0;
	int i = 0;
	int j = 0;
	while(v[i]!= 0){
		while(v[i][j]!=0){
			j++;
		}
		i++;
		cont += j;
		j = 0;
	}
	
	char* c = (char*) malloc( sizeof(char) * (cont+1)); 
	i = 0;
	j = 0;
	int x = 0;
	while(v[i]!= 0){
		while(v[i][j]!=0){
			c[x]= v[i][j];
			j++;
			x++;
		}
		i++;
		j = 0;
	}
	c[x] = 0;
	return c;
}

int main() {

    char* v[5] = {"hola", "como", "va", "el", "dia"};

    char* sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);
	
	free(sc);
	
	char* abc = superConcatenateWithSep(v, 5, "");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", abc);

    //free(abc);

	char* asdd = longest(v, 5);
	
	printf("El string mas largo es: \"%s\"\n", abc);
	
    return 0;
}
