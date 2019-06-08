#ifndef CPP_DICTIONARY_H

#define CPP_DICTIONARY_H

#include <string>

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();
    void add(const std::string& key, int value);
    bool remove(const std::string& key);
    int get_value(const std::string& key);
    void clear();
    bool contains_key(const std::string& key);
    bool contains_value(int value);
    int operator[](const std::string& key);
private:
    struct KeyValuePair{
        KeyValuePair();
        KeyValuePair(const std::string& key, int value);
        std::string key;
        int value{};
        void clear();
    };
    KeyValuePair* entries_; //[5];
    int index_of_key(const std::string& key);
};

#endif //CPP_DICTIONARY_H
