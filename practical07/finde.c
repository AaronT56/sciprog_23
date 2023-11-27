// Find e using Taylor series expansion for e^x


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Initialise prototypes of functions
int factorial(int n);
// We will use dynamic memory allocation using malloc() where 
// we use pointers to allocate memory during the program's runtime. 
// This is why the "term" variable is a pointer as during the runtime,
// the size of the array will be determined and is not known beforehand.
// This is dynamic memory allocation.
int main(void){
  
  //As we are saving these as integers, when we reach higher powers of e
  // our series expansion will become further from e rather than closer.
  // This is a result of integer overflow. There is a limit on which we can
  // represent pure integers. If you are out of this range, the numbers become strange and don
  // represent what we want anymore. In this situation it can be better
  // to use long integers or signed integers.
  int i, order;
  double e, *terms;
  
  printf("Please enter your desired polynomial order\n");
  // We can even do some error checking using scanf which will help
  // for debugging if needed later.
  if(scanf("%d", &order) != 1){
    printf("Inputs must be a number\n");
    return 1;
  }

  //We will establish an array with allocates space based on n. This
  //is where malloc() will be used.
  terms = malloc(order*sizeof(double));
  // Now the array elements will be filled in.
  for(i = 0; i < order; i++){
    // Here the factorial constants of each term are determined.
    terms[i] = 1.0/(double)factorial(i+1);

    printf("e term for order %d is %1.14lf \n", i+1, terms[i]);
  }
  
  // Now simply compute the formula starting off with e = 1 as
  // this will always be the first term. Then each of the other
  // terms in can be calculated using the terms[i] array.
  e = 1.0;
  for(i = 0; i < order; i++){
    e = e + terms[i];
  
  }
  // Always remember to free your array as they may have thousands
  // of elements.
  free(terms);
  
  // Here we are printing e with 10 figures of scientific notation
  // followed by the difference between the true e value and the one
  // which we have calculated.
  printf("e is estimated as %.10lf, with difference %e\n", e, e-exp(1.0));
  
  return 0;
  
}
// Here we will write the factorial function to be used in main

int factorial(int n){
  // FIrst we do some error checking ensuring that our function
  // does not take inputs less than n.
  if(n<0){
    printf("Error: The number you have input is negative:.\n");
    return(-1);
  }
  // It is standard to define 0! as 1.
  else if(n==0){return 1;}
  else{return(n*factorial(n-1));}
}
