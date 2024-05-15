#include <stdio.h>
#include <stdlib.h>

void TestFnc( void *p, size_t n )
{

    switch (n)
    {
    case sizeof(int):
        printf("%d\n", *((int*)p) );
        break;
     case sizeof(double):
        printf("%f\n", *((double*)p) );
        break;
    default:
        printf("Unknown\n");
        break;
    }

}

int main()
{
    int i = 123;

    double d = 0.123;

    void *p_v;

    p_v = &i;

    printf("%d\n", *(int *)p_v );

    p_v = &d;

    printf("%f\n", *(double *)p_v );

    TestFnc( &i, sizeof i );

    TestFnc( &d, sizeof d );

    return 0;
}
