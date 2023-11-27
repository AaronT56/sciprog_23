#include<stdio.h>
#include<stdlib.h>

// Firstly, we create a function which takes an integer as an argument
// and retunrs a pointer to some allocated memory block of that many integers.


int *allocatearray(int n){
  int *p;
  // p is an integer pointer. The int * before malloc is best practice
  // as it tells us what should be returned before malloc. So we are taking
  // n times the sizeof(int) which is 4 bytes of memory.
  p =(int *) malloc(n*sizeof(int));
  // So overall p is some integer pointer and the code returns p which
  // is also an integer pointer which has that many integers. So it does
  // everything we want.
  return p;
}

// Now, take a pointer to an array of integers and fill every cell with one.

// Here we are passing the address (pass by reference) so we don't need to
// return anything.
void fillwithones(int *array, int n){
  int i;
  // Now loop through array making each cell a 1.
  for(i = 0; i < n; i++){
    array[i] = 1;
  }
}


// Now, take a pointer to an array of integer and print its elements on
// the screen.
void printarray(int *array, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("a[%d]: %d\n", i, array[i]); 
  }
}
// Deallocate memory. This assigns the pointer to null to free the location
// which is this pointer is attributed to.
void freearray(int *array){
  free(array);
}


int main(){
  int n, *a;

  printf("Size of the array:\n");

  scanf("%d", &n);
  // Now simply use the above functions to get the desired outputs. What
  // each function does is already outlined.
  a = allocatearray(n);

  fillwithones(a, n);

  printarray(a, n);

  freearray(a);
  
  // Just to ensure a doesn't point anywhere we set a = NULL;
  
  a = NULL;
  
  return(0);

}
