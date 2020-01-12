#ifndef CPP_DICTIONARY_H

#define CPP_DICTIONARY_H

#include <string>
#include <stdexcept>

template <typename TKey, typename TValue>
class Dictionary
{
public:
    struct KeyValuePair
    {
        KeyValuePair() = default;
        KeyValuePair(const TKey& key, const TValue& value) : key(key), value(value) {}
        ~KeyValuePair()
        {
            key.~TKey();
            value.~TValue();
        }

        TKey key;
        TValue value;
    };

    Dictionary() : entries_(new KeyValuePair[NumEntries]) {}
    ~Dictionary()
    {
        delete[] entries_;
    }

    void add(const TKey& key, const TValue& value)
    {
        // see if we already are storing something with this key
        int index = index_of_key(key);

        if (index >= 0)
        {
            entries_[index] = KeyValuePair(key, value);
            return;
        }

        // this is a new key, so add it to free space
        for (int i = 0; i < NumEntries; i++)
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

    bool remove(const TKey& key)
    {
        int index = index_of_key(key);
        if (index < 0)
        {
            return false;
        }

        entries_[index].~KeyValuePair();
        return true;
    }

    const TValue& get_value(const TKey& key)
    {
        int index = index_of_key(key);
        if (index < 0)
        {
            throw std::runtime_error("Key does not exist!");
        }

        return entries_[index].value;
    }

    KeyValuePair* get_entries()
    {
        return entries_;
    }

    unsigned int size()
    {
        return NumEntries;
    }

    void clear()
    {
        for (int i = 0; i < NumEntries; ++i)
        {
            entries_[i].~KeyValuePair();
        }
    }

    bool contains_key(const TKey& key)
    {
        return index_of_key(key) >= 0;
    }

    bool contains_value(const TValue& value)
    {
        for (int i = 0; i < NumEntries; i++)
        {
            if (value == entries_[i].value)
            {
                return true;
            }
        }

        return false;
    }

    const TValue& operator[](const TKey& key)
    {
        return get_value(key);
    }

private:
    const int NumEntries = 5;
    KeyValuePair* entries_;
    int index_of_key(const TKey& key)
    {
        for (int i = 0; i < NumEntries; i++)
        {
            if (key == entries_[i].key)
            {
                return i;
            }
        }
        return -1;
    }
};

#endif //CPP_DICTIONARY_H
