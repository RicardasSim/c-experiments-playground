#include <stdio.h>
#include <stdlib.h>

/*
Foreground Colors:
-------------------
Red: \x1b[31m
Green: \x1b[32m
Yellow: \x1b[33m
Blue: \x1b[34m
Magenta:\x1b[35m
Cyan: \x1b[36m
White: \x1b[37m

Background Colors:
-------------------
Red: \x1b[41m
Green: \x1b[42m
Yellow: \x1b[43m
Blue: \x1b[44m
Magenta:\x1b[45m
Cyan: \x1b[46m
White: \x1b[47m

Combining Colors and Formatting:
---------------------------------
Bold: \x1b[1m
Dim: \x1b[2m (not supported by all terminals)
Italic: \x1b[3m
Underlined: \x1b[4m
Blinking: \x1b[5m (not supported by all terminals)
Inverted: \x1b[7m
Hidden: \x1b[8m
Strikethrough: \x1b[9m (not supported by all terminals)
*/

#define COLOR_RESET "\x1B[0m"
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_BLUE "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_WHITE "\x1B[37m"

int main()
{

    printf( COLOR_GREEN "Green " COLOR_RESET );

    printf( COLOR_RED "Red " COLOR_YELLOW "Yellow " COLOR_BLUE "Blue " COLOR_RESET );

    printf( COLOR_MAGENTA "Magenta " COLOR_CYAN "Cyan " COLOR_WHITE "White " COLOR_RESET );

    printf( "\x1b[1m" COLOR_MAGENTA "Bold Magenta " COLOR_RESET " " );

    printf( "\x1b[4m" COLOR_MAGENTA "Underlined Magenta" COLOR_RESET "\n" );

    return 0;

}
