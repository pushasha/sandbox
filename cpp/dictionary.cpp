#include "dictionary.h"
#include <stdexcept>

Dictionary::Dictionary()
= default;

void Dictionary::add(const std::string& key, int value)
{
    // see if we already are storing something with this key
    int index = index_of_key(key);

    if (index >= 0)
    {
        entries_[index] = KeyValuePair(key, value);
        return;
    }

    // this is a new key, so add it to free space
    const int array_size = size_of_entries();
    for (int i = 0; i < array_size; i++)
    {
        if (entries_[i].key.empty())
        {
            entries_[i] = KeyValuePair(key, value);
            return;
        }
    }

    // If we get here, it means there was no space left. Throw exception.
    throw std::runtime_error("Dictionary full");
}

bool Dictionary::remove(const std::string& key)
{
    int index = index_of_key(key);
    if (index < 0)
    {
        return false;
    }

    entries_[index].clear();
    return true;
}

void Dictionary::clear()
{
    const int array_size = size_of_entries();
    for (int i = 0; i < array_size; ++i)
    {
        entries_[i].clear();
    }
}

bool Dictionary::contains_key(const std::string& key)
{
    return index_of_key(key) >= 0;
}

bool Dictionary::contains_value(int value)
{
    const int array_size = size_of_entries();
    for (int i = 0; i < array_size; i++)
    {
        if (value == entries_[i].value)
        {
            return true;
        }
    }

    return false;
}

int Dictionary::index_of_key(const std::string& key)
{
    const int array_size = size_of_entries();
    for (int i = 0; i < array_size; i++)
    {
        if (key == entries_[i].key)
        {
            return i;
        }
    }
    return -1;
}

int Dictionary::get_value(const std::string& key)
{
    int index = index_of_key(key);
    if (index < 0)
    {
        throw std::runtime_error("Key does not exist!");
    }

    return entries_[index].value;
}

int Dictionary::operator[](const std::string& key)
{
    return get_value(key);
}

Dictionary::KeyValuePair::KeyValuePair()
= default;

Dictionary::KeyValuePair::KeyValuePair(const std::string& key, int value): key(key), value(value){}

void Dictionary::KeyValuePair::clear()
{
    key.clear();
    value = 0;
}
