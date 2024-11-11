#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int rc1 = fork();
	
	if (rc1 == 0){
		printf("Soy Amaranta, hija de Jose Arcadio");
		exit(0);
	}
	
	int rc2 = fork();
	if (rc2 == 0){
		printf("Soy Aureliano, hijo de Jose Arcadio");
		exit(0);
	}
	
	int rc3 = fork();
	if (rc3 == 0){
		printf("Soy Jose Arcadio, hija de Jose Arcadio");
		exit(0);
	}
	
	wait(0);
	wait(0);
	wait(0);
	printf("Soy Jose Arcadio, padre de todas/os");

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

