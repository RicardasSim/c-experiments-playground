#include <stdio.h>
#include <stdlib.h>

void TestProgSh1( char *psz_str )
{
    printf("From TestProgSh1: %s\n", psz_str );
}

int TestProgSum1( int a, int b )
{
   return a + b;
}

void TestProgSum2( int a, int b, int *p_result )
{
   *p_result =  a + b;
}
