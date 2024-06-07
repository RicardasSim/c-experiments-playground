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


Vec3Flt CrossProductVec3F( Vec3Flt a, Vec3Flt b )
{

    Vec3Flt vec_ret = { a.y * b.z - a.z * b.y,
                        a.z * b.x - a.x * b.z,
                        a.x * b.y - a.y * b.x };

    return vec_ret;
}


int main()
{

    Vec3Flt test_vec_ret;

    Vec3Flt test_vec_1 = { 1.0, 0.0, 0.0 };
    Vec3Flt test_vec_2 = { 0.0, 1.0, 0.0 };
    Vec3Flt test_vec_3 = { 1.0, 1.0, 1.0 };

    /**************************************************************/

    puts("(1)\n");

    test_vec_ret = CrossProductVec3F( test_vec_1, test_vec_2 );

    printf("vec1:   x: %f y: %f z: %f\n", test_vec_1.x, test_vec_1.y, test_vec_1.z );
    printf("vec2:   x: %f y: %f z: %f\n", test_vec_2.x, test_vec_2.y, test_vec_2.z );
    printf("result: x: %f y: %f z: %f\n", test_vec_ret.x, test_vec_ret.y, test_vec_ret.z );

    putchar('\n');

    /**************************************************************/

    puts("(2)\n");

    test_vec_ret = CrossProductVec3F( test_vec_1, test_vec_3 );

    printf("vec1:   x: %f y: %f z: %f\n", test_vec_1.x, test_vec_1.y, test_vec_1.z );
    printf("vec2:   x: %f y: %f z: %f\n", test_vec_3.x, test_vec_3.y, test_vec_3.z );
    printf("result: x: %f y: %f z: %f\n", test_vec_ret.x, test_vec_ret.y, test_vec_ret.z );

    putchar('\n');

    /**************************************************************/

    puts("(3)\n");

    test_vec_ret = CrossProductVec3F( test_vec_2, test_vec_3 );

    printf("vec1:   x: %f y: %f z: %f\n", test_vec_2.x, test_vec_2.y, test_vec_2.z );
    printf("vec2:   x: %f y: %f z: %f\n", test_vec_3.x, test_vec_3.y, test_vec_3.z );
    printf("result: x: %f y: %f z: %f\n", test_vec_ret.x, test_vec_ret.y, test_vec_ret.z );

    putchar('\n');

    /**************************************************************/

    return 0;
}
