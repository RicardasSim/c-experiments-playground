#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 3
#define LEN 64

void TestFnc( char (*arr)[LEN] )
{
    strcpy( arr[0], "first");
    strcpy( arr[1], "second");
    strcpy( arr[2], "third");
}

int main()
{
    char d_arr[NUM][LEN] = { 0 };

    TestFnc( d_arr );

    puts( d_arr[0] );
    puts( d_arr[1] );
    puts( d_arr[2] );

    return 0;
}
