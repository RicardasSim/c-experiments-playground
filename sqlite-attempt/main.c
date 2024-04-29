#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sqlite3.h>

bool CreateTable( sqlite3 *db )
{
    char *error_msg = NULL;
    int rc;
    char *sql;

    //CREATE TABLE IF NOT EXISTS TABLE_FOR_TESTING
    sql = "CREATE TABLE TABLE_FOR_TESTING(" \
          "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
          "FLD1 TEXT NOT NULL," \
          "FLD2 CHAR(64)," \
          "QTY1 REAL );";

    rc = sqlite3_exec( db, sql, NULL, 0, &error_msg );

    if( rc != SQLITE_OK )
    {
        printf( "SQL error: %s\n", error_msg );
        sqlite3_free( error_msg );
        return false;
    }

    return true;
}

bool CreateRecords( sqlite3 *db )
{

    char *error_msg = NULL;
    int rc;
    char *sql;

    sql = "INSERT INTO TABLE_FOR_TESTING (FLD1,FLD2,QTY1) " \
          "VALUES ('L1', 'Flour', 2.00 ); " \
          "INSERT INTO TABLE_FOR_TESTING (FLD1,FLD2,QTY1) " \
          "VALUES ('L1', 'Salt', 0.5 ); " \
          "INSERT INTO TABLE_FOR_TESTING (FLD1,FLD2,QTY1) " \
          "VALUES ('L1', 'Milk', 1.5 ); " \
          "INSERT INTO TABLE_FOR_TESTING (FLD1,FLD2,QTY1) " \
          "VALUES ('L2', 'Butter', 0.75 ); " \
          "INSERT INTO TABLE_FOR_TESTING (FLD1,FLD2,QTY1) " \
          "VALUES ('L2', 'Sugar', 1.0 );";

    rc = sqlite3_exec( db, sql, NULL, 0, &error_msg );

    if( rc != SQLITE_OK )
    {
        printf( "SQL error: %s\n", error_msg );
        sqlite3_free( error_msg );
        return false;
    }

    return true;
}

/*
static int Callback( void *not_used,
                     int argc,
                     char **argv,
                     char **col_name )
{*/
    /* Silence compiler warning for unused parameters: not_used */
/*    (void)not_used;


    int i;

    for(i = 0; i<argc; i++)
    {
        printf( "%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL" );
    }

    printf("\n");

    return 0;
}
*/

static int Callback( void *data,
                     int argc,
                     char **argv,
                     char **col_name )
{
    int i;

    printf( "%s\n", (const char*)data );

    for( i = 0; i < argc; i++ )
    {
        printf( "%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL" );
    }

    printf("\n");

    return 0;
}

bool SelectTest1( sqlite3 *db )
{
    char *error_msg = NULL;
    int rc;
    char *sql;

    sql = "SELECT * from TABLE_FOR_TESTING WHERE FLD1 ='L1'";

    const char* data = "Data to Callback.";

    rc = sqlite3_exec( db, sql, Callback, (void*)data, &error_msg );

    if( rc != SQLITE_OK )
    {
        printf("SQL error: %s\n", error_msg );
        sqlite3_free( error_msg );
        return false;
    }

    return true;
}

bool SelectTest2( sqlite3 *db )
{

    sqlite3_stmt *stmt;
    int rc;
    char *sql;

    sql = "SELECT * from TABLE_FOR_TESTING WHERE FLD1 ='L1'";

    rc = sqlite3_prepare_v2( db, sql, -1, &stmt, NULL );

    if ( rc != SQLITE_OK )
    {
        printf( "SQL error: %s\n", sqlite3_errmsg( db ) );
        return false;;
    }

    while (( rc = sqlite3_step( stmt )) == SQLITE_ROW )
    {
        int id = sqlite3_column_int ( stmt, 0 );
        char *fld_1 = (char *) sqlite3_column_text( stmt, 1 );
        char *fld_2 = (char *) sqlite3_column_text( stmt, 2 );
        double qty_1 = sqlite3_column_double ( stmt, 3 );

        printf( "id: %d fld_1: %s fld_2: %s qty_1: %f\n",
                id, fld_1, fld_2, qty_1 );
    }

    if ( rc != SQLITE_DONE )
    {
        printf( "SQL error: %s\n", sqlite3_errmsg( db ) );
    }

    sqlite3_finalize( stmt );

    return true;
}

// TODO: + SELECT

bool UpdateTest( sqlite3 *db )
{
    char *error_msg = NULL;
    int rc;
    char *sql;

    sql = "UPDATE TABLE_FOR_TESTING set QTY1 = 10.00 where FLD2='Flour';";

    rc = sqlite3_exec( db, sql, NULL, 0, &error_msg );

    if( rc != SQLITE_OK )
    {
        printf( "SQL error: %s\n", error_msg );
        sqlite3_free( error_msg );
        return false;
    }

    return true;
}

// TODO: + SELECT

bool DeleteTest( sqlite3 *db )
{
    char *error_msg = NULL;
    int rc;
    char *sql;

    sql = "DELETE from TABLE_FOR_TESTING where ID=1;";

    rc = sqlite3_exec( db, sql, NULL, 0, &error_msg );

    if( rc != SQLITE_OK )
    {
        printf( "SQL error: %s\n", error_msg );
        sqlite3_free( error_msg );
        return false;
    }

    return true;
}

bool DropTableTest( sqlite3 *db )
{
    char *error_msg = NULL;
    int rc;
    char *sql;

    sql = "DROP TABLE TABLE_FOR_TESTING";

    rc = sqlite3_exec( db, sql, NULL, 0, &error_msg );

    if( rc != SQLITE_OK )
    {
        printf( "SQL error: %s\n", error_msg );
        sqlite3_free( error_msg );
        return false;
    }

    return true;
}

int main()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open( "for_testing_can_be_deleted.db", &db );

    if( rc )
    {
        printf( "Canot open database: %s\n", sqlite3_errmsg( db ) );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: database opened successfully.\n" );

    if ( !CreateTable( db ) )
    {
        printf("ERROR: CreateTables failed.\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: table created successfully.\n");


    if ( !CreateRecords( db ) )
    {
        printf("ERROR: CreateRecords failed.\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: records created successfully.\n" );

    if ( !SelectTest1( db ) )
    {
        printf("ERROR: SelectTest1 failed.\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: Select 1 - done successfully.\n" );

    if ( !UpdateTest( db ) )
    {
        printf("ERROR: UpdateTest failed.\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf("INFO: Update - done successfully\n");

    if ( !SelectTest2( db ) )
    {
        printf("ERROR: SelectTest2 failed (1).\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: Select 2 - done successfully.\n" );

    if ( !DeleteTest( db ) )
    {
        printf("ERROR: DeleteTest failed.\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: Delete - done successfully.\n" );

    if ( !SelectTest2( db ) )
    {
        printf("ERROR: SelectTest2 failed (2).\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: Select 2 - done successfully.\n" );

    if ( !DropTableTest( db ) )
    {
        printf("ERROR: DropTableTest failed.\n");
        sqlite3_close( db );
        exit( EXIT_FAILURE );
    }

    printf( "INFO: Drop Table - done successfully.\n" );

    sqlite3_close( db );

    exit( EXIT_SUCCESS );
}
