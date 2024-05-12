/*********************************************************************
 * FILE NAME                                                         *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *********************************************************************/

/*
    Formulas taken from:
    Line-line intersection - Wikipedia
    http://en.wikipedia.org/wiki/Line-line_intersection
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

typedef struct {

    double x;
    double y;

} Point2D;

typedef struct {

    Point2D a;
    Point2D b;

} Line;

/*********************************************************************
 * F NAME WhereTheLinesIntersect
 *
 * Given two points through which a line passes: l_1, l_2
 *
 * p_ipnt Intersection point
 *
 *********************************************************************/

bool WhereTheLinesIntersect( Line l_1, Line l_2, Point2D *p_ipnt )
{

    double x12 = l_1.a.x - l_1.b.x;
    double x34 = l_2.a.x - l_2.b.x;
    double y12 = l_1.a.y - l_1.b.y;
    double y34 = l_2.a.y - l_2.b.y;

    double c = x12 * y34 - y12 * x34;

    if ( fabs(c) < DBL_EPSILON )
    {
        // No intersection
        return false;
    }

    // Intersection
    double a = l_1.a.x * l_1.b.y - l_1.a.y * l_1.b.x;
    double b = l_2.a.x * l_2.b.y - l_2.a.y * l_2.b.x;

    double x = (a * x34 - b * x12) / c;
    double y = (a * y34 - b * y12) / c;

    p_ipnt->x = x;
    p_ipnt->y = y;

    return true;
}

/*********************************************************************
 * F NAME main
 *
 *********************************************************************/

int main()
{

    Point2D ret_ipnt;
    bool ret_val;

    /************************************************************/

    printf("(1)\n");

    Line line_1 = { { 0.0, 0.0 }, { 1.0, 0.0 } };
    Line line_2 = { { 0.5, 1.0 }, { 0.5, 0.0 } };

    printf("Line 1: x1: %f y1: %f x2: %f y2: %f\n",
            line_1.a.x, line_1.a.y, line_1.b.x, line_1.b.y );

    printf("Line 2: x1: %f y1: %f x2: %f y2: %f\n",
            line_2.a.x, line_2.a.y, line_2.b.x, line_2.b.y );

    ret_val = WhereTheLinesIntersect( line_1, line_2, &ret_ipnt );

    if ( ret_val )
    {
        printf("The lines intersect: %f %f\n", ret_ipnt.x, ret_ipnt.y );
    }
    else
    {
        printf( "The lines do not intersect.\n" );
    }

    /************************************************************/

    printf("(2)\n");

    line_1.a.x = -1.0;
    line_1.a.y = -1.0;
    line_1.b.x = 1.0;
    line_1.b.y = 1.0;

    line_2.a.x = -1.0;
    line_2.a.y = -2.0;
    line_2.b.x = 0.0;
    line_2.b.y = 1.0;

    printf("Line 1: x1: %f y1: %f x2: %f y2: %f\n",
            line_1.a.x, line_1.a.y, line_1.b.x, line_1.b.y );

    printf("Line 2: x1: %f y1: %f x2: %f y2: %f\n",
            line_2.a.x, line_2.a.y, line_2.b.x, line_2.b.y );

    ret_val = WhereTheLinesIntersect( line_1, line_2, &ret_ipnt );

    if ( ret_val )
    {
        printf("The lines intersect: %f %f\n", ret_ipnt.x, ret_ipnt.y );
    }
    else
    {
        printf( "The lines do not intersect.\n" );
    }

    return 0;
}
