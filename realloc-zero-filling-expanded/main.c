#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void FillBufferWithOnes( char *p_buff,
                         size_t n )
{

    for ( unsigned int i = 0; i < n; ++i )
    {
        p_buff[i] = 1;
    }

}

void FillBufferWithOnesInt( int *p_buff,
                            size_t n )
{

    for ( unsigned int i = 0; i < n; ++i )
    {
        p_buff[i] = 1;
    }

}

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

void TestBufferInt( int *p_buff,
                    size_t n )
{
    long int sum = 0;

    for ( unsigned int i = 0; i < n; ++i )
    {
        sum += p_buff[i];
    }

    printf("sum: %ld size ( int ): %zu\n", sum, n );
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

bool ExpandBufferZeroFillExpandedInt( int **p_buff,
                                      size_t *p_current_size,
                                      size_t chunk_size_to_add )
{

    size_t new_size = *p_current_size + chunk_size_to_add;

    int *p_tmp = realloc( *p_buff, new_size * sizeof *p_tmp );

    if ( !p_tmp )
    {
        printf("ERROR: cannot reallocate memory\n");
        return false;
    }

    // Fill the newly allocated memory with zeroes
    memset( p_tmp + *p_current_size, 0, chunk_size_to_add * sizeof *p_tmp );

    *p_buff = p_tmp;

    *p_current_size = new_size;

    return true;
}


int main()
{

    size_t current_size = 1024;

    printf("(1)\n");

    char *buffer = calloc( current_size, sizeof *buffer );

    if ( !buffer )
    {
        printf("ERROR: cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }

    TestBuffer( buffer, current_size );

    /************************************************************/

    printf("(2)\n");

    FillBufferWithOnes( buffer, current_size );
    TestBuffer( buffer, current_size );

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

    FillBufferWithOnes( buffer, current_size );
    TestBuffer( buffer, current_size );

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
    current_size = 0;

    /************************************************************/

    size_t current_size_i = 1024;

    printf("(4)\n");

    int *buffer_i = calloc( current_size_i, sizeof *buffer_i );

    if ( !buffer_i )
    {
        printf("ERROR: cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }

    TestBufferInt( buffer_i, current_size_i );

    /************************************************************/

    printf("(5)\n");

    FillBufferWithOnesInt( buffer_i, current_size_i );
    TestBufferInt( buffer_i, current_size_i );

    if ( !ExpandBufferZeroFillExpandedInt( &buffer_i,
                                           &current_size_i,
                                           1024 ) )
    {
        printf("ERROR: ExpandBufferZeroFillExpandedInt\n");
        free( buffer_i );
        exit(EXIT_FAILURE);
    }

    TestBufferInt( buffer_i, current_size_i );

    /************************************************************/

    printf("(6)\n");

    FillBufferWithOnesInt( buffer_i, current_size_i );
    TestBufferInt( buffer_i, current_size_i );

    if ( !ExpandBufferZeroFillExpandedInt( &buffer_i,
                                           &current_size_i,
                                           1024 ) )
    {
        printf("ERROR: ExpandBufferZeroFillExpandedInt\n");
        free( buffer_i );
        exit(EXIT_FAILURE);
    }

    TestBufferInt( buffer_i, current_size_i );

    free( buffer_i );

    /************************************************************/

    exit(EXIT_SUCCESS);
}
