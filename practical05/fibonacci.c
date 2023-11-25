#include <stdio.h>
#include <stdlib.h>

// Creating the functions which will later be used
// We want a function with two arguments. The two arguments will be
// adjacent numbers in a fibonacci series, ie Fn-1 and Fn-2. Then once
// the computation has been done, the Fn and Fn-1 numbers are stored for the
// next iteration when exiting the sequence.

void fibonacci(int *a, int *b);

int main(){
	// f0 and f1 are the first two numbers of the fibonacci series.
	int n, i;
	int f0 = 0, f1 = 1;

	printf("Please enter a positive integer\n");
	scanf("%d", &n);
	
	// The Fibonacci series is only valid from numbers 1 or greater so this error
	// is necessary to prevent certain inputs.
	if(n < 1){
	printf("The number is not a positive integer, please choose a positive integer\n");
	exit(1);
	}

	
	printf("The fibonacci sequence is: \n");
        printf("%d, %d, ", f0, f1);

	// Here the Fibonacci series can be calculated using the fibonacci function
	for(i = 2; i <= n; i++){
		fibonacci(&f1, &f0);
		printf("%d. ", f1);
		
		// This will print a line break every ten lines to make the output cleaner
		// The reason this if statement works is because it is just one line
		// which is a C feature.
		if((i+1)%10 == 0) printf("\n");
		}
		
return(0);
}


void fibonacci(int* a, int *b){
	int next;
	// this next variable describes the next Fn in the fibonacci formula  fn = fn-1 + fn-2
	// a will be used to describe the fn-1 and b to describe fn-2
	
	// The following computes the next value in the Fibonacci sequence
	next = *a + *b;

	// Now we let fn = fn-1 and fn-1 = fn-2 and continue
	*b = *a;
	*a = next;
}
