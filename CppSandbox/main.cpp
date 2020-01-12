#include <iostream>
#include "dictionary.h"

int main()
{
    try
    {
        Dictionary<std::string, std::string> dict = Dictionary<std::string, std::string>(1);
        dict.add("one", "1");
        dict.add("two", "2");
        dict.add("three", "3");
        dict.add("four", "4");
        dict.add("five", "5");

        dict.remove("three");

        for (size_t i = 0; i < dict.size(); i++)
        {
            Dictionary<std::string, std::string>::KeyValuePair& pair = dict.get_entries()[i];
            std::cout << "(" << pair.key << "," << pair.value << ")" << std::endl;
        }
    }
    catch (std::exception ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}