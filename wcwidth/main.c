#include <locale.h>
#include <stdio.h>

#define __USE_XOPEN 1

#include <wchar.h>

int main()
{
    setlocale( LC_CTYPE, "en_US.UTF-8" );

    wchar_t wch = L'❤';

    printf( "%lc %d\n", wch, wcwidth(wch) );

    return   0;
}
