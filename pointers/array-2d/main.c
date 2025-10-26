#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num_of_rows = 3;
    int num_of_cols = 4;

    // Allocate memory for an array of int pointers

    int **p_mtrx = malloc( num_of_rows * sizeof(int *) );

    if ( p_mtrx == NULL )
    {
        // If allocation fails, print an error and exit
        printf("Error: failed to allocate memory for p_mtrx.\n");
        return 1;
    }

    // Allocate memory for each row and initialize values

    for ( int i = 0; i < num_of_rows; ++i )
    {
        p_mtrx[i] = malloc( num_of_cols * sizeof(int) );

        if ( p_mtrx[i] == NULL )
        {
            // If allocation fails for a row,
            // clean up previously allocated rows
            printf("Error: failed to allocate memory for p_mtrx row [%d].\n", i);

            for ( int j = 0; j < i; ++j )
            {
                // Free each previously allocated row
                free( p_mtrx[j] );
            }

            // Free the top-level pointer array
            free( p_mtrx );

            return 1;
        }

        // Fill the row with sample values
        // sequential integers
        for ( int j = 0; j < num_of_cols; ++j )
        {
            p_mtrx[i][j] = i * num_of_cols + j;
        }

    }

    // Print the contents of the 2D array
    printf("Contents:\n");

    for ( int i = 0; i < num_of_rows; ++i )
    {
        for ( int j = 0; j < num_of_cols; ++j )
        {
            printf("%d ", p_mtrx[i][j] );
        }
        
    printf("\n");
    }

    // Free all allocated memory
    
    // Free each row
    for ( int i = 0; i < num_of_rows; ++i )
    {
        free( p_mtrx[i] ); 
    }

    // Free the array of row pointers
    free( p_mtrx ); 

    // Exit normal

    return 0;
}
