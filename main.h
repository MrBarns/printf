#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


/* Testers */
/* #include <stdio.h> */

/*
 * mapper - maps format specifiers to their handler functions
 *
 * @spec: specifier
 * @func: handler function
 */

typedef struct mapper
{
	char spec;
	int (*func) (va_list args);
} Mapper;

int _printf(const char *format, ...);


/* Helper functions */
int handle_specs(const char *format, int x, va_list args);


/* Handler functions */
int print_char(va_list args);
int print_str(va_list args);
int print_cent(va_list args);

#endif
