// This will be used to define a function which will then be used in
// the main.c file. 

void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]){
  int i, j, k;

  // Matrix Multiplication
  for(i = 0; i < n; i++){
    for(j = 0; j < q; j++){
      for(k = 0; k < p; k++){
        C[i][j] = C[i][j] + A[i][k]*B[k][j];
      }
    }
  }
}
