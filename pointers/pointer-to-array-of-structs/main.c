#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char c;
    int i;
    float f;
}St;

int main()
{
    St s_arr[32] = {0};

    printf("(sizeof s_arr): %zu\n", sizeof s_arr );
    printf("(sizeof *s_arr): %zu\n", sizeof *s_arr );

    St st_0 = { 'a', 1, 10.0f };
    St st_1 = { 'b', 2, 20.0f };
    St st_2 = { 'c', 3, 30.0f };

    //**********

    St (*p_1_arr)[];

    p_1_arr = &s_arr;

    (*p_1_arr)[0] = st_0;

    printf("[0] %c %i %f\n",
            s_arr[0].c,
            s_arr[0].i,
            s_arr[0].f );

    //**********

    typedef St p_arr[];

    p_arr *p_arr_2;

    p_arr_2 = &s_arr;

    (*p_arr_2)[1] = st_1;

    printf("[2] %c %i %f\n",
            s_arr[1].c,
            s_arr[1].i,
            s_arr[1].f );

    //**********

    s_arr[2] = st_2;

    printf("[2] %c %i %f\n",
            s_arr[2].c,
            s_arr[2].i,
            s_arr[2].f );

    return 0;
}
