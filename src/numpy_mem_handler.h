/* See https://docs.python.org/3/extending/extending.html */
#define PY_SSIZE_T_CLEAN
#include <Python.h>

/* We need at least numpy 1.22 */
#define NPY_TARGET_VERSION NPY_2_0_API_VERSION
#include "numpy/arrayobject.h"


static inline void
c_get_current_handler()
{
    PyObject* handler = PyDataMem_GetHandler();
};
