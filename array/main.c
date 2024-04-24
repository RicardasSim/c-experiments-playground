#include <stdio.h>
#include <stdlib.h>

int main()
{

    char c_array[10] = {0};
    int i_array_1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int i_array_2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    double d_array[3] = { 0.0 };

    printf("sizeof c_array: %zu\n", sizeof c_array );
    printf("sizeof i_array_1: %zu\n", sizeof i_array_1 );
    printf("sizeof i_array_2: %zu\n", sizeof i_array_2 );
    printf("sizeof d_array: %zu\n", sizeof d_array );

    puts("");

    // number of elements in array

    printf("Num of elements: c_array: %zu\n", sizeof c_array / sizeof c_array[0] );
    printf("Num of elements: i_array_1: %zu\n", sizeof i_array_1 / sizeof i_array_1[0] );
    printf("Num of elements: i_array_2: %zu\n", sizeof i_array_2 / sizeof i_array_2[0] );
    printf("Num of elements: d_array: %zu\n", sizeof d_array / sizeof d_array[0] );

    puts("");

    printf("Num of elements: c_array: %zu\n", sizeof c_array / sizeof *c_array );
    printf("Num of elements: i_array_1: %zu\n", sizeof i_array_1 / sizeof *i_array_1 );
    printf("Num of elements: i_array_2: %zu\n", sizeof i_array_2 / sizeof *i_array_2 );
    printf("Num of elements: d_array: %zu\n", sizeof d_array / sizeof *d_array );

    puts("");

    // size of array element

    printf("Elem. size: c_array: %zu\n", sizeof c_array[0] );
    printf("Elem. size: i_array_1: %zu\n", sizeof i_array_1[0] );
    printf("Elem. size: i_array_2: %zu\n", sizeof i_array_2[0] );
    printf("Elem. size: d_array: %zu\n", sizeof d_array[0] );

    puts("");

    printf("Elem. size: c_array: %zu\n", sizeof *c_array );
    printf("Elem. size: i_array_1: %zu\n", sizeof *i_array_1 );
    printf("Elem. size: i_array_2: %zu\n", sizeof *i_array_2 );
    printf("Elem. size: d_array: %zu\n", sizeof *d_array );

    puts("");

    char *p_c_array = NULL;

    p_c_array = c_array;

    printf("Address of c_array: %p\n", (void*) c_array );
    printf("Address p_c_array points to: %p\n", (void*) p_c_array );

    c_array[0] = 'M';
    c_array[1] = 'I';
    c_array[2] = 'C';

    p_c_array[3] = 'R';
    p_c_array[4] = 'O';
    p_c_array[5] = 'S';

    *(p_c_array + 6) = 'C';
    *(p_c_array + 7) = 'O';
    *(p_c_array + 8) = 'P';
    *(p_c_array + 9) = 'E';

    // Loop Through an Array

    for ( unsigned int i = 0; i < sizeof c_array / sizeof *c_array; ++i )
    {
        printf ("%c ", c_array[i] );
    }

    puts("");

    printf("*p_c_array : %c\n", *p_c_array );
    printf("*(p_c_array + 1) : %c\n", *(p_c_array + 1) );
    printf("*p_c_array + 1 : %c\n", *p_c_array + 1 );

    puts("");


    d_array[0] = 0.1;
    d_array[1] = 0.2;
    d_array[2] = 0.3;

    double *p_d_array = NULL;

    p_d_array = d_array;

    printf("Address of d_array: %p\n", (void*) d_array );
    printf("Address p_d_array point to: %p\n", (void*) p_d_array );

    printf("Address of d_array[1]: %p\n", (void*) &d_array[1] );
    printf("Address (p_d_array + 1) points to: %p\n", (void*) (p_d_array + 1) );

    puts("");

    printf("Test 1 : %f\n", d_array[0] );
    printf("Test 2 : %f\n", *(++p_d_array) );
    printf("Test 3 : %f\n", *(p_d_array + 1) );

    puts("");

    return 0;
}
