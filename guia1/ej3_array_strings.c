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
	l[size] = 0;
	int mayor = l[0];
	for (int i = 0; i<size; i++){
		if (l[i] > l[mayor]){
			mayor = i;
		}
	}
	return v[mayor];
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
	
	char* c = (char*) malloc( sizeof(char) * cont); 
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
    return c;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {

    // COMPLETAR

    return 0;
}

int main() {

    char* v[5] = {"hola", "como", "va", "el", "dia"};

    char* l = longest(v, 5);

    printf("El string mas largo es: \"%s\"\n", l);

    char* sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);

    /*char* scs = superConcatenateWithSep(v, 5, "...");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", scs);

    free(sc);
    free(scs);

    // */

    return 0;
}
