#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef union U1 {
        char c;
        int i;
} U1;

typedef union U2 {
        char c;
        int i;
        double d;
        char *s;
} U2;

typedef union U3 {
        uint8_t a;
        uint16_t b;
        uint32_t c;
        uint64_t d;
} U3;

int main()
{
    U1 u_1;
    U2 u_2 = { .d = 0.9 };

    printf("sizeof u_1: %zu\n\n", sizeof u_1 );

    printf("sizeof u_2: %zu\n", sizeof u_2 );
    printf("value of u_2.d: %f\n", u_2.d );
    printf("sizeof u_2.c: %zu\n", sizeof u_2.c );
    printf("sizeof u_2.i: %zu\n", sizeof u_2.i );
    printf("sizeof u_2.d: %zu\n", sizeof u_2.d );
    printf("sizeof u_2.s: %zu\n\n", sizeof u_2.s );

    U3 u_3;

    u_3.a = 123;

    puts("u_3.a = 123;");
    printf("%u\n", u_3.a );
    printf("%u\n", u_3.b );
    printf("%u\n", u_3.c );
    printf("%lu\n", u_3.d );

    putchar('\n');

    u_3.b = 12345;

    puts("u_3.b = 12345;");
    printf("%u\n", u_3.a );
    printf("%u\n", u_3.b );
    printf("%u\n", u_3.c );
    printf("%lu\n", u_3.d );

    putchar('\n');

    u_3.c = 1234567890;

    puts("u_3.c = 1234567890;");
    printf("%u\n", u_3.a );
    printf("%u\n", u_3.b );
    printf("%u\n", u_3.c );
    printf("%lu\n", u_3.d );

    putchar('\n');

    u_3.d = 1234567890123456789;

    puts("u_3.d = 1234567890123456789;");
    printf("%u\n", u_3.a );
    printf("%u\n", u_3.b );
    printf("%u\n", u_3.c );
    printf("%lu\n", u_3.d );

    putchar('\n');


    puts("u:");

    U2 u;

    u.c = 'A';

    printf("%c %c\n", u.c, u.c + 1 );

    u.i = 123;

    printf("%d %d\n", u.i, u.i + 1 );

    u.d = 0.8;

    printf("%f %f\n", u.d, u.d + 0.4 );

    char str[] = "Train whistle blows";

    u.s = str;

    printf("%s\n\n", u.s );

    return 0;
}
