#include <stdio.h>
int main(void) {
	int i, ierr; 
	double a;

	printf("Enter an int and double\n");
	ierr = scanf("%d %lf",&i,&a);


	if(ierr != 2) printf("Problem with input");
	return(0);
}
