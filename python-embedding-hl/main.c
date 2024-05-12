#define PY_SSIZE_T_CLEAN
#include <Python.h>

int main()
{
    int result;

    const char *p_script = "print('Hello from Python')\n";

    Py_Initialize();

    /************************************************************/

    printf("(1)\n");

    result = PyRun_SimpleString( p_script );

    if( result < 0 )
    {
        printf("ERROR: PyRun_SimpleString\n");

        if ( Py_FinalizeEx() < 0 )
        {
            printf("ERROR: Py_FinalizeEx\n");
            return 120;
        }

        return 1;
    }

    /************************************************************/

    printf("(2)\n");

    result = PyRun_SimpleString("for i in range(3):\n\tprint(i)\n");

    if( result < 0 )
    {
        printf("ERROR: PyRun_SimpleString\n");

        if ( Py_FinalizeEx() < 0 )
        {
            printf("ERROR: Py_FinalizeEx\n");
            return 120;
        }

        return 1;
    }

    /************************************************************/

    if ( Py_FinalizeEx() < 0 )
    {
        printf("ERROR: Py_FinalizeEx\n");
        return 120;
    }

    return 0;
}
