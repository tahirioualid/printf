#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0; // To keep track of the number of characters printed
    
    while (*format) {
        if (*format == '%') {
            format++; // Move to the character after '%'
            if (*format == '\0') {
                break; // Handle the case of '%' at the end of the format string
            }
            
            if (*format == 'c') {
                // Character specifier
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // String specifier
                const char *str = va_arg(args, const char *);
                while (*str) {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                // Literal '%' specifier
                putchar('%');
                count++;
            }
        } else {
            putchar(*format);
            count++;
        }
        
        format++; // Move to the next character in the format string
    }
    
    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! Your lucky number is %d%c\n", "Alice", 7, '!');
    return 0;
}
