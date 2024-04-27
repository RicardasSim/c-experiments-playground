#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Fnc3( int **p, int *val, unsigned int num )
{
    *p = malloc( num * sizeof **p );

    if ( !*p )
    {
        printf("ERROR: cannot allocate memory.\n");
        return false;
    }

    for ( unsigned int i = 0; i < num; ++i )
    {
        // (*p)[i] = i;
        *( *p + i ) = i;
    }

    *val += 1;

    return true;
}

bool Fnc2( int **p_buff, int *p_val, unsigned int num )
{

    if ( !Fnc3( p_buff, p_val, num ) )
    {
        printf("ERROR: Fnc3 failed.\n");
        return 1;
    }

    *p_val += 1;

    return true;
}

bool Fnc1( int **p_buff, int *p_val, unsigned int num )
{

    if ( !Fnc2( p_buff, p_val, num ) )
    {
        printf("ERROR: Fnc2 failed.\n");
        return 1;
    }

    *p_val += 1;

    return true;
}

int main()
{

    int *buff = NULL;
    int test_val = 123;
    unsigned int num = 3;

    if ( !Fnc1( &buff, &test_val, num ) )
    {
        printf("ERROR: Fnc1 failed.\n");
        return 1;
    }

    for ( unsigned int i = 0; i < num; ++i )
    {
        printf("%d ", buff[i] );
    }

    free( buff );

    printf("\n%d\n\n", test_val );

    return 0;
}
