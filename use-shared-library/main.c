/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *                                                                   *
 *                                                                   *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

/*********************************************************************
 * F NAME CloseLibrary();
 *
 *********************************************************************/

bool CloseLibrary( void *library_handle )
{
    if ( dlclose( library_handle ) )
    {
        printf("ERROR: %s\n", dlerror() );
        return false;
    }

    return true;
}

/*********************************************************************
 * F NAME main();
 *
 *********************************************************************/

int main()
{
    void *library_handle;
    char *error;

    void (*pfn_TestProgSh1)( char * );
    int (*pfn_TestProgSum1)( int, int );
    void (*pfn_TestProgSum2)( int, int, int * );

    library_handle = dlopen ( "./libTestprogShared.so", RTLD_LAZY );

    if ( !library_handle )
    {
        printf ( "ERROR: %s", dlerror() );
        exit(1);
    }

    *(void **)(&pfn_TestProgSh1) = dlsym( library_handle, "TestProgSh1" );

    error = dlerror();

    if ( error != NULL )
    {
        printf( "ERROR: %s\n", error );
        CloseLibrary( library_handle );;
        exit(EXIT_FAILURE);
    }

    *(void **)(&pfn_TestProgSum1) = dlsym( library_handle, "TestProgSum1" );

    error = dlerror();

    if ( error != NULL )
    {
        printf( "ERROR: %s\n", error );
        CloseLibrary( library_handle );
        exit(EXIT_FAILURE);
    }

    *(void **)(&pfn_TestProgSum2) = dlsym( library_handle, "TestProgSum2" );

    error = dlerror();

    if ( error != NULL )
    {
        printf( "ERROR: %s\n", error );
        CloseLibrary( library_handle );
        exit(EXIT_FAILURE);
    }

/*********************************************************************/

    (*pfn_TestProgSh1)( "String from main.c" );

    int a = 1;
    int b = 2;
    int result;

    result = (*pfn_TestProgSum1)( a, b );

    printf("Result (1): %d\n", result );

    a = 4;
    b = 5;

    (*pfn_TestProgSum2)( a, b, &result );

    printf("Result (2): %d\n", result );

/*********************************************************************/

    CloseLibrary(library_handle);

    exit(EXIT_SUCCESS);
}
