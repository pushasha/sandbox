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

    Dictionary(unsigned int initial_capacity) : entries_(new KeyValuePair[initial_capacity]), capacity_(initial_capacity) {}
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

        if (num_entries_ + 1 > capacity_)
        {
            std::cout << "Expanding dictionary from " << capacity_ << " to " << capacity_ + grow_size_<< std::endl;
            // If we get here, it means there was no space left. Expand.
            KeyValuePair* new_entries = new KeyValuePair[capacity_ + grow_size_];
            capacity_ = capacity_ + grow_size_;

            if (num_entries_ > capacity_)
            {
                return;
            }

            // Copy entries into new array
            for (size_t i = 0; i < num_entries_; i++)
            {
                new_entries[i] = entries_[i];
            }

            // free up old array
            delete[] entries_;

            entries_ = new_entries;
        }

        // this is a new key, so add it to the first free space
        entries_[num_entries_] = KeyValuePair(key, value);
        num_entries_++;
    }

    bool remove(const TKey& key)
    {
        int index = index_of_key(key);
        if (index < 0)
        {
            return false; // Entry with key does not exist, so nothing was removed.
        }

        entries_[index].~KeyValuePair();
        
        if ((unsigned int)index < num_entries_ - 1)
        {
            // Shift everything down
            for (size_t i = index; i < num_entries_ - 1; i++)
            {
                entries_[i] = entries_[i + 1];
            }
        }

        num_entries_--;
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
        return num_entries_;
    }

    void clear()
    {
        for (size_t i = 0; i < num_entries_; ++i)
        {
            entries_[i].~KeyValuePair();
        }

        num_entries_ = 0;
    }

    bool contains_key(const TKey& key)
    {
        return index_of_key(key) >= 0;
    }

    bool contains_value(const TValue& value)
    {
        for (size_t i = 0; i < num_entries_; i++)
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
    unsigned int grow_size_ = 1;
    unsigned int capacity_ = 0;
    unsigned int num_entries_ = 0;
    KeyValuePair* entries_;
    int index_of_key(const TKey& key)
    {
        for (size_t i = 0; i < num_entries_; i++)
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
