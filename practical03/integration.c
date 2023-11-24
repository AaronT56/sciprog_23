#include<stdio.h>
#include<math.h>

int main(){

// Initialising Number of points to be used specifying N = 12
// Defining the trapezoidal formula


int N = 12;
double x_0 = 0.0;
double x_12 = M_PI/3.0;
double width = (x_12-x_0)/(double)N;

// Create the function over which the integral will be approximated

double X = tan(x_0)+tan(x_12);

// Calculating tan at each of the points and obtaining their values.

double y;
double x;
double sum = X;

int i;
for(i=1; i<12; i++){


	x = x_0 + width*i;
	y = tan(x);
	sum += 2*y;
}
double int_approximation = sum * width * 0.5;
double true_integral = log(2.0);

printf("The approximate value of the integral for tan(x) between 0 and pi/3 is :\n%.5f\n with exact solution of:\n%.5f\n",int_approximation,true_integral);

return(0);
}
