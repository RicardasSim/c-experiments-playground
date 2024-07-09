#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 3
#define LEN 64

void TestFnc1( char (*arr)[LEN] )
{
    strcpy( arr[0], "first");
    strcpy( arr[1], "second");
    strcpy( arr[2], "third");
}

void TestFnc2( char arr[][LEN] )
{
    strcpy( arr[0], "one");
    strcpy( arr[1], "two");
    strcpy( arr[2], "three");
}

int main()
{
    char d_arr[NUM][LEN] = { 0 };

    TestFnc1( d_arr );

    puts( d_arr[0] );
    puts( d_arr[1] );
    puts( d_arr[2] );
    putchar('\n');

    TestFnc2( d_arr );

    puts( d_arr[0] );
    puts( d_arr[1] );
    puts( d_arr[2] );
    putchar('\n');

    return 0;
}
