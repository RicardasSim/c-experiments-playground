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


Vec3Flt NormalizeVec3F( Vec3Flt v )
{

    Vec3Flt vec_ret;

    float length = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

    vec_ret.x = v.x / length;
    vec_ret.y = v.y / length;
    vec_ret.z = v.z / length;

    return vec_ret;
}


int main()
{

    Vec3Flt test_vec;

    /**************************************************************/

    test_vec.x = 1.0f;
    test_vec.y = 1.0f;
    test_vec.z = 1.0f;

    puts("(1)\n");

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    test_vec = NormalizeVec3F( test_vec );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    /**************************************************************/

    test_vec.x = 0.1f;
    test_vec.y = 0.1f;
    test_vec.z = 0.1f;

    puts("(2)\n");

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    test_vec = NormalizeVec3F( test_vec );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    /**************************************************************/

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 1.0f;

    puts("(3)\n");

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    test_vec = NormalizeVec3F( test_vec );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    /**************************************************************/

    test_vec.x = 0.5f;
    test_vec.y = 0.0f;
    test_vec.z = 0.0f;

    puts("(4)\n");

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    test_vec = NormalizeVec3F( test_vec );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    /**************************************************************/

    return 0;
}
