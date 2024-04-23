/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE trying to use optparse                                    *
 *                                                                   *
 * UNILICENSE                                                        *
 *                                                                   *
*********************************************************************/

#define OPTPARSE_IMPLEMENTATION
#define OPTPARSE_API static
#include "optparse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool g_example_flag = false;
int g_device_num;

/*********************************************************************
 * F NAME IsNumberPositiveAndNotNull();
 *
 *********************************************************************/

bool IsNumberPositiveAndNotNull( char *str, int *num )
{

    int num_tmp = 0;

    if ( str[0]=='-' ) return false;

    for ( int i=0; str[i] != 0; ++i )
    {
        if ( !isdigit(str[i])) return false;
    }

    num_tmp = atoi( str );

    if ( !num_tmp ) return false;

    *num = num_tmp;

    return true;
}

/*********************************************************************
 * F NAME PrintHelp();
 *
 *********************************************************************/

static void PrintHelp( void )
{

    #define LN(s) s "\n"

    printf( LN("usage: program [options]")
            LN("")
            LN("optional arguments:")
            LN("  -d, --devicenum=num       just example `num`, 1 or greater")
            LN("  -e, --example             another example")
            LN("  -i, --input=filename      input `filename`")
            LN("  -o, --output=filename     output `filename`")
            LN("  -h, --help                display help message and exit"));

    printf("\n");
}


/*********************************************************************
 * F NAME ParseOptions();
 *
 *********************************************************************/

bool ParseOptions( int argc, char **argv )
{

    if ( argc > 1 )
    {

        struct optparse options;

        static const struct optparse_long longopts[] = {
            {"help",        'h',    OPTPARSE_NONE},
            {"devicenum",   'd',    OPTPARSE_REQUIRED},
            {"example",     'e',    OPTPARSE_NONE},
            {"input",       'i',    OPTPARSE_REQUIRED},
            {"output",      'o',    OPTPARSE_REQUIRED},
            { 0, 0, 0 },
        };

        optparse_init(&options, argv);

        char *arg;
        int opt, longindex;

        while ((opt = optparse_long(&options, longopts, &longindex)) != -1)
        {
            switch (opt)
            {

                case 'i':

                    printf("INFO: (i) %s\n", options.optarg );

                    break;

                case 'o':

                    printf("INFO: (o) %s\n", options.optarg );

                    break;

                case 'd':

                    printf( "INFO: device number, optarg -> %s\n",
                            options.optarg );

                    int num = 0;

                    if ( IsNumberPositiveAndNotNull( options.optarg,
                                                     &num))
                    {
                        printf("INFO: device number is valid. %d\n", num );
                        g_device_num = num;
                    }
                    else
                    {
                        printf("ERROR: invalid device number, must be greater than 0\n");
                        return false;
                    }

                    break;

                case 'e':

                    g_example_flag = true;

                    break;

                case 'h':
                    PrintHelp();
                    exit(EXIT_SUCCESS);

                case '?':

                    printf("ERROR: %s: %s\n", argv[0], options.errmsg );

                    exit(EXIT_FAILURE);

            }

            printf("INFO: %c (%d, %d) = '%s'\n",
                    opt,
                    options.optind,
                    longindex,
                    options.optarg );

        }

        printf( "INFO: optind = %d\n", options.optind );

        while ( ( arg = optparse_arg( &options ) ) )
        {
            printf("INFO: argument: %s\n", arg );
        }
    }

    return true;
}

/*********************************************************************
 * F NAME main();
 *
 *********************************************************************/

int main( int argc, char **argv )
{

    if( !ParseOptions( argc, argv ) )
    {
        printf("ERROR: parse options failure.\n");
        exit(EXIT_FAILURE);
    }

    printf("Example flag: %s\n", g_example_flag ? "set" : "not set" );
    printf("Device number: %d\n", g_device_num );

    exit(EXIT_SUCCESS);
}
