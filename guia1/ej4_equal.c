#include <stdio.h>
#include <stdlib.h>

void pairOfEquals(char v[], int size, char** a, char** b) {

    for(int i = 0; i<size;i++){
		for(int j = i+1; j<size; j++){
			if(v[i] == v[j]){
				*a = &v[i];
				*b = &v[j];
				return;
			}
		}
	}
	*a = 0;
	*b = 0;

}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[5] = {9, 5, 6, 4, 1};

    char* a;
    char* b;

    pairOfEquals(v, 8, &a, &b);

    if(a == 0 || b == 0) {
        printf("No hay iguales");
    } else {
        printf("Los valores iguales son: %i == %i\n", (char)(*a), (char)(*b));
    }

    // */

    return 0;
}
