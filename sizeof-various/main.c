#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    char c;
    int i;
    float f;
    double d;
    char *p_c;
    int *p_i;
    float *p_f;
    double *p_d;
    void *p_v;
} St;

int main()
{

    printf("sizeof(char): %zu\n", sizeof( char ) );
    printf("sizeof(int): %zu\n", sizeof( int ) );
    printf("sizeof(float): %zu\n", sizeof( float ) );
    printf("sizeof(double): %zu\n", sizeof( double ) );

    {

        char c;
        int i;
        float f;
        double d;

        printf("sizeof c: %zu\n", sizeof c );
        printf("sizeof i: %zu\n", sizeof i );
        printf("sizeof f: %zu\n", sizeof f );
        printf("sizeof d: %zu\n", sizeof d );

        printf("sizeof &c: %zu\n", sizeof &c );
        printf("sizeof &i: %zu\n", sizeof &i );
        printf("sizeof &f: %zu\n", sizeof &f );
        printf("sizeof &d: %zu\n", sizeof &d );

    }

    {

        char *p_c;
        int *p_i;
        float *p_f;
        double *p_d;

        printf("sizeof *p_c: %zu\n", sizeof *p_c );
        printf("sizeof *p_i: %zu\n", sizeof *p_i );
        printf("sizeof *p_f: %zu\n", sizeof *p_f );
        printf("sizeof *p_&d: %zu\n", sizeof *p_d );

        printf("sizeof p_c: %zu\n", sizeof p_c );
        printf("sizeof p_i: %zu\n", sizeof p_i );
        printf("sizeof p_f: %zu\n", sizeof p_f );
        printf("sizeof p_d: %zu\n", sizeof p_d );

    }

    {

        char **p_d_c;
        int **p_d_i;
        float **p_d_f;
        double **p_d_d;

        printf("sizeof **p_d_c: %zu\n", sizeof **p_d_c );
        printf("sizeof **p_d_i: %zu\n", sizeof **p_d_i );
        printf("sizeof **p_d_f: %zu\n", sizeof **p_d_f );
        printf("sizeof **p_d_&d: %zu\n", sizeof **p_d_d );

        printf("sizeof *p_d_c: %zu\n", sizeof *p_d_c );
        printf("sizeof *p_d_i: %zu\n", sizeof *p_d_i );
        printf("sizeof *p_d_f: %zu\n", sizeof *p_d_f );
        printf("sizeof *p_d_&d: %zu\n", sizeof *p_d_d );

        printf("sizeof p_d_c: %zu\n", sizeof p_d_c );
        printf("sizeof p_d_i: %zu\n", sizeof p_d_i );
        printf("sizeof p_d_f: %zu\n", sizeof p_d_f );
        printf("sizeof p_d_d: %zu\n", sizeof p_d_d );

    }

    {

        St s;

        printf("sizeof s: %zu\n", sizeof s );
        printf("sizeof &s: %zu\n", sizeof &s );
        printf("sizeof s.c: %zu\n", sizeof s.c );
        printf("sizeof s.i: %zu\n", sizeof s.i );
        printf("sizeof s.f: %zu\n", sizeof s.f );
        printf("sizeof s.d: %zu\n", sizeof s.d );
        printf("sizeof s.p_c: %zu\n", sizeof s.p_c );
        printf("sizeof s.p_i: %zu\n", sizeof s.p_i );
        printf("sizeof s.p_f: %zu\n", sizeof s.p_f );
        printf("sizeof s.p_d: %zu\n", sizeof s.p_d );
        printf("sizeof s.p_v: %zu\n", sizeof s.p_v );
        printf("sizeof *s.p_c: %zu\n", sizeof *s.p_c );
        printf("sizeof *s.p_i: %zu\n", sizeof *s.p_i );
        printf("sizeof *s.p_f: %zu\n", sizeof *s.p_f );
        printf("sizeof *s.p_d: %zu\n", sizeof *s.p_d );

    }

    {

        St *p_s;

        printf("sizeof *p_s: %zu\n", sizeof *p_s );
        printf("sizeof p_s: %zu\n", sizeof p_s );
        printf("sizeof p_s->c: %zu\n", sizeof p_s->c );
        printf("sizeof p_s->i: %zu\n", sizeof p_s->i );
        printf("sizeof p_s->f: %zu\n", sizeof p_s->f );
        printf("sizeof p_s->d: %zu\n", sizeof p_s->d );
        printf("sizeof p_s->p_c: %zu\n", sizeof p_s->p_c );
        printf("sizeof p_s->p_i: %zu\n", sizeof p_s->p_i );
        printf("sizeof p_s->p_f: %zu\n", sizeof p_s->p_f );
        printf("sizeof p_s->p_d: %zu\n", sizeof p_s->p_d );
        printf("sizeof p_s->p_v: %zu\n", sizeof p_s->p_v );
        printf("sizeof *p_s->p_c: %zu\n", sizeof *p_s->p_c );
        printf("sizeof *p_s->p_i: %zu\n", sizeof *p_s->p_i );
        printf("sizeof *p_s->p_f: %zu\n", sizeof *p_s->p_f );
        printf("sizeof *p_s->p_d: %zu\n", sizeof *p_s->p_d );

    }

    {

        St **p_d_s;

        printf("sizeof **p_d_s: %zu\n", sizeof **p_d_s );
        printf("sizeof *p_d_s: %zu\n", sizeof *p_d_s );
        printf("sizeof p_d_s: %zu\n", sizeof p_d_s );
        printf("sizeof (*p_d_s)->c: %zu\n", sizeof (*p_d_s)->c );
        printf("sizeof (*p_d_s)->i: %zu\n", sizeof (*p_d_s)->i );
        printf("sizeof (*p_d_s)->f: %zu\n", sizeof (*p_d_s)->f );
        printf("sizeof (*p_d_s)->d: %zu\n", sizeof (*p_d_s)->d );
        printf("sizeof (*p_d_s)->p_c: %zu\n", sizeof (*p_d_s)->p_c );
        printf("sizeof (*p_d_s)->p_i: %zu\n", sizeof (*p_d_s)->p_i );
        printf("sizeof (*p_d_s)->p_f: %zu\n", sizeof (*p_d_s)->p_f );
        printf("sizeof (*p_d_s)->p_d: %zu\n", sizeof (*p_d_s)->p_d );
        printf("sizeof (*p_d_s)->p_v: %zu\n", sizeof (*p_d_s)->p_v );
        printf("sizeof *(*p_d_s)->p_c: %zu\n", sizeof *(*p_d_s)->p_c );
        printf("sizeof *(*p_d_s)->p_i: %zu\n", sizeof *(*p_d_s)->p_i );
        printf("sizeof *(*p_d_s)->p_f: %zu\n", sizeof *(*p_d_s)->p_f );
        printf("sizeof *(*p_d_s)->p_d: %zu\n", sizeof *(*p_d_s)->p_d );

    }

    {
        char arr_c[100];

        printf("sizeof arr_c: %zu\n", sizeof arr_c );
        printf("sizeof *arr_c: %zu\n", sizeof *arr_c );
        printf("sizeof arr_c[0]: %zu\n", sizeof arr_c[0] );
        printf("arr_c num. of elem.: %zu\n", sizeof arr_c / sizeof *arr_c );
    }

    {
        int arr_i[100];

        printf("sizeof arr_i: %zu\n", sizeof arr_i );
        printf("sizeof *arr_i: %zu\n", sizeof *arr_i );
        printf("sizeof arr_i[0]: %zu\n", sizeof arr_i[0] );
        printf("arr_i num. of elem.: %zu\n", sizeof arr_i / sizeof *arr_i );
    }

    {
        float arr_f[100];

        printf("sizeof arr_f: %zu\n", sizeof arr_f );
        printf("sizeof *arr_f: %zu\n", sizeof *arr_f );
        printf("sizeof arr_f[0]: %zu\n", sizeof arr_f[0] );
        printf("arr_f num. of elem.: %zu\n", sizeof arr_f / sizeof *arr_f );
    }

    {
        double arr_d[100];

        printf("sizeof arr_d: %zu\n", sizeof arr_d );
        printf("sizeof *arr_d: %zu\n", sizeof *arr_d );
        printf("sizeof arr_d[0]: %zu\n", sizeof arr_d[0] );
        printf("arr_d num. of elem.: %zu\n", sizeof arr_d / sizeof *arr_d );
    }

    return 0;
}
