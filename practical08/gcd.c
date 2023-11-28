#include<stdio.h>
// We are going to create a function which outputs the
// greatest common divisor of two integers.


// We will create the gcd function which takes two integers and retruns an integer.

int iterative_gcd(int a, int b){
  int temp;

  // The modulo symbol (%) divides the given numerator by the denominator.
  // This will iteratively go through the demoninators of 
  // the integers a and b and will calculate the gcd through
  // by outputing a once b has reached 0 (when the gcd is found).
  while(b != 0){
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;  
}

// Now, we calculate the gcd using a recursive function as follows:
// When doing recursive functions look at the formula and think
// about the return statements you want (they will be the two different
// statements of the formula).
int recursive_gcd(int a, int b){
  if(b == 0){
    return a;
  }
  else
  {
    // A "trick" of recursive functions is that the arguments which you pass here
    // when you call a recursive function are not going to be the original arguments.
    // So you are at risk of creating an infinite loop if not careful.
   return recursive_gcd(b, a % b);
  }
}
// Now we can use the function in main()


int main(){
  int a;
  int b;
  printf("Enter one of the integers which you require the gcd of a:\n");
  scanf("%d", &a);
  if(a <= 0){
  printf("Number must be positive\n");
  return 1;
  }
  printf("Enter one of the integers which you require the gcd of b:\n");
  scanf("%d", &b);
  if(b <= 0){
  printf("Number must be positive\n");
  return 1;
  }
  int ans_r = recursive_gcd(a,b);
  int ans_i = iterative_gcd(a,b);
  printf("Using iteration, we get %d\n", ans_i);
  printf("Using recursion, we get %d\n", ans_r);
  return 0;
}


