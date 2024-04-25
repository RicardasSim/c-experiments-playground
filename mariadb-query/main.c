/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *********************************************************************/

/*
 This example requires a running mysql server.
 A database must also be created.

 Create database
 ----------------

 mysql> CREATE DATABASE testdb CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
 mysql> USE testdb;

 Create tables

 mysql> CREATE TABLE exmpltbl ( id smallint unsigned not null auto_increment,
                                name varchar(20) not null,
                                primary key (id) );

 Insert some records
 --------------------

 mysql> INSERT INTO exmpltbl ( id, name ) VALUES ( null, 'Simon' );
 mysql> INSERT INTO exmpltbl ( id, name ) VALUES ( null, 'Veronica' );
 mysql> INSERT INTO exmpltbl ( id, name ) VALUES ( null, 'Valeria' );
 mysql> INSERT INTO exmpltbl ( id, name ) VALUES ( null, 'Robert' );
 mysql> INSERT INTO exmpltbl ( id, name ) VALUES ( null, 'Eglė' );

 Create user, grant privileges
 ------------------------------

 mysql> CREATE USER 'testuser'@'localhost' IDENTIFIED BY 'pass123';
 mysql> GRANT ALL PRIVILEGES ON testdb . * TO 'testuser'@'localhost';
 mysql> FLUSH PRIVILEGES;

 mysql> quit

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

#define DATA_BASE_HOST "localhost"
#define DATA_BASE_NAME "testdb"
#define USER_NAME "testuser"
#define USER_PASSWORD "pass123"

int main ()
{

    MYSQL mysql;
    MYSQL_RES *result;
    MYSQL_ROW row;
    unsigned int num_fields;
    unsigned int num_rows;

    if( !mysql_init( &mysql ) )
    {
        printf("Error initializing MySQL client\n");
        return 1;
    }

    mysql_options( &mysql, MYSQL_SET_CHARSET_NAME, "utf8mb4" );

    if ( !mysql_real_connect( &mysql,
                              DATA_BASE_HOST,
                              USER_NAME,
                              USER_PASSWORD,
                              DATA_BASE_NAME,
                              0,
                              NULL,
                              0 ) )
    {
        fprintf( stderr, "Failed to connect to database. Error: %s\n", mysql_error( &mysql ) );
        mysql_close( &mysql );
        mysql_library_end();
        return 1;
    }

    char test_str[]="a";

    // TODO: allocate memory with malloc
    char query_string[512], *p_end;

    p_end = stpcpy( query_string, "SELECT name FROM exmpltbl WHERE name LIKE '%" );
    p_end += mysql_real_escape_string( &mysql,
                                       p_end,
                                       test_str,
                                       strlen(test_str) );
    p_end = stpcpy( p_end, "%'" );

    if ( mysql_real_query( &mysql,query_string, (unsigned int) ( p_end - query_string ) ) )
    {
        fprintf( stderr, "Mysql query failed. ERROR: %s\n", mysql_error( &mysql ) );
        mysql_close( &mysql );
        mysql_library_end();
        return 1;
    }

    result = mysql_store_result( &mysql );

    if ( result )
    {
        num_fields = mysql_num_fields( result );
        printf("INFO: num of fields: %d\n", num_fields );

        num_rows = mysql_affected_rows( &mysql );
        printf("INFO: num of rows: %d\n", num_rows );

        while (( row = mysql_fetch_row( result ) ))
        {
            unsigned long *lengths;

            lengths = mysql_fetch_lengths( result );

            for( unsigned int i = 0; i < num_fields; i++ )
            {
                printf("[%.*s]", (int) lengths[i], row[i] ? row[i] : "NULL" );
            }

            printf("\n");
        }

        mysql_free_result( result );

    }
    else
    {
        if ( mysql_errno( &mysql ))
        {
            fprintf( stderr, "Error: %s\n", mysql_error( &mysql ) );
            mysql_close( &mysql );
            mysql_library_end();
            return 1;
        }
        else if ( mysql_field_count( &mysql ) == 0 )
        {
            printf("query does not return data (it was not a SELECT)\n");

            num_rows = mysql_affected_rows( &mysql );
            printf("num_rows: %d\n", num_rows );
        }
    }


    mysql_close( &mysql );

    mysql_library_end();

    return 0;
}
