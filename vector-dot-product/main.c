/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
    double z;
} Vec3Dbl;

typedef struct{
    float x;
    float y;
    float z;
} Vec3Flt;


float DotProductVec3F( Vec3Flt a, Vec3Flt b )
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


int main()
{

    float ret_val;

    Vec3Flt test_vec_1 = { 1.0, 0.0, 0.0 };
    Vec3Flt test_vec_2 = { 0.0, 1.0, 1.0 };
    Vec3Flt test_vec_3 = { 1.0, 1.0, 1.0 };

    /**************************************************************/

    puts("(1)\n");

    ret_val = DotProductVec3F( test_vec_1, test_vec_2 );

    printf("vec1: x: %f y: %f z: %f\n", test_vec_1.x, test_vec_1.y, test_vec_1.z );
    printf("vec2: x: %f y: %f z: %f\n", test_vec_2.x, test_vec_2.y, test_vec_2.z );
    printf("Dot Product: %f\n", ret_val );

    putchar('\n');

    /**************************************************************/

    puts("(2)\n");

    ret_val = DotProductVec3F( test_vec_1, test_vec_3 );

    printf("vec1: x: %f y: %f z: %f\n", test_vec_1.x, test_vec_1.y, test_vec_1.z );
    printf("vec2: x: %f y: %f z: %f\n", test_vec_3.x, test_vec_3.y, test_vec_3.z );
    printf("Dot Product: %f\n", ret_val );

    putchar('\n');

    /**************************************************************/

    puts("(3)\n");

    ret_val = DotProductVec3F( test_vec_2, test_vec_3 );

    printf("vec1: x: %f y: %f z: %f\n", test_vec_2.x, test_vec_2.y, test_vec_2.z );
    printf("vec2: x: %f y: %f z: %f\n", test_vec_3.x, test_vec_3.y, test_vec_3.z );
    printf("Dot Product: %f\n", ret_val );

    putchar('\n');

    /**************************************************************/

    puts("(4)\n");

    float a[3] = { 1.0, 0.0, 1.0 };
    float b[3] = { 0.0, 1.0, 1.0 };

    float product = 0.0f;

    for ( unsigned int i = 0; i < 3; ++i )
    {
        product += a[i] * b[i];
    }

    printf("vec a: x: %f y: %f z: %f\n", a[0], a[1], a[2] );
    printf("vec b: x: %f y: %f z: %f\n", b[0], b[1], b[2] );
    printf("Dot Product: %f\n", product );

    putchar('\n');

    return 0;
}
