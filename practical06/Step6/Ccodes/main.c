#include<stdio.h>

int main(){

  int n=5, p=3, q=4; // Define how big the matrices that will be multiplied will be.
  double A[n][p], B[p][q], C[n][q]; // signify the size of each of the matrices which will be used
  int i, j, k; // These will be used to loop through the rows and columns 
  
  // To initialize the matricse, the following code is necessary:
  // The A matrix will be composed of the sum of the two row and column
  // indexes. Hence, we will just create a nested loop to go through
  // each i and j and adding the two to get the inputs of A.
  for(i = 0; i < n; i++){
    for(j = 0; j < p; j++){
    A[i][j] = i+j;
    }
  }

  // This will be similar to A but with i-j rather than i+j forming the
  // inputs of the matrix.
  for(i = 0; i < p; i++){
    for(j = 0; j < q; j++){
    B[i][j] = i-j;
    }
  }
  // Matrix C is calculated by multiplying A and B. But first, we must
  // initialize C by setting all of the inputs to 0. The multiplication
  // will be performed later.
  for(i = 0; i < n; i++){
    for(j = 0; j < q; j++){
    C[i][j] = 0;
    }
  }

  //This time we will not be doing the matrix multiplication in this file.
  //Instead, we take the matmult.c file which is in the same directory as
  //the main.c file and use the function from there in this file to perform
  //the same task

  matmult(n, p, q, A, B, C);

  // Finally, the matrices will be printed by using another nested
  // loop which will iteratively go through each element of the matrix
  // and print them. This is done for all three matrices, the only
  // change being the size of the matrix.
  printf("\nThis is the matrix A:\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < p; j++){
      printf("%3.0f ", A[i][j]);
    }
  printf("\n");
  }

  printf("\nThis is the matrix B:\n");
  for(i = 0; i < p; i++){
    for(j = 0; j < q; j++){
      printf("%3.0f ", B[i][j]);
    }
  printf("\n");
  }

  printf("\nThis is the matrix C:\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < q; j++){
      printf("%3.0f ", C[i][j]);
    }
  printf("\n");
  }

return(0);
}

