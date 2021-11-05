#include <Python.h>

/**
 * print_python_string - prints Python strings
 * @p: string to print
 */
void print_python_string(PyObject *p)
{
	char *tipe;

	printf("[.] string object info\n");
	if (!p || !PyUnicode_Check(p))
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	if (PyUnicode_IS_COMPACT_ASCII(p))
		tipe = "compact ascii";
	else if (PyUnicode_IS_COMPACT(p))
		tipe = "compact unicode object";
	else if (PyUnicode_KIND(p) == PyUnicode_WCHAR_KIND)
		tipe = "legacy string, not ready";
	else if (!PyUnicode_IS_COMPACT(p))
		tipe = "legacty string, ready";
	printf("  type: %s\n", tipe);
	printf("  length: %ld\n", (((PyASCIIObject *)(p))->length));
	printf("  value: %ls\n", (PyUnicode_AsWideCharString(p, NULL)));
}
