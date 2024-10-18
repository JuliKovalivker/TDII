#include <stdio.h>
#include <stdlib.h>

int sumAsBytes(char* v) {

	int suma = v[0];
	for(int i = 1; i<12; i++){
		suma += v[i];
	}
    return suma;
}

int sumAsInts(int* v) {

	int suma = v[0];
	for(int i = 1; i<12; i++){
		if(i%4 == 0){
			suma += v[i];
		}
		else if(i == 1|| i%4 == 1){
			suma += v[i]*16*16;
		}
		else if(i == 2 || i%4 == 2){
			suma += v[i]*16*16*16*16;
		}
		else if(i == 3 || i%4 == 3){
			suma += v[i]*16*16*16*16*16*16*16*16;
		}
	}
	return suma;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[12] = {0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00};
	
	int f[12] = {0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00};
	
	
    int sumB = sumAsBytes((char*)v);
    int sumI = sumAsInts((int*)f);

    printf("El arreglo sumado de a bytes es: %i (d) %x (h)\n", sumB, sumB);
    printf("El arreglo sumado de a ints es: %i (d) %x (h)\n", sumI, sumI);

    // */

    return 0;
}
