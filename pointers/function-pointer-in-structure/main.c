#include <stdio.h>
#include <stdlib.h>

int TestFncA( int a, int b )
{
    return a + b;
}

int TestFncM( int a, int b )
{
    return a * b;
}

int main()
{

    typedef int (*pfnAdd)( int, int );
    typedef int (*pfnMul)( int, int );

    typedef struct st
    {
        int res;
        pfnAdd Add;
        pfnMul Mul;
    } St;

    {
        St s;

        s.Add = &TestFncA;
        s.Mul = &TestFncM;

        s.res = (s.Add)( 3, 7 );

        printf("(1) %d\n", s.res );

        s.res = (s.Mul)( 3, 7 );

        printf("(2) %d\n", s.res );

    }

    {

        St *p_s;

        p_s = malloc( sizeof *p_s );

        if ( !p_s )
        {
            printf("Error: cannot allocate memory\n");
            return 1;
        }

        p_s->Add = &TestFncA;
        p_s->Mul = &TestFncM;

        p_s->res = (p_s->Add)( 3, 7 );

        printf("(3) %d\n", p_s->res );

        p_s->res = (p_s->Mul)( 3, 7 );

        printf("(4) %d\n", p_s->res );

        free( p_s );

    }

    return 0;
}
