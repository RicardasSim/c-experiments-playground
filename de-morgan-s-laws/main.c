#include <stdio.h>
#include <stdlib.h>

/*
De Morgan's Laws
not (A or B) = not A and not B
not (A and B) = not A or not B
*/

int main()
{

    printf("not (A or B) = not A and not B\n");
    printf("not (A and B) = not A or not B\n");

    puts("");

    printf("!(0||0) : %s\t", !(0||0) ? "1" : "0");
    printf("!0&&!0 : %s\n", !0&&!0 ? "1" : "0");

    printf("!(0||1) : %s\t", !(0||1) ? "1" : "0");
    printf("!0&&!1 : %s\n", !0&&!1 ? "1" : "0");

    printf("!(1||0) : %s\t", !(1||0) ? "1" : "0");
    printf("!1&&!0 : %s\n", !1&&!0 ? "1" : "0");

    printf("!(1||1) : %s\t", !(1||1) ? "1" : "0");
    printf("!1&&!1 : %s\n", !1&&!1 ? "1" : "0");

    puts("");

    printf("!(0&&0) : %s\t", !(0&&0) ? "1" : "0");
    printf("!0||!0 : %s\n", !0||!0 ? "1" : "0");

    printf("!(0&&1) : %s\t", !(0&&1) ? "1" : "0");
    printf("!0||!1 : %s\n", !0||!1 ? "1" : "0");

    printf("!(1&&0) : %s\t", !(1&&0) ? "1" : "0");
    printf("!1||!0 : %s\n", !1||!0 ? "1" : "0");

    printf("!(1&&1) : %s\t", !(1&&1) ? "1" : "0");
    printf("!1||!1 : %s\n", !1||!1 ? "1" : "0");

    puts("");

    return 0;
}
