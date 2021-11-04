#include <Python.h>

/**
 * print_python_bytes - prints
 * @p: list
 */
void print_python_bytes(PyObject *p)
{
	char *bytes;
	Py_ssize_t size, i;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = (((PyVarObject *)(p))->ob_size);
	bytes = (((PyBytesObject *)(p))->ob_sval);
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", bytes);
	size = size > 9 ? 10 : size + 1;
	printf("  first %ld bytes: ", size);
	for (i = 0; i < size; i++)
		printf("%02hhx%c", bytes[i], i < size - 1 ? ' ' : '\n');
}

/**
 * print_python_list - prints
 * @p: list
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size = Pysize(p), i;
	PyObject *obj;

	if (!p)
		return;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
	{
		obj = ((PyListObject *)(p))->ob_obj[i];
		printf("Element %ld: %s\n", i, obj->ob_type->tp_name);
		if (PyBytes_Check(obj))
			print_python_bytes(obj);
	}
}
