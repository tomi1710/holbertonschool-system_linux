#include <Python.h>

/**
 * print_python_bytes - prints
 * @p: list
 */
void print_python_bytes(PyObject *p)
{
	char *py_bytes_str;
	Py_ssize_t i;
	Py_ssize_t size;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = (((PyVarObject *)(p))->ob_size);
	py_bytes_str = (((PyBytesObject *)(p))->ob_sval);
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", py_bytes_str);
	size = size > 9 ? 10 : size + 1;
	printf("  first %ld bytes: ", size);
	for (i = 0; i < size; i++)
		printf("%02hhx%c", py_bytes_str[i], i < size - 1 ? ' ' : '\n');
}

/**
 * print_python_list - prints
 * @p: list
 */
void print_python_list(PyObject *p)
{
	PyObject *item;
	Py_ssize_t i;
	Py_ssize_t size = PyList_Size(p);

	if (!p)
		return;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
	{
		item = ((PyListObject *)(p))->ob_item[i];
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
