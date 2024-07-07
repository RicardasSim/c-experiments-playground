#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_STR_MAX 512

typedef struct st {
    char str_1[TEST_STR_MAX];
    char str_2[TEST_STR_MAX];
    char *p_str;
    int i_v;
    double d_v;
} St;

int main()
{
    /*
    GCC extension, specifying ranges
    [6 ... 9] = 50
    gcc with -Wpedantic
    warning: ISO C forbids specifying range of elements to initialize [-Wpedantic]
    */

    int arr[10] = { 10, 20, [4] = 30, [5] = 40 };

    for ( unsigned int i = 0; i < sizeof arr / sizeof *arr ; ++i )
    {
        printf("%d ", arr[i] );
    }

    putchar('\n');

    St st_arr[6];

    st_arr[0] = ( struct st ){ "Stairway", "Zeppelin", NULL, 1, 0.1 };
    st_arr[1] = ( St ){ "Rain", "Roses", NULL, 1, 0.1 };

    strcpy( st_arr[2].str_1, "Rising" );
    strcpy( st_arr[2].str_2, "Animals" );
    st_arr[2].p_str = NULL;
    st_arr[2].i_v = 123;
    st_arr[2].d_v = 123.45;

    // with designated initializers

    st_arr[3] = ( St ){ .p_str = NULL, .str_1 = "Yell", .str_2 = "Idol" };
    st_arr[4] = ( St ){ .p_str = NULL, .str_2 = "Forever", .str_1 = "Queen", .d_v = 321.1 };

    //------------------------------

    st_arr[5] = ( St ){ .i_v = 123 , .d_v = 321.1 };

    char test_str_1[] = "Camouflage";
    char test_str_2[] = "Shield";

    size_t len = sizeof test_str_1;

    memcpy( st_arr[5].str_1, test_str_1, len );
    st_arr[5].str_1[len] = '\0';

    st_arr[5].p_str = test_str_2;

    for ( unsigned int i = 0; i < sizeof st_arr / sizeof *st_arr ; ++i )
    {
        printf("%s %s %s %d %f\n",
                st_arr[i].str_1,
                st_arr[i].str_2,
                st_arr[i].p_str,
                st_arr[i].i_v,
                st_arr[i].d_v );
    }

    putchar('\n');

    return 0;
}
