#include "Utils.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>

void log(const char* format, ...)
{
    size_t len = strlen(format);
    size_t new_len = len + 2; // 2 is num chars in \n\0

    char* buffer = new char[new_len];
    char* current = buffer;
    strcpy(current, format);
    current = current+len;
    *(current++) = '\n';
    *(current) = '\0';

    va_list arg_ptr;
    va_start(arg_ptr, format);

    vprintf(buffer, arg_ptr);

    va_end(arg_ptr);
    delete[] buffer;
}

void log_event(const char* format, ...)
{
    size_t len = strlen(format);
    size_t new_len = len+8; // 8 is num chars in << >>\n\0

    char* buffer = new char[new_len];
    char* current = buffer;
    *(current++) = '<';
    *(current++) = '<';
    *(current++) = ' ';
    strcpy(current, format);
    current = current+len;
    *(current++) = ' ';
    *(current++) = '>';
    *(current++) = '>';
    *(current++) = '\n';
    *(current) = '\0';

    va_list arg_ptr;
    va_start(arg_ptr, format);

    vprintf(buffer, arg_ptr);

    va_end(arg_ptr);
    delete[] buffer;
}

