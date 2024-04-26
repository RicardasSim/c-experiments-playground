#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct testS {
    int a;
    int b;
} TestS;

void TestFnc1( int *p_v )
{
    *p_v += 1;
}

void TestFnc2( TestS *p_s )
{
    p_s->a += 1;
    p_s->b += 1;
}

bool TestAllocateMem1( int **p, size_t n )
{

    *p = malloc(n);

    if ( !*p )
    {
        printf("ERROR: cannot allocate memory (1).\n");
        return false;
    }

    return true;
}

bool TestAllocateMem2( int **p, unsigned int num )
{

    *p = malloc( num * sizeof **p );

    if ( !*p )
    {
        printf("ERROR: cannot allocate memory (2).\n");
        return false;
    }

    for ( unsigned int i = 0; i < num; ++i )
    {
        *( *p + i ) = i;
    }

    return true;
}

bool TestAllocateMem3( int **p, unsigned int num )
{

    *p = malloc( num * sizeof **p );

    if ( !*p )
    {
        printf("ERROR: cannot allocate memory (3).\n");
        return false;
    }

    for ( unsigned int i = 0; i < num; ++i )
    {
        (*p)[i] = i;
    }

    return true;
}

int main()
{

    int a = 0;

    printf("%d\n", a );

    TestFnc1( &a );

    printf("%d\n\n", a );

    /**********/

    TestS s = { 1, 5 };

    printf("struct a: %d b: %d\n", s.a, s.b );

    TestFnc2( &s );

    printf("struct a: %d b: %d\n\n", s.a, s.b );

    /**********/
    {
        int *buffer_1;
        unsigned int num_1 = 10;

        if ( !TestAllocateMem1( &buffer_1, num_1 * sizeof *buffer_1 ) )
        {
            printf("ERROR: TestAllocateMem1 failed.\n");
            return 1;
        }

        for ( unsigned int i = 0; i < num_1; ++i )
        {
            buffer_1[i] = i;
        }

        for ( unsigned int i = 0; i < num_1; ++i )
        {
            printf("%d ", buffer_1[i] );
        }

        printf("\n\n");

        free( buffer_1 );
    }

    /**********/

    {
        int *buffer_2;
        unsigned int num_2 = 8;

        if ( !TestAllocateMem2( &buffer_2, num_2 ) )
        {
            printf("ERROR: TestAllocateMem2 failed.\n");
            return 1;
        }

        for ( unsigned int i = 0; i < num_2; ++i )
        {
            printf("%d ", buffer_2[i] );
        }

        printf("\n\n");

        free( buffer_2 );
    }

    /**********/

    {
        int *buffer_3;
        unsigned int num_3 = 8;

        if ( !TestAllocateMem3( &buffer_3, num_3 ) )
        {
            printf("ERROR: TestAllocateMem3 failed.\n");
            return 1;
        }

        for ( unsigned int i = 0; i < num_3; ++i )
        {
            printf("%d ", buffer_3[i] );
        }

        printf("\n\n");

        free( buffer_3 );
    }

    return 0;
}
