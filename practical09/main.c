#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"
// This will tell you how big the file which you are importing is/how big
// the matrix is.

int getlines(char filename[MAX_FILE_NAME]);

int main(){  

    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // ##! n function which gets the number of lines
    int n = getlines(filename);

    // TODO: Open the file 
    f = fopen(filename, "r");
    if(f == NULL){
        printf("!! can't open file !!\n");
	exit(1);
    }

    int i;
    // TODO: Allocating a matrix for storing the magic square
    // as an array of pointers, where each pointer is a row 
    int **magicsquare = malloc(n*sizeof(int*));
    // We use a double pointer to create a 2-d array by dynamically allocating
    // to 1-d arrays.
    for(i = 0; i < n; i++){
	magicsquare[i] = malloc(n*sizeof(int));
    }

    // TODO:inputting integer data into the matrix;
    int j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
	// Now we will read value by value from the file to the matrix.
	// We use fscanf to read from the file.
	fscanf(f, "%d", &magicsquare[i][j]);
	printf("%d\t", magicsquare[i][j]);
	}	
    
    printf("\n");
    }
    // here we use the ? to have two different outputs of our printf depeding on 
    // whether isMagicSquare outputs true or false.
    printf("This square %s magic\n", isMagicSquare(magicsquare, n)? "is" : "is NOT");

    // TODO: Freeing each row separately before freeing the array of pointers
    for(i = 0; i < n; i++){
	free(magicsquare[i]);
    }
    free(magicsquare);

    // TODO:Close the file
    fclose(f);

    return 0;
}  

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    // This is a pointer to a file type.
    FILE *fp;
    // Opens the system file and assigns pointer to it.
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;
    // This code is reading characters from a file using the fgetc function until it
    // reaches the end of the file (EOF, which stands for End of File). 
    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}
