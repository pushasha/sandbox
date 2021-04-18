#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <cstdarg>
#include <cstring>
#include <type_traits>

class Log {
public:
    static void set_logging_enabled(bool enabled);

    static void log(const char* msg);

    static void log_event(const char* msg);

    static void logf(const char* format, ...);

    static void logf_event(const char* format, ...);

    template<class T, class = std::enable_if_t<!std::is_same<T, const char>::value>>
    static void log(T* self, const char* msg)
    {
        if (!logging_enabled) {
            return;
        }

        std::cout << '[' << T::c_log_tag << "] " << msg << std::endl;
    }

    template<class T, class = std::enable_if_t<!std::is_same<T, const char>::value>>
    static void log_event(T* self, const char* msg)
    {
        if (!logging_enabled) {
            return;
        }

        std::cout << "<< [" << T::c_log_tag << "] " << msg << " >>" << std::endl;
    }

    template<class T, class = std::enable_if_t<!std::is_same<T, const char>::value>>
    static void logf(T* self, const char* format, ...)
    {
        if (!logging_enabled) {
            return;
        }

        const char* tag = T::c_log_tag;
        size_t tag_len = strlen(tag);
        size_t fmt_len = strlen(format);
        size_t buffer_len = tag_len + fmt_len + 11; // 5 is for two square brackets, a space, a newline, and a null terminator

        char* const buffer = new char[buffer_len];
        char* current = buffer;

        // add tag to beginning of log
        *(current++) = '[';
        strcpy(current, tag);
        current = current + tag_len;
        *(current++) = ']';
        *(current++) = ' ';

        // add format after tag
        va_list arg_ptr;
        va_start(arg_ptr, format);

        vlogf(buffer, buffer_len, current, format, arg_ptr);

        va_end(arg_ptr);
        delete[] buffer;
    }

    template<class T, class = std::enable_if_t<!std::is_same<T, const char>::value>>
    static void logf_event(T* self, const char* format, ...)
    {
        if (!logging_enabled) {
            return;
        }

        const char* tag = T::c_log_tag;
        size_t tag_len = strlen(tag);
        size_t fmt_len = strlen(format);
        size_t buffer_len = tag_len + fmt_len + 11; // 5 is for two square brackets, a space, a newline, and a null terminator

        char* const buffer = new char[buffer_len];
        char* current = buffer;

        *(current++) = '<';
        *(current++) = '<';
        *(current++) = ' ';

        // add tag to beginning of log
        *(current++) = '[';
        strcpy(current, tag);
        current = current + tag_len;
        *(current++) = ']';
        *(current++) = ' ';

        current = current + fmt_len;

        *(current++) = ' ';
        *(current++) = '>';
        *(current) = '>';

        // set current back to where we want to insert format str
        current = buffer + 6 + tag_len;

        // add format after tag
        va_list arg_ptr;
        va_start(arg_ptr, format);

        vlogf(buffer, buffer_len, current, format, arg_ptr);

        va_end(arg_ptr);
        delete[] buffer;
    }

    template<class T>
    static const void* get_mem_address(const T& ref)
    {
        return static_cast<const void*>(&ref);
    }

private:
    static bool logging_enabled;

    static void vlogf(char* buffer, size_t buffer_len, char* current, const char* format, va_list arg_ptr);
};

#endif //LOG_H
