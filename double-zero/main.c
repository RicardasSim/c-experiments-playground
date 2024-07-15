#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[]="A\0" "ABC\0" "Zeppelin\0" "Cassiopeia Constellation\0";

int main()
{

    // print str in hex

    for( unsigned int i = 0; i < sizeof str; ++i )
    {
        printf("%xh ",str[i]);
    };

    putchar('\n');

    printf( "(1) %zu\n", sizeof str );

    unsigned int offset = 0;
    char c = 0;
    char c_prev =0;

    while(1)
    {
        c_prev = c;
        c = str[ offset ];
        offset++;

        if( c == 0 && c_prev == 0 )
        {
            break;
        }
    };

    printf("(2) %d\n", offset );


    offset = 0;
    c = 0;
    c_prev = 0;

    while(1)
    {
        c_prev = c;
        c = str[ offset ];

        if( c == 0 && c_prev ==0 )
        {
            break;
        }

        offset++;
    };

    printf("(3) %d\n", offset );

    return 0;
}
