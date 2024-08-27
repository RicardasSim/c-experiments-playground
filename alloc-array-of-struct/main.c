#include <stdio.h>
#include <stdlib.h>

#define MUM_OF_ST 10

typedef struct
{
    char c;
    int i;
    float f;
    double d;
} St;


int main()
{


    St *s_arr = calloc( MUM_OF_ST, sizeof *s_arr );

    printf("sizeof St: %zu\n", sizeof( St ) );
    printf("sizeof *s_arr: %zu\n", sizeof *s_arr );
    printf("sizeof s_arr[0]: %zu\n", sizeof s_arr[0] );
    printf("sizeof s_arr: %zu\n", sizeof s_arr );

    s_arr[0].c = 'a';
    s_arr[0].i = 1;
    s_arr[0].f = 0.1f;
    s_arr[0].d = 1.1;

    s_arr[1].c = s_arr[0].c + 1;
    s_arr[1].i = s_arr[0].i + 1;
    s_arr[1].f = s_arr[0].f + 1.0f;
    s_arr[1].d = s_arr[0].d + 1.0;

    printf( "%c %i %f %f\n", s_arr[0].c, s_arr[0].i, s_arr[0].f, s_arr[0].d );
    printf( "%c %i %f %f\n", s_arr[1].c, s_arr[1].i, s_arr[1].f, s_arr[1].d );

    free( s_arr );

    return 0;
}
