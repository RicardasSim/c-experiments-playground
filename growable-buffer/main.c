#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INITIAL_CAPACITY 4
#define CHUNK_SIZE 4

typedef struct
{
    char *p_buffer;
    size_t size;
    size_t capacity;
} StBuff;

StBuff sb;

bool InitBuffer( StBuff *p_sb )
{
    char *p_tmp;

    //p_tmp = malloc( INITIAL_CAPACITY * sizeof *p_tmp );
    p_tmp = calloc( INITIAL_CAPACITY, sizeof *p_tmp );

    if ( !p_tmp )
    {
        printf("Error: cannot allocate memory\n");
        return false;
    }

    p_sb->p_buffer = p_tmp;
    p_sb->capacity = INITIAL_CAPACITY;
    p_sb->size = 0;

    return true;
}

bool GrowBuffer( StBuff *p_sb, size_t size_to_grow )
{
    char *p_tmp;
    size_t new_capacity = p_sb->capacity + size_to_grow;

    p_tmp = realloc ( p_sb->p_buffer,
                      new_capacity * sizeof *p_tmp );

    if ( !p_tmp )
    {
        printf("Error: cannot reallocate memory buffer\n");
        return false;
    }

    p_sb->p_buffer = p_tmp;

    // zero out the newly allocated part
    memset( p_sb->p_buffer + p_sb->capacity * sizeof *p_sb->p_buffer,
            0,
            new_capacity - p_sb->capacity * sizeof *p_sb->p_buffer );

    p_sb->capacity = new_capacity;

    printf("Info: GrowBuffer: by %zu OK\n", size_to_grow );

    return true;
}

bool AddCharToBuffer ( StBuff *p_sb, char c )
{
    size_t new_size = p_sb->size + 1;

    if ( new_size > p_sb->capacity )
    {
        if ( !GrowBuffer( p_sb, CHUNK_SIZE ) )
        {
            printf("Error: cannot add char to buffer\n");
            return false;
        }
    }

    p_sb->p_buffer[p_sb->size] = c;
    p_sb->size = new_size;

    return true;
}

bool AddStrToBuffer ( StBuff *p_sb, const char *p_str )
{

    size_t len = strlen( p_str );
    size_t new_size = p_sb->size + len;

    // align the size to the next chunk boundary
    size_t grow_size = (len + CHUNK_SIZE - 1) & ~(CHUNK_SIZE - 1);

    if ( new_size > p_sb->capacity )
    {
        if ( !GrowBuffer( p_sb, grow_size ) )
        {
            printf("Error: cannot add str to buffer\n");
            return false;
        }
    }

    // without null terminating char
    memcpy( p_sb->p_buffer + p_sb->size ,p_str , len );

    p_sb->size = new_size;

    return true;
}

void FreeBuffer( StBuff *p_sb )
{
    free( p_sb->p_buffer );
    p_sb->p_buffer = NULL;
}

void Print( char *p, size_t size )
{
    for ( size_t i = 0; i < size; ++i )
    {
        putchar( p[i] );
    }

    putchar('\n');
}

int main()
{

    if ( !InitBuffer( &sb ) )
    {
        printf("Error: buffer initialization failed\n");
        exit(EXIT_FAILURE);
    }

    if (!AddCharToBuffer ( &sb, 'A' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'B' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'C' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }

    Print( sb.p_buffer, sb.size );

    if (!AddCharToBuffer ( &sb, 'D' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'E' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'F' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }

    Print( sb.p_buffer, sb.size );

    if (!AddStrToBuffer ( &sb, "123" )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'G' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'H' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'I' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }

    Print( sb.p_buffer, sb.size );

    if (!AddStrToBuffer ( &sb, "456_789" )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'J' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'K' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddCharToBuffer ( &sb, 'L' )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }
    if (!AddStrToBuffer ( &sb, "10_11_12" )){ FreeBuffer( &sb ); exit(EXIT_FAILURE); }

    Print( sb.p_buffer, sb.size );

    FreeBuffer( &sb );

    exit(EXIT_SUCCESS);
}
