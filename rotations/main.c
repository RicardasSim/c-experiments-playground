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

SIFNC void RotateXL( Vec3Flt *p_vec, float angle_radians )
{
    float s = sinf( angle_radians );
    float c = cosf( angle_radians );

    float tmp_y = p_vec->y;

    p_vec->y = tmp_y * c - p_vec->z * s;
    p_vec->z = tmp_y * s + p_vec->z * c;
}

SIFNC void RotateYL( Vec3Flt *p_vec, float angle_radians )
{
    float s = sinf( angle_radians );
    float c = cosf( angle_radians );

    float tmp_z = p_vec->z;

    p_vec->z = tmp_z * c - p_vec->x * s;
    p_vec->x = tmp_z * s + p_vec->x * c;
}

SIFNC void RotateZL( Vec3Flt *p_vec, float angle_radians )
{
    float s = sinf( angle_radians );
    float c = cosf( angle_radians );

    float tmp_x = p_vec->x;

    p_vec->x = tmp_x * c - p_vec->y * s;
    p_vec->y = tmp_x * s + p_vec->y * c;
}

SIFNC void RotateXR( Vec3Flt *p_vec, float angle_radians )
{
    float s = sinf( angle_radians );
    float c = cosf( angle_radians );

    float tmp_z = p_vec->z;

    p_vec->z = tmp_z * c + p_vec->y * s;
    p_vec->y = p_vec->y * c - tmp_z * s;
}

SIFNC void RotateYR( Vec3Flt *p_vec, float angle_radians )
{
    float s = sinf( angle_radians );
    float c = cosf( angle_radians );

    float tmp_x = p_vec->x;

    p_vec->x = tmp_x * c + p_vec->z * s;
    p_vec->z = p_vec->z * c - tmp_x * s;
}

SIFNC void RotateZR( Vec3Flt *p_vec, float angle_radians )
{
    float s = sinf( angle_radians );
    float c = cosf( angle_radians );

    float tmp_y = p_vec->y;

    p_vec->y = tmp_y * c + p_vec->x * s;
    p_vec->x = p_vec->x * c - tmp_y * s;
}

int main()
{

    Vec3Flt test_vec;

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    puts("Left handed coordinate system rotations.");

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateXL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateYL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateZL( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    puts("");

    test_vec.x = 0.0f;
    test_vec.y = 1.0f;
    test_vec.z = 0.0f;

    puts("Right handed coordinate system rotations.");

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateXR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateYR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    RotateZR( &test_vec, DegreesToRadiansFloat( 90.0f ) );

    printf("x: %f y: %f z: %f\n", test_vec.x, test_vec.y, test_vec.z );

    putchar('\n');

    return 0;
}
