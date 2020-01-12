#include <iostream>
#include "dictionary.h"

int main() {

    Dictionary<std::string, std::string> dict = Dictionary<std::string, std::string>();
    dict.add("one", "1");
    dict.add("two", "2");
    dict.add("three", "3");
    dict.add("four", "4");
    dict.add("five", "5");

    for (size_t i = 0; i < dict.size(); i++)
    {
        Dictionary<std::string, std::string>::KeyValuePair& pair = dict.get_entries()[i];
        std::cout << "(" + pair.key + "," + pair.value + ")" << std::endl;
    }

    return 0;
}