#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *v_str_arr[]={ "A", "ABC", "Zeppelin", "Cassiopeia Constellation" };

int main()
{
    for ( unsigned int i = 0; i < sizeof v_str_arr / sizeof *v_str_arr; ++i )
    {
        char **p;

        p = &v_str_arr[i];

        printf("%s (%zu) %p %p\n",
                v_str_arr[i],
                strlen( v_str_arr[i] ),
                (void*)p,
                (void*)*p );
    }

    return 0;
}
