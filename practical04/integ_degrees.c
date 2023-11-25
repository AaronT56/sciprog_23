#include<stdio.h>
#include<math.h>

// Here we define the names of the functions which we will be using and
// the types of inputs which they will take
float degrees_to_radians(float degrees);
double traprule(int N);

int main(){
	int N = 12;
	double integral_approximation = traprule(N);
	double exact_integral = log(2.0);
	
	printf("The approximate value obtained by the trapezoidal rule for 12 boxes between 0 and 60 degrees is:\n%.5f\nThe exact solution is:\n%.5f\n",integral_approximation, exact_integral);

	return(0);		
}
// This function converts degrees to radians by multiplying by pi/180
float degrees_to_radians(float degrees){
	return (degrees * M_PI)/180.0;
}

double traprule(int N){
	// We define each of the variables which will be used in the traprule function 
	int i;
	double degrees;
	double radians;
	double TanValues[N+1];
	double width;

	// This will loop through all of the values from 0 to N (which is 12). 
	// This will therefore generate the degrees from 0 to 60 as we are multiply by 5.
	// Then the degrees_to_radians function which is defined above will convert 
	// degrees to radians is used to change these degrees to radians. Finally, the tan
	// values are calculated using the tan function from the math package.
	
	for(i=0; i <= N; i++){
		degrees = i * 5.0;
		radians = degrees_to_radians(degrees);
		TanValues[i] = tan(radians);
		}

	// We add the tan values at the endpoints and define that to be the area
	// as is the case in the trapezoidal rule formula.
	double area = TanValues[0] + TanValues[N];
	
	// To perform the trapezoidal approximation it is further necessary to compute the 
	// intermediary tan values between the two endpoints and multiply them by two. 
	// This will give us the total area which can be used as part of the formula.
	for(i = 1; i < N; i++){
		area += 2.0*TanValues[i];
	
	}
	// Once we have the areas, we simply multiply these this total area by the width of each box
	// which should result in a good approximation for the area under the curve. Finally,
	// the trapezoidal approximation can now be made.
	width = degrees_to_radians(60/(2.0*N));
	area *= width;
	return area;
}


