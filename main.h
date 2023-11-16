#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


/*
 * struct mapper - maps format specifiers to their handler functions
 *
 * @spec: specifier
 * @func: handler function
 *
 * Description: Mapper groups format specifiers to their handler functions for
 * easy assignments.
 */

struct mapper
{
	char spec;
	int (*func)(va_list args);
};
typedef struct mapper Mapper;

int _printf(const char *format, ...);


/* Helper functions */
int handle_specs(const char *format, int x, va_list args);


/* Handler functions */
int print_char(va_list args);
int print_str(va_list args);
int print_cent(va_list args);

#endif
