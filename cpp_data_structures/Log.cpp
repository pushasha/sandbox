#include "Log.h"

bool Log::logging_enabled = true; // true by default

void Log::set_logging_enabled(bool enabled)
{
    logging_enabled = enabled;
}

void Log::log(const char* msg)
{
    if (!logging_enabled) {
        return;
    }

    std::cout << msg << std::endl;
}

void Log::log_event(const char* msg)
{
    if (!logging_enabled) {
        return;
    }

    std::cout << "<< " << msg << " >>" << std::endl;
}

void Log::logf(const char* format, ...)
{
    if (!logging_enabled) {
        return;
    }

    size_t buffer_len = strlen(format) + 2; // 2 is num chars in \n\0

    char* const buffer = new char[buffer_len];
    char* current = buffer;

    va_list arg_ptr;
    va_start(arg_ptr, format);

    vlogf(buffer, buffer_len, current, format, arg_ptr);

    va_end(arg_ptr);
    delete[] buffer;
}

void Log::logf_event(const char* format, ...)
{
    if (!logging_enabled) {
        return;
    }

    size_t fmt_len = strlen(format);
    size_t buffer_len = fmt_len + 8; // 8 is num chars in << >>\n\0

    char* const buffer = new char[buffer_len];
    char* current = buffer;
    *(current++) = '<';
    *(current++) = '<';
    *(current++) = ' ';
    current = current + fmt_len;
    *(current++) = ' ';
    *(current++) = '>';
    *(current) = '>';

    // set current back to where we want to insert format str
    current = buffer + 3;

    va_list arg_ptr;
    va_start(arg_ptr, format);

    vlogf(buffer, buffer_len, current, format, arg_ptr);

    va_end(arg_ptr);
    delete[] buffer;
}

void Log::vlogf(char* const buffer, size_t buffer_len, char* current, const char* format, va_list arg_ptr)
{
    strncpy(current, format, strlen(format));
    current = buffer + (buffer_len - 2); // 2 is num chars in \n\0
    *(current++) = '\n';
    *(current) = '\0';

    vprintf(buffer, arg_ptr);
}
