#include <stdio.h>
#include <stdlib.h>

#define NUM 32

#define STRINGIZER2(x) #x
#define STRINGIZER(x) STRINGIZER2(x)

int main()
{

    unsigned int var = NUM;

    printf ( "%d\n", var );

    char *str = "NUM: " STRINGIZER(NUM);

    printf ("%s\n",  str );

    return 0;
}
