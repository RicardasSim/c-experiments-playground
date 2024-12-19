#include <stdio.h>
#include <stdlib.h>

int CompareChars( const void *p_a, const void *p_b )
{
    return ( *(char *)p_a - *(char *)p_b );
}

void PrintArray( char arr[], int size )
{
    for ( int i = 0; i < size; ++i )
    {
        printf("%c ", arr[i] );
    }
    printf("\n");
}

int main()
{
    char arr_c[] = { 'i', 'j', 'c', 'd', 'e', 'f', 'g', 'h', 'b', 'a' };

    PrintArray( arr_c, sizeof( arr_c ) / sizeof( arr_c[0] ) );

    qsort( arr_c, sizeof( arr_c ) / sizeof( arr_c[0] ), sizeof( arr_c[0] ), CompareChars );

    PrintArray( arr_c, sizeof( arr_c ) / sizeof( arr_c[0] ) );

    return 0;
}
