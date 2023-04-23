#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0;
    int i;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'c') {
                char c = va_arg(args, int);
                _putchar(c);
                printed_chars++;
            } else if (format[i] == 's') {
                char *s = va_arg(args, char *);
                fputs(s, stdout);
                printed_chars += strlen(s);
            } else if (format[i] == '%') {
                _putchar('%');
                printed_chars++;
            } else {
                _putchar('%');
                _putchar(format[i]);
                printed_chars += 2;
            }
        } else {
            _putchar(format[i]);
            printed_chars++;
        }
    }

    va_end(args);
    return printed_chars;
}

