/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SIFNC static inline

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

SIFNC float RadiansToDegreesFloat( float angle_radians )
{
    return angle_radians * 180.0f / M_PI;
}


SIFNC float DegreesToRadiansFloat( float angle_degrees )
{
    return angle_degrees * M_PI / 180.0f;
}


SIFNC double RadiansToDegreesDouble( double angle_radians )
{
    return angle_radians * 180.0 / M_PI;
}


SIFNC double DegreesToRadiansDouble( double angle_degrees )
{
    return angle_degrees * M_PI / 180.0;
}


void RotateXCCWL( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_y = p_vec->y;

    p_vec->y = tmp_y * c - p_vec->z * s;
    p_vec->z = tmp_y * s + p_vec->z * c;

}


void RotateXCWL( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_y = p_vec->y;

    p_vec->y = tmp_y * c + p_vec->z * s;
    //p_vec->z = tmp_y * -s + p_vec->z * c;
    p_vec->z = p_vec->z * c - tmp_y * s;
}


void RotateXCCWR( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_z = p_vec->z;

    p_vec->z = tmp_z * c - p_vec->y * s;
    p_vec->y = tmp_z * s + p_vec->y * c;

}


void RotateXCWR( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_z = p_vec->z;

    p_vec->z = tmp_z * c + p_vec->y * s;
    //p_vec->y = tmp_z * -s + p_vec->y * c;
    p_vec->y = p_vec->y * c - tmp_z * s;
}


void RotateYCCWL( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_z = p_vec->z;

    p_vec->z = tmp_z * c - p_vec->x * s;
    p_vec->x = tmp_z * s + p_vec->x * c;

}


void RotateYCWL( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_z = p_vec->z;

    p_vec->z = tmp_z * c + p_vec->x * s;
    //p_vec->x = tmp_z * -s + p_vec->x * c;
    p_vec->x = p_vec->x * c - tmp_z * s;
}


void RotateYCCWR( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_x = p_vec->x;

    p_vec->x = tmp_x * c - p_vec->z * s;
    p_vec->z = tmp_x * s + p_vec->z * c;

}


void RotateYCWR( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_x = p_vec->x;

    p_vec->x = tmp_x * c + p_vec->z * s;
    //p_vec->z = tmp_x * -s + p_vec->z * c;
    p_vec->z = p_vec->z * c - tmp_x * s;
}


void RotateZCCWL( Vec3Flt *p_vec, float angle_rad )
{

    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_x = p_vec->x;

    p_vec->x = tmp_x * c - p_vec->y * s;
    p_vec->y = tmp_x * s + p_vec->y * c;

}


void RotateZCWL( Vec3Flt *p_vec, float angle_rad )
{

    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_x = p_vec->x;

    p_vec->x = tmp_x * c + p_vec->y * s;
    //p_vec->y = tmp_x * -s + p_vec->y * c;
    p_vec->y = p_vec->y * c - tmp_x * s;
}


void RotateZCCWR( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_y = p_vec->y;

    p_vec->y = tmp_y * c - p_vec->x * s;
    p_vec->x = tmp_y * s + p_vec->x * c;

}


void RotateZCWR( Vec3Flt *p_vec, float angle_rad )
{
    float s = sinf(angle_rad);
    float c = cosf(angle_rad);

    float tmp_y = p_vec->y;

    p_vec->y = tmp_y * c + p_vec->x * s;
    //p_vec.x = tmp_y * -s + p_vec->x * c;
    p_vec->x = p_vec->x * c - tmp_y * s;
}


int main()
{

    Vec3Flt test_vec;

    /********************* X Axis ***********************/

    puts("Right handed coordinate system, X axis, Clockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateXCWR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Right handed coordinate system, X axis, Counterclockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateXCCWR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Left handed coordinate system, X axis, Clockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateXCWL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Left handed coordinate system, X axis, Counterclockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateXCCWL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    /********************* Y Axis ***********************/

    puts("Right handed coordinate system, Y axis, Clockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 1.0f;
    test_vec.y = 0.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateYCWR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Right handed coordinate system, Y axis, Counterclockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 1.0f;
    test_vec.y = 0.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateYCCWR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Left handed coordinate system, Y axis, Clockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 1.0f;
    test_vec.y = 0.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateYCWL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Left handed coordinate system, Y axis, Counterclockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 1.0f;
    test_vec.y = 0.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateYCCWL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    /********************* Z Axis ***********************/

    puts("Right handed coordinate system, Z axis, Clockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateZCWR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Right handed coordinate system, Z axis, Counterclockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateZCCWR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Left handed coordinate system, Z axis, Clockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateZCWL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    puts("Left handed coordinate system, Z axis, Counterclockwise.\n"
         "(when the angle is 90 degrees, positive)");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateZCCWL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    return 0;
}
