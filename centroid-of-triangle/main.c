#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}Point2Dbl;

Point2Dbl CentroidOfTriangle( Point2Dbl a,
                              Point2Dbl b,
                              Point2Dbl c )
{
    //Point2Dbl ret;
    //ret.x = (a.x + b.x + c.x) / 3.0;
    //ret.y = (a.y + b.y + c.y) / 3.0;
    //return ret;

    return (Point2Dbl) { (a.x + b.x + c.x) / 3.0,
                         (a.y + b.y + c.y) / 3.0 };
}

int main()
{

    Point2Dbl p1, p2, p3, ret_v;

    p1.x = 0.0;
    p1.y = 0.0;

    p2.x = 1.0;
    p2.y = 3.0;

    p3.x = 2.0;
    p3.y = 0.0;

    ret_v = CentroidOfTriangle( p1, p2, p3 );

    printf("Test (1) p1: %f %f p2: %f %f p3: %f %f centroid: %f %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, ret_v.x, ret_v.y );

    p2.x = 1.0;
    p2.y = -3.0;

    ret_v = CentroidOfTriangle( p1, p2, p3 );

    printf("Test (2) p1: %f %f p2: %f %f p3: %f %f centroid: %f %f\n",
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, ret_v.x, ret_v.y );

    return 0;
}
