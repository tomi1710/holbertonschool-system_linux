#include <Python.h>


/**
 * print_python_list - prints
 * @p: list to print
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size = PyList_Size(p), i;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
		printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
}
