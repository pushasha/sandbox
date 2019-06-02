#ifndef CPP_DICTIONARY_H

#define CPP_DICTIONARY_H

#include <string>

class Dictionary
{
public:
    Dictionary();
    void add(std::string key, int value);
    bool remove(std::string key);
    int get_value(std::string key);
    void clear();
    bool contains_key(std::string key);
    bool contains_value(int value);
    int operator[] (std::string);
private:
    struct KeyValuePair{
        KeyValuePair();
        KeyValuePair(std::string key, int value);
        std::string key;
        int value;
        void clear();
    };
    KeyValuePair entries_ [5];
    int index_of_key(std::string key);
    inline int size_of_entries(){

        return sizeof(entries_) / sizeof(KeyValuePair);
    }
};

#endif //CPP_DICTIONARY_H
