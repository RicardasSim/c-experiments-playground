#include <stdio.h>
#include <stdlib.h>
#include <csv.h>

typedef struct s_counter {
  long unsigned fields;
  long unsigned rows;
} S_counter;

// callback function that handle end-of-field events

void CallBack1( void *p_s, size_t len, void *data )
{
    printf("%.*s ", (int)len, (char *)p_s );

    ((S_counter *) data)->fields++;
}

// callback function that handle end-of-row events

void CallBack2( int c, void *data )
{
    /* Silence compiler warning for unused parameters */
    (void)c;

    //printf("%d\n", c);

    putchar('\n');

    ((S_counter *) data)->rows++;
}

int main()
{

    FILE *fp;
    struct csv_parser prsr;
    unsigned char options = 0;
    S_counter cntr = {0,0};
    char buf[1024];
    size_t rsz;

    if ( csv_init( &prsr, options ) != 0 )
    {
        printf( "ERROR: failed to initialize csv parser.\n");
        exit( EXIT_FAILURE );
    }

    const char file_name[] = "test_file.csv";

    fp = fopen( file_name, "rb");

    if ( !fp )
    {
        printf("ERROR: failed to open file %s\n", file_name );
        csv_free( &prsr );
        exit( EXIT_FAILURE );
    }

    while ( ( rsz = fread( buf, 1, 1024, fp ) ) > 0 )
    {
        if ( csv_parse( &prsr,
                        buf,
                        rsz,
                        CallBack1,
                        CallBack2,
                        &cntr ) != rsz )
        {
            printf("ERROR: error while parsing file %s\n", csv_strerror( csv_error(&prsr) ));
        }
    }

    csv_fini( &prsr, CallBack1, CallBack2, &cntr );

    fclose( fp );

    printf("INFO: num of fields: %lu , num of rows: %lu\n", cntr.fields, cntr.rows );

    csv_free( &prsr );

    exit( EXIT_SUCCESS );
}
