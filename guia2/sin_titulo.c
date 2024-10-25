#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include <time.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
	/*
	char* nombres[3] = {"Amaranta", "Aureliano", "Jose"};
	for(int i = 0; i<3; i++){
		int rc = fork();
		if (rc == 0){
			printf("Soy %s, hija de Jose Arcadio\n", nombres[i]);
			exit(0);
		}
	}
	*/
	int rc1 = fork();
	if (rc1 == 0){
		printf("Soy Amaranta, hija de Jose Arcadio\n");
		exit(0);
	}
	
	int rc2 = fork();
	if (rc2 == 0){
		printf("Soy Aureliano, hijo de Jose Arcadio\n");
		exit(0);
	}
	
	int rc3 = fork();
	if (rc3 == 0){
		printf("Soy Jose Arcadio, hija de Jose Arcadio\n");
		exit(0);
	}
	
	wait(0);
	wait(0);
	wait(0);
	printf("Soy Jose Arcadio, padre de todas/os");
	
	return 0;
}

