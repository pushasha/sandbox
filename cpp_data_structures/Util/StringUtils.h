#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <cstdio>

namespace StringUtils
{
    template <typename... Ts>
    std::string fmt (const std::string &fmt, Ts... vs)
    {
        char b;
        int required = std::snprintf(&b, 0, fmt.c_str(), vs...) + 1;

        char bytes[required];
        std::snprintf(bytes, required, fmt.c_str(), vs...);

        return std::string(bytes);
    }
}

#endif //STRING_UTILS_H
