#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}Point2Dbl;

/*
Shoelace formula:
0.5f * ((x1 * y2) + (x2 * y3) + (x3 * y1) - (x1 * y3) - (x2 * y1) - (x3 * y2))
*/

double AreaOfTriangleSF( Point2Dbl a,
                         Point2Dbl b,
                         Point2Dbl c )
{
    // Calculate the area using the Shoelace formula
    return fabs( 0.5 * ( ( a.x * b.y ) +
                         ( b.x * c.y ) +
                         ( c.x * a.y ) -
                         ( a.x * c.y ) -
                         ( b.x * a.y ) -
                         ( c.x * b.y ) ) );
}

double AreaOfTriangleV1( Point2Dbl a,
                         Point2Dbl b,
                         Point2Dbl c )
{

    return fabs( ( a.x * ( b.y - c.y ) +
                   b.x * ( c.y - a.y ) +
                   c.x * ( a.y - b.y ) ) * 0.5 );

}


int main()
{

    Point2Dbl p1, p2, p3;

    p1.x = 0.0;
    p1.y = 0.0;

    p2.x = 10.0;
    p2.y = 0.0;

    p3.x = 10.0;
    p3.y = 10.0;

    printf("Test (1) p1: %f %f p2: %f %f p3: %f %f area: %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
            AreaOfTriangleV1( p1, p2, p3 ) );

    printf("Test (2) p1: %f %f p2: %f %f p3: %f %f area: %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
            AreaOfTriangleSF( p1, p2, p3 ) );

    p2.x = -10.0;
    p2.y = 0.0;

    printf("Test (3) p1: %f %f p2: %f %f p3: %f %f area: %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
            AreaOfTriangleV1( p1, p2, p3 ) );

    printf("Test (4) p1: %f %f p2: %f %f p3: %f %f area: %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
            AreaOfTriangleSF( p1, p2, p3 ) );

    p3.x = -10.0;
    p3.y = -10.0;

    printf("Test (5) p1: %f %f p2: %f %f p3: %f %f area: %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
            AreaOfTriangleV1( p1, p2, p3 ) );

    printf("Test (6) p1: %f %f p2: %f %f p3: %f %f area: %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
            AreaOfTriangleSF( p1, p2, p3 ) );

    return 0;
}
