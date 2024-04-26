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

bool TestAllocateMem( int **p, size_t n )
{

    *p = malloc(n);

    if ( !*p )
    {
        printf("ERROR: cannot allocate memory.\n");
        return false;
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

    int *buffer;
    unsigned int num = 10;

    if ( !TestAllocateMem( &buffer, num * sizeof *buffer ) )
    {
        printf("ERROR: TestAllocateMem failed.\n");
        return 1;
    }

    for ( unsigned int i = 0; i < num; ++i )
    {
        buffer[i] = i;
    }

    for ( unsigned int i = 0; i < num; ++i )
    {
        printf("%d ", buffer[i] );
    }

    printf("\n\n");

    free( buffer );

    return 0;
}
