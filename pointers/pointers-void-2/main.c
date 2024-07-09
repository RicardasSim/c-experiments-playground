#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct st
{
    char c;
    int i;
    float f;
} St;

enum prc
{
    PR_INC_C = 1,
    PR_INC_I = 2,
    PR_ADD_1_F = 3
};

void *ObjInit()
{
    St *p_s = calloc( 1, sizeof(St) );

    if ( !p_s )
    {
        return NULL;
    }

    return p_s;
}

bool ObjClean( void *p )
{

    free( p );

    return true;
}

bool ObjGet( void *p, char *var_name, void *p_val )
{

    if ( !strcmp( var_name, "varc" ) )
    {
         *(char*) p_val = ((St*)p)->c;
    }
    else if ( !strcmp( var_name, "vari" ) )
    {
        *(int*) p_val = ((St*)p)->i;
    }
    else if ( !strcmp( var_name, "varf" ) )
    {
        *(float*) p_val = ((St*)p)->f;
    }
    else
    {
        return false;
    }

    return true;
}

bool ObjSet( void *p, char *var_name, void *p_val )
{

    if ( !strcmp( var_name, "varc" ) )
    {
        ((St*)p)->c = *(char*) p_val;
    }
    else if ( !strcmp( var_name, "vari" ) )
    {
        ((St*)p)->i = *(int*) p_val;
    }
    else if ( !strcmp( var_name, "varf" ) )
    {
        ((St*)p)->f = *(float*) p_val;
    }
    else
    {
        return false;
    }

    return true;
}

bool ObjProc( void *p, int proc )
{

    switch ( proc )
    {
        case PR_INC_C:

            ((St*)p)->c++;

        break;

        case PR_INC_I:

            ((St*)p)->i++;

        break;

        case PR_ADD_1_F:

            ((St*)p)->f += 1.0f;

        break;

    default:

        return false;

        //break;
    }

    return true;
}

int main()
{

    void *p_obj[2] = {NULL};
    unsigned int obj_num = 2;

    for ( unsigned int i = 0; i < obj_num; ++i )
    {
        p_obj[i] = ObjInit();

        if ( !p_obj[i] )
        {
            printf("Error: cannot initialize obj (%d).\n", i );

            for ( unsigned int j = i; j > 0; --j )
            {
                ObjClean( p_obj[ j - 1 ] );
            }

            return 1;
        }
    }

    //******************************

    char v_c = 'a';
    int v_i = 1;
    float v_f = 10.0f;

    ObjSet( p_obj[0], "varc", &v_c );
    ObjSet( p_obj[0], "vari", &v_i );
    ObjSet( p_obj[0], "varf", &v_f );

    v_c = 'b';
    v_i = 2;
    v_f = 20.0f;

    ObjSet( p_obj[1], "varc", &v_c );
    ObjSet( p_obj[1], "vari", &v_i );
    ObjSet( p_obj[1], "varf", &v_f );

    //******************************

    char test_a;
    int test_i;
    float test_f;

    ObjGet( p_obj[0], "varc", &test_a );
    ObjGet( p_obj[0], "vari", &test_i );
    ObjGet( p_obj[0], "varf", &test_f );

    printf("(1) %c %i %f\n", test_a, test_i, test_f );

    ObjGet( p_obj[1], "varc", &test_a );
    ObjGet( p_obj[1], "vari", &test_i );
    ObjGet( p_obj[1], "varf", &test_f );

    printf("(2) %c %i %f\n", test_a, test_i, test_f );

    //******************************

    ObjProc( p_obj[0], PR_ADD_1_F );
    ObjProc( p_obj[1], PR_INC_C );

    //******************************

    ObjGet( p_obj[0], "varc", &test_a );
    ObjGet( p_obj[0], "vari", &test_i );
    ObjGet( p_obj[0], "varf", &test_f );

    printf("(1) %c %i %f\n", test_a, test_i, test_f );

    ObjGet( p_obj[1], "varc", &test_a );
    ObjGet( p_obj[1], "vari", &test_i );
    ObjGet( p_obj[1], "varf", &test_f );

    printf("(2) %c %i %f\n", test_a, test_i, test_f );

    //******************************

    for ( unsigned int i = 0; i < obj_num; ++i )
    {
        ObjClean( p_obj[i] );
    }


    return 0;
}
