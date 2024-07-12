#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ARR 32

typedef struct{
    char c;
    int i;
    float f;
}St;

int main()
{
    St **p_arr;

    printf("(sizeof p_arr): %zu\n", sizeof p_arr );
    printf("(sizeof *p_arr): %zu\n", sizeof *p_arr );
    printf("(sizeof **p_arr): %zu\n", sizeof **p_arr );

    p_arr = malloc( NUM_OF_ARR * sizeof *p_arr );

    if( !p_arr )
    {
        printf("Error: cannot allocate memory (1)\n");
        exit(EXIT_FAILURE);
    }

    for ( unsigned int i = 0; i < NUM_OF_ARR; ++i )
    {
        p_arr[i] = malloc( sizeof **p_arr );

        if ( !p_arr[i] )
        {
            printf("Error: cannot allocate memory (2)[%d]\n", i);

            for ( unsigned int j = i; j > 0; --j )
            {
                free( p_arr[ j - 1 ] );
            }

            exit(EXIT_FAILURE);

        }
    }

    //**********

    p_arr[0]->c = 'a';
    p_arr[0]->i = 1;
    p_arr[0]->f = 10.0f;

    printf("[0] %c %i %f\n",
            p_arr[0]->c,
            p_arr[0]->i,
            p_arr[0]->f );

    //**********

    for( unsigned int i = 0; i < NUM_OF_ARR; ++i )
    {
        free( p_arr[i] );
    }

    free( p_arr );

    exit(EXIT_SUCCESS);
}
