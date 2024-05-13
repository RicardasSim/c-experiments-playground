#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// TODO: int buffer

void TestBuffer( char *p_buff,
                 size_t n )
{
    long int sum = 0;

    for ( unsigned int i = 0; i < n; ++i )
    {
        sum += p_buff[i];
    }

    printf("sum: %ld size: %zu\n", sum, n );
}


bool ExpandBufferZeroFillExpanded( char **p_buff,
                                   size_t *p_current_size,
                                   size_t chunk_size_to_add )
{

    size_t new_size = *p_current_size + chunk_size_to_add;

    char *p_tmp = realloc( *p_buff, new_size );

    if ( !p_tmp )
    {
        printf("ERROR: cannot reallocate memory\n");
        return false;
    }

    // Fill the newly allocated memory with zeroes
    memset( p_tmp + *p_current_size, 0, chunk_size_to_add );

    *p_buff = p_tmp;

    *p_current_size = new_size;

    return true;
}

int main()
{

    size_t current_size = 1024;

    printf("(1)\n");

    char* buffer = calloc( current_size, sizeof(char) );

    if ( !buffer )
    {
        printf("ERROR: cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }

    TestBuffer( buffer, current_size );

    /************************************************************/

    printf("(2)\n");

    if ( !ExpandBufferZeroFillExpanded( &buffer,
                                        &current_size,
                                        1024 ) )
    {
        printf("ERROR: ExpandBufferZeroFillExpanded\n");
        free( buffer );
        exit(EXIT_FAILURE);
    }

    TestBuffer( buffer, current_size );

    /************************************************************/

    printf("(3)\n");

    if ( !ExpandBufferZeroFillExpanded( &buffer,
                                        &current_size,
                                        1024 ) )
    {
        printf("ERROR: ExpandBufferZeroFillExpanded\n");
        free( buffer );
        exit(EXIT_FAILURE);
    }

    TestBuffer( buffer, current_size );

    free( buffer );

    exit(EXIT_SUCCESS);
}
