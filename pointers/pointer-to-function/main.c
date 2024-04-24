#include <stdio.h>
#include <stdlib.h>

void Fnc( int a )
{
    printf("%d\n", a );
}

int main()
{
    //void (*f_p)(int);
    //f_p = &Fnc;

    void (*f_p)(int) = &Fnc;

    (*f_p)( 123 );

    return 0;
}
