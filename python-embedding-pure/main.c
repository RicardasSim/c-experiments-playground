#define PY_SSIZE_T_CLEAN
#include <Python.h>

int main()
{

    PyObject *p_name, *p_module, *p_fnc, *p_args, *p_value;
    const char pm_name[] = "risim_test";
    const char f_name[] = "risim_fnc_tst";

    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");

    p_name = PyUnicode_DecodeFSDefault( pm_name );

    p_module = PyImport_Import( p_name );

    // Release a strong reference to object
    Py_DECREF( p_name );

    if ( p_module == NULL )
    {
        PyErr_Print();
        printf("ERROR: failed to load: %s\n", pm_name );
        Py_Finalize();
        return 1;
    }

    p_fnc = PyObject_GetAttrString( p_module, f_name );

    if ( !( p_fnc && PyCallable_Check( p_fnc ) ) )
    {
        if ( PyErr_Occurred() )
        {
            PyErr_Print();
        }

        printf("ERROR: cannot find function: %s\n", f_name );
        Py_XDECREF( p_fnc );
        Py_DECREF( p_module );
        Py_Finalize();
    }

    //int arg[2] = { 1, 2 };
    double arg[2] = { 1.2, 0.7 };

    p_args = PyTuple_New(2);

    for ( unsigned int i = 0; i < 2; ++i )
    {
        //p_value = PyLong_FromLong( arg[i] );
        p_value = PyFloat_FromDouble( arg[i] );

        if ( !p_value )
        {
            Py_DECREF( p_args );
            Py_XDECREF( p_fnc );
            Py_DECREF( p_module );
            printf("ERROR: cannot convert argument\n");
            Py_Finalize();
            return 1;
        }

        PyTuple_SetItem( p_args, i, p_value );
    }

    p_value = PyObject_CallObject( p_fnc, p_args );

    Py_DECREF( p_args );

    if ( p_value == NULL )
    {
        Py_DECREF( p_fnc );
        Py_DECREF( p_module );
        PyErr_Print();
        printf("ERROR: PyObject_CallObject failed\n");
        Py_Finalize();
        return 1;
    }

    printf("Result: %f\n", PyFloat_AsDouble( p_value ) );
    Py_DECREF( p_value );
    Py_XDECREF( p_fnc );
    Py_DECREF( p_module );
    Py_Finalize();

    return 0;
}
