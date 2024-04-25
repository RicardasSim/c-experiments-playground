#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;

    char file_name[] = "this_file_can_be_deleted.txt";

    fp = fopen( file_name, "r" );

    if ( fp )
    {
        printf("WARNING: file \"%s\" already exists ! Overwrite it ? [Y/N]\n", file_name );

        char c = toupper( getchar() );

        if ( c != 'Y' )
        {
            printf("Not overwriting.\n");
            fclose( fp );
            return 0;
        }

        fclose( fp );

    }

    fp = fopen( file_name, "w" );

    if ( !fp )
    {
        printf("ERROR: cannot open file \"%s\" for writing !\n", file_name );
        return 1;
    }

    fprintf( fp,"%s\n", "This file is for testing." );

    fclose(fp);

    printf("INFO: a file \"%s\" has been written/overwritten.\n", file_name );

    return 0;
}
