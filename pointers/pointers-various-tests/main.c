#include <stdio.h>
#include <stdlib.h>



int main()
{
    float a[][3] = {0};

    printf("Array size: %zu x %zu\n",
            sizeof(a) / sizeof( a[0] ),
            sizeof(a[0]) / sizeof(a[0][0]) );

    for ( unsigned int i = 0; i < sizeof(a) / sizeof(a[0]); ++i )
    {
        for ( unsigned int j = 0; j < 3; ++j )
        {
            printf("a[%d][%d] = %.2f\n", i, j, a[i][j] );
        }
    }

    return 0;
}
