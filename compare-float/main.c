#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

bool IsFltAEqual1( float a,
                   float b,
                   float epsilon )
{
    return fabs( a - b ) < epsilon;
}

bool IsFltAEqual2( float a,
                   float b,
                   unsigned int precision )
{

    int i_a, i_b;

    if ( a > 0 )
    {
        i_a = (int)( a * precision + .5f );
    }
    else
    {
        i_a = (int)( a * precision - .5f );
    }

    if ( b > 0 )
    {
        i_b = (int)( b * precision + .5f );
    }
    else
    {
        i_b = (int)( b * precision - .5f );
    }

    return ( i_a == i_b );
}

int main()
{
    if( IsFltAEqual1( 0.123f, 0.123f, FLT_EPSILON ) )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }

    if( IsFltAEqual1( 0.1231f, 0.123f, FLT_EPSILON ) )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }

    if( IsFltAEqual2( 0.321f, 0.321f, 100000 ) )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }

    if( IsFltAEqual2( 0.3211f, 0.321f, 100000 ) )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }

    return 0;
}
