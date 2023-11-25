#include<stdio.h>
#include<math.h>

// Defining functions 

double arctanh1(const double x, const double delta);

double arctanh2(const double x);

// The main function will simply ask the user for the necessary inputs and then print the output based on the user's criteria.

int main(){
	double delta, x;

	printf("Please enter your desired precision for the Maclaurin Series \n");
	scanf("%lf", &delta);

	// This defines the length of the output array.
	int length = 1000;

	double tan1[length]; // This stores the output for arctanh1
	double tan2[length]; // This stores the output for arctanh2

	int j = 0; // This will be the index of our array
	x = -0.9; // the starting value of the array
	
	while(x <= 0.9 && j < length){
		tan1[j] = arctanh1(x, delta); // Creates an array of the outputs using Maclaurin series for arctanh
		tan2[j] = arctanh2(x); // Creates an array of outputs using the log function
		printf("The difference between the two methods at x = %lf is found to be %.10lf.\n", x, fabs(tan1[j] - tan2[j]));
		j++;
		x = x + 0.01; // Creates array where values of x range from -0.9 to 0.9 in steps of 0.01
}
return(0);

}
// The archtanh1 will be the function to define the hyperbolic
// tangent as a Maclaurin Series.
double arctanh1(const double x, const double delta){
	// Here we define the variables of the function.
	// arcTan will be used to summate each iteration of the series
	// and find the total. elem will calculate the total value of each iteration (each value of n).
	// val will simply calculate 2n+1 (in the formula). By summing each iteration of the series,
	// we attain the desired result.
	double arcTan = 0;
	double elem, val;
	int n = 0; 
	// A do while loop is suitable as we are going to loop over and over through several values until
	// we reach the stopping criteria.
	do{
		val = 2 * n + 1;
		elem = pow(x, val)/val;
		arcTan += elem;
		n++;
	}  while(fabs(elem) >= delta);
	return arcTan;
}
// arctanh2 is a bit simpler as we simply compute some logs of a variable x
double arctanh2(const double x){
	return ((log(1+x) - log(1-x))/2);
}
