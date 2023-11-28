#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


int isMagicSquare(int ** square, const int n) {

    // Eliminate the case where 'n' is negative
    if(n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    int M = (n * (n*n + 1))/2;
    printf("M = %d\n", M);

    int i, j;
    // TODO: Checking that every row and column add up to M
    // Iterating through row indices of magic square:
    for(i = 0; i < n; i ++){
        int rowSum = 0;
        int colSum = 0;
        // Iterate through column indices and add row and column sums up.
        for(j = 0; j < n; j++){
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        printf("i = %d, rowSum = %d, colSum = %d\n", i, rowSum, colSum);
	// Thus line will ensure that the matrix we are dealing with is in fact a magic square.
        if(rowSum != M || colSum != M){
	    return 0;
        }
    }
    // TODO: Checking that the main and secondary
    // diagonals each add up to M
    // If passed all checks, it is a magic square
    // First define both diagonal sums.
    int diagSum = 0;
    int secDiagSum = 0;   
    for(i = 0; i < n; i ++){
    // The diagonals are located at the intersection if ith row
    // and ith columns, hence we use the following code:
        diagSum += square[i][i];
	secDiagSum += square[i][n-i-1];
    }
    printf("diagSum = %d, secDiagSum = %d\n", diagSum, secDiagSum);
    if(diagSum != M ||  secDiagSum != M){
            return 0;
        }
    // Essentially we have checked if any of the conditions of a magic square matrix have 
    // not been met and if the code reaches this point that implies that none of
    // these conditions are not met. Hence, we say it is a magic square matrix and 
    // return 1.
    return 1;
}

