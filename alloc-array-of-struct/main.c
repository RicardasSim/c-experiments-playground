#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MUM_OF_ST 10

typedef struct
{
    char c;
    int i;
    float f;
    double d;
} St;

typedef struct
{
    char *p_1;
    char *p_2;
} St_p;

void Cleanup( St_p *p, unsigned int num )
{
    for ( unsigned int i = 0; i < num; ++i )
    {
        free( p[i].p_1 );
        free( p[i].p_2 );
    }

    free( p );
}

int main()
{


    St *s_arr = malloc( MUM_OF_ST * sizeof *s_arr );

    if ( !s_arr )
    {
        printf("Error: cannot allocate memory for s_arr.\n");
        exit(EXIT_FAILURE);
    }

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

    /********************************/

    char str_1[] = "Galaxy";
    char str_2[] = "Milky Way";
    char str_3[] = "Constellation";
    char str_4[] = "Cassiopeia";

    St_p *s_arr_2 = calloc( MUM_OF_ST, sizeof *s_arr_2 );

    if ( !s_arr_2 )
    {
        printf("Error: cannot allocate memory for s_arr_2.\n");
        exit(EXIT_FAILURE);
    }

    printf("sizeof St_p: %zu\n", sizeof( St_p ) );
    printf("sizeof *s_arr_2: %zu\n", sizeof *s_arr_2 );
    printf("sizeof s_arr_2[0]: %zu\n", sizeof s_arr_2[0] );
    printf("sizeof s_arr_2: %zu\n", sizeof s_arr_2 );
    printf("sizeof *str_1: %zu\n", sizeof *str_1 );

    /***********/

    s_arr_2[0].p_1 = malloc( ( strlen( str_1 ) + 1 ) * sizeof *str_1 );

    if ( !s_arr_2[0].p_1 )
    {
        printf("Error: cannot allocate memory (1).\n");
        Cleanup( s_arr_2, MUM_OF_ST );
        exit(EXIT_FAILURE);
    }

    strcpy( s_arr_2[0].p_1, str_1 );

    /***********/

    s_arr_2[0].p_2 = malloc( ( strlen( str_2 ) + 1 ) * sizeof *str_2 );

    if ( !s_arr_2[0].p_2 )
    {
        printf("Error: cannot allocate memory (2).\n");
        Cleanup( s_arr_2, MUM_OF_ST );
        exit(EXIT_FAILURE);
    }

    strcpy( s_arr_2[0].p_2, str_2 );

    /***********/

    s_arr_2[1].p_1 = malloc( ( strlen( str_3 ) + 1 ) * sizeof *str_3 );

    if ( !s_arr_2[1].p_1 )
    {
        printf("Error: cannot allocate memory (3).\n");
        Cleanup( s_arr_2, MUM_OF_ST );
        exit(EXIT_FAILURE);
    }

    strcpy( s_arr_2[1].p_1, str_3 );

    /***********/

    s_arr_2[1].p_2 = malloc( ( strlen( str_4 ) + 1 ) * sizeof *str_4 );

    if ( !s_arr_2[1].p_2 )
    {
        printf("Error: cannot allocate memory (4).\n");
        Cleanup( s_arr_2, MUM_OF_ST );
        exit(EXIT_FAILURE);
    }

    strcpy( s_arr_2[1].p_2, str_4 );

    /***********/

    printf("%s %s\n", s_arr_2[0].p_1, s_arr_2[0].p_2 );
    printf("%s %s\n", s_arr_2[1].p_1, s_arr_2[1].p_2 );

    Cleanup( s_arr_2, MUM_OF_ST );

    exit(EXIT_SUCCESS);
}
