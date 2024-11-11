#include <stdio.h>
#include <stdlib.h>

int len(char* s) {
	
	int i = 0;
	while (s[i]!=0){
		i++;
	}
	
	return i;
}

char* copy(char* s) {
	
	char* c = (char*) malloc( sizeof(char) * len(s)); 
	int i = 0;
	while (s[i]!=0){
		c[i] = s[i];
		i++;
	}
	
	return c;
}

void replaceChar(char* s, char old, char new) {
	
	int i = 0;
	while(s[i]!=0){
		if(s[i] == old){
			s[i] = new;
		}
		i++;
	}
	
}

char* concatenate(char* s1, char* s2) {
	
	char* c = (char*) malloc( sizeof(char) * (len(s1) + len(s2))); 
	int i = 0;
	int j = 0;
	while(s1[i]!=0){
		c[i] = s1[i];
		i++;
	}
	while(s2[j]!=0){
		c[i+j] = s2[j];
		j++;
	}
	c[i+j] = 0;
	return c;
}

int main() {
	
	char* s1 = "Ramon";
	char* s2 = "Ricardo";
	
	printf("El string \"%s\" mide %i\n",s1, len(s1));
	printf("El string \"%s\" mide %i\n",s2, len(s2));
	
	char* copyS1 = copy(s1);
	char* copyS2 = copy(s2);
	
	printf("El string \"%s\" es una copia de  %s\n",copyS1, s1);
	printf("El string \"%s\" es una copia de  %s\n",copyS2, s2);
	
	replaceChar(copyS1, 'a', 'o');
	replaceChar(copyS2, 'R', 'T');
	
	printf("Sobre el string \"%s\" remplazo 'a' por 'o': %s\n",s1, copyS1);
	printf("Sobre el string \"%s\" remplazo 'R' por 'T': %s\n",s2, copyS2);
	
	printf("Concateno \"%s\" con \"%s\":",copyS1, copyS2);
	
	char* concat = concatenate(copyS1, copyS2);
	
	printf(" \"%s\"\n",concat);
	
	free(concat);
	
	
	return 0;
}
