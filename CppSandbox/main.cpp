#include <iostream>
#include "dictionary.h"

int main() {

    Dictionary dict = Dictionary();
    dict.add("one", 1);
    dict.add("two", 2);
    dict.add("three", 3);
    dict.add("four", 4);
    dict.add("five", 5);

    std::cout << dict["three"] << std::endl;
    return 0;
}