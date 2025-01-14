#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}Point2Dbl;

typedef struct{
    double x;
    double y;
    double z;
}Point3Dbl;

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

Point3Dbl CentroidOfTriangle3D( Point3Dbl a,
                                Point3Dbl b,
                                Point3Dbl c )
{
    /*
    Point3Dbl ret;
    ret.x = (a.x + b.x + c.x) / 3.0;
    ret.y = (a.y + b.y + c.y) / 3.0;
    ret.z = (a.z + b.z + c.z) / 3.0;
    return ret;
    */

    return (Point3Dbl) { (a.x + b.x + c.x) / 3.0,
                         (a.y + b.y + c.y) / 3.0,
                         (a.z + b.z + c.z) / 3.0 };
}

int main()
{
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

    }

    /******************************************/

    {

    Point3Dbl p1, p2, p3, ret_v;

    p1.x = 1.0;
    p1.y = 1.0;
    p1.z = 0.0;

    p2.x = 2.0;
    p2.y = 5.0;
    p2.z = 1.0;

    p3.x = 3.0;
    p3.y = 1.0;
    p3.z = 0.0;

    ret_v = CentroidOfTriangle3D( p1, p2, p3 );

    printf("Test (3) p1: %f %f %f p2: %f %f %f p3: %f %f %f centroid: %f %f %f\n",
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z,
            p3.x, p3.y, p3.z,
            ret_v.x, ret_v.y, ret_v.z );

    p2.z = -1.0;

    ret_v = CentroidOfTriangle3D( p1, p2, p3 );

    printf("Test (4) p1: %f %f %f p2: %f %f %f p3: %f %f %f centroid: %f %f %f\n",
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z,
            p3.x, p3.y, p3.z,
            ret_v.x, ret_v.y, ret_v.z );

    }

    return 0;
}
