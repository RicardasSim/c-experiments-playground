#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>

int main()
{
    printf("Maximum File Name Length (Chars): %d\n", NAME_MAX );
    printf("Maximum Path Length including nul (Chars): %d\n", PATH_MAX );

    return 0;
}
