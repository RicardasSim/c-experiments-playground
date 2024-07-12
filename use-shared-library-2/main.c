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

    void *(*pfnTestInit)();
    void (*pfnTestClean)( void* );
    void (*pfnTestProc)();

    library_handle = dlopen ( "./libTestprogShared.so", RTLD_LAZY );

    if ( !library_handle )
    {
        printf ( "ERROR: %s", dlerror() );
        exit(1);
    }

    *(void **)(&pfnTestInit) = dlsym( library_handle, "TestInit" );

    error = dlerror();

    if ( error != NULL )
    {
        printf( "ERROR: %s\n", error );
        CloseLibrary( library_handle );;
        exit(EXIT_FAILURE);
    }

    *(void **)(&pfnTestClean) = dlsym( library_handle, "TestClean" );

    error = dlerror();

    if ( error != NULL )
    {
        printf( "ERROR: %s\n", error );
        CloseLibrary( library_handle );
        exit(EXIT_FAILURE);
    }

    *(void **)(&pfnTestProc) = dlsym( library_handle, "TestProc" );

    error = dlerror();

    if ( error != NULL )
    {
        printf( "ERROR: %s\n", error );
        CloseLibrary( library_handle );
        exit(EXIT_FAILURE);
    }

/*********************************************************************/

    typedef void (*pfnClean)( void* );
    typedef void (*pfnProc)();

    typedef struct obj{
        void *p_s;
        pfnClean Clean;
        pfnProc Proc;
    }Obj;

    Obj obj[2];

    obj[0].Clean = pfnTestClean;
    obj[0].Proc = pfnTestProc;

    obj[1].Clean = pfnTestClean;
    obj[1].Proc = pfnTestProc;

    obj[0].p_s = (*pfnTestInit)();

    if ( !obj[0].p_s )
    {
        printf("Error: TestInit (0)\n");
    }
    else
    {
        printf("Info: TestInit (0) OK\n");

        (obj[0].Proc)();

        //(*pfnTestClean)( obj[0].p_s );
        (obj[0].Clean)( obj[0].p_s );

    }

    putchar('\n');

    obj[1].p_s = (*pfnTestInit)();

    if ( !obj[1].p_s )
    {
        printf("Error: TestInit (1)\n");
    }
    else
    {
        printf("Info: TestInit (1) OK\n");

        (obj[1].Proc)();

        (obj[1].Clean)( obj[1].p_s );

    }

    putchar('\n');

/*********************************************************************/

    CloseLibrary(library_handle);

    exit(EXIT_SUCCESS);
}
