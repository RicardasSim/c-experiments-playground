#include <stdio.h>
#include <stdlib.h>

typedef struct st{
    char c;
    int i;
    float f;
}St;

void *TestInit()
{
    printf("TestInit\n");

    St *p_s = calloc( 1, sizeof(St) );

    if ( !p_s )
    {
        return NULL;
    }

    return p_s;

}

void TestClean( void *p )
{
    printf("TestClean\n");
    free( p );
    p = NULL;
}

void TestProc()
{
    printf("TestProc\n");
}
