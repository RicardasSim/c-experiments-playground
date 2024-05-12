/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *********************************************************************/

/*
    This example requires a running PostgreSQL server.
    Server configured as:

    pg_hba.conf

    from

    #   TYPE  DATABASE USER ADDRESS METHOD
        local all      all          peer

    to

    #   TYPE  DATABASE USER ADDRESS METHOD
        local all      all          md5


    A database must also be created.

    Linux
    ----------

    sudo -u postgres psql

    postgres=# create database test_db;
    postgres=# create user test_user with encrypted password 'password123';
    postgres=# grant all privileges on database test_db to test_user;

    postgres=# quit

    As test_user

    psql --username=test_user test_db

    test_db=> CREATE TABLE test_table( id SERIAL PRIMARY KEY, fld1 VARCHAR(64), fld2 VARCHAR(64) );

    test_db=> INSERT INTO test_table ( fld1, fld2 ) VALUES ( 'Bumblebee', 'Bombus' );
    test_db=> INSERT INTO test_table ( fld1, fld2 ) VALUES ( 'Bee', 'Anthophila' );

    test_db=> quit

*/

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main()
{
    PGconn *conn;
    PGresult *res;

    // Establish a connection to the database
    conn = PQconnectdb( "dbname=test_db user=test_user password=password123" );

    if ( PQstatus(conn) != CONNECTION_OK )
    {
        fprintf( stderr, "Connection to database failed: %s\n", PQerrorMessage( conn ) );
        PQfinish( conn );
        exit(EXIT_FAILURE);
    }

    // Execute a query
    res = PQexec( conn, "SELECT * FROM test_table" );

    if ( PQresultStatus( res ) != PGRES_TUPLES_OK )
    {
        fprintf( stderr, "Query execution failed: %s\n", PQerrorMessage( conn ) );
        PQclear( res );
        PQfinish( conn );
        exit(EXIT_FAILURE);
    }

    // Print the result

    int num_rows = PQntuples(res);
    int num_cols = PQnfields(res);

    printf("Number of rows: %d\n", num_rows );
    printf("Number of columns: %d\n", num_cols );

    for ( int i = 0; i < num_cols; ++i )
    {
        printf("%s  ", PQfname( res, i ) );
    }

    putchar('\n');

    for ( int i = 0; i < num_rows; ++i )
    {
        for (int j = 0; j < num_cols; ++j )
        {
            printf("%s  ", PQgetvalue( res, i, j ) );
        }

        putchar('\n');
    }

    // Clean up
    PQclear(res);
    PQfinish(conn);

    exit(EXIT_SUCCESS);
}
