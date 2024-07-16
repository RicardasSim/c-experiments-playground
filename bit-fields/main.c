#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {

    unsigned int a;
    unsigned int b;
    unsigned int c;

}St1;

typedef struct {

    unsigned int a : 3;
    unsigned int b : 1;
    unsigned int c : 1;

}St2;

// a structure with forced alignment
typedef struct {

    unsigned int a : 3;
    unsigned int : 0;
    unsigned int b : 1;
    unsigned int : 0;
    unsigned int c : 1;

}St3;

typedef struct {

    unsigned int year;
    unsigned int month : 4;
    unsigned int day : 5;

} Date;

int main()
{
    printf("Hello !\n");

    printf("Size of St1 is %zu bytes\n", sizeof (St1) );
    printf("Size of St2 is %zu bytes\n", sizeof (St2) );
    printf("Size of St3 is %zu bytes\n", sizeof (St3) );

    St2 st_2;

    printf("Size of st_2 is %zu bytes\n", sizeof st_2 );

    st_2.a = 7;
    st_2.b = false;
    st_2.c = true;

    printf("st_2 a is %d\n", st_2.a );
    printf("st_2 b is %d (%s)\n", st_2.b, st_2.b?"true":"false" );
    printf("st_2 c is %d (%s)\n", st_2.c, st_2.c?"true":"false" );

    Date d = { 2024, 7, 16 };

    printf ("Date: %d %d %d\n", d.year, d.month, d.day );
    printf ("Date: %d %02d %02d\n", d.year, d.month, d.day );

    return 0;
}
