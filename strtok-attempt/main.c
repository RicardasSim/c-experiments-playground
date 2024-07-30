#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str_1[] = "aaa/bbb/ccc,ddd/eee/fff,ggg/hhh/iii";
char str_2[] = "aaa/bbb/ccc,ddd/eee/fff,ggg/hhh/iii";
char str_3[] = "aaa/bbb/ccc,ddd/eee/fff,ggg/hhh/iii";
char str_4[] = "aaa/bbb/ccc,ddd/eee/fff,ggg/hhh/iii";

int main()
{

    printf("(1)\n");

    printf("str 1: %s\n", str_1 );

    char *token = strtok( str_1, "/" );

    while ( token != NULL )
    {
        printf("%s\n", token );
        token = strtok( NULL, "/" );
    }

    printf("str 1: %s\n", str_1 );

    printf("\n(2)\n");

    printf("str 2: %s\n", str_2 );

    char delim[] = "/,";
    token = strtok( str_2, delim );


    while ( token != NULL )
    {
        printf("%s\n", token );
        token = strtok( NULL, delim );
    }

    printf("str 2: %s\n", str_2 );

    /*------------------------------------------------------------
      The strtok_r() function is a reentrant version of strtok().
      Reentrant functions can be safely called simultaneously
      from multiple threads or contexts without interfering with
      each other.
    ------------------------------------------------------------*/

    printf("\n(3)\n");

    printf("str 3: %s\n", str_3 );

    char *save_ptr_1;

    char *token_1 = strtok_r ( str_3, ",", &save_ptr_1 );

    while ( token_1 != NULL )
    {
        char *save_ptr_2;

        printf("Token 1: %s\n", token_1 );

        char *token_2 = strtok_r( token_1, "/", &save_ptr_2 );

        while ( token_2 != NULL )
        {
            printf("Token 2: %s\n", token_2 );

            token_2 = strtok_r( NULL, "/", &save_ptr_2 );
        }

        token_1 = strtok_r(NULL, ",", &save_ptr_1 );
    }

    printf("str 3: %s\n\n", str_3 );

    printf("\n(4)\n");

    printf("str 4: %s\n", str_4 );

    printf("str 4 address: %p\n", (void*)str_4 );

    char *save_ptr_4;

    char *token_4 = strtok_r ( str_4, ",", &save_ptr_4 );

    printf("(1) save_ptr_4 points to: %p\n", (void*)save_ptr_4 );

    while ( token_4 != NULL )
    {

        printf("Token 4: %s\n", token_4 );

        token_4 = strtok_r(NULL, ",", &save_ptr_4 );

        printf("(2) save_ptr_4 points to: %p\n", (void*)save_ptr_4 );
    }

    printf("str 4: %s\n", str_4 );

    printf("str 4 address: %p\n", (void*)str_4 );

    putchar('\n');

    return 0;
}
