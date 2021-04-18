#ifndef HASHSET_H
#define HASHSET_H

#include <cstddef>
#include <functional>
#include "CommonTypes.h"
#include "LinkedList.h"
#include "HashSetIterator.h"

namespace Collections
{
template <class T>
class HashSet
{
public:
    friend class HashSetIterator<T>;

    HashSet() = delete;

    explicit HashSet(uint num_buckets)
    {
        hasher = std::hash<T>();
        bucket_count = num_buckets;
        bucket_array = new LinkedList<T>[bucket_count];
    }

    virtual ~HashSet()
    {
        delete[] bucket_array;
        bucket_array = nullptr;
    }

    void add(const T& item)
    {
        LinkedList<T>& list = get_bucket(item);
        if (list.contains(item)){
            return;
        }
        list.add(item);
    }

    void add(T&& item)
    {
        LinkedList<T>& list = get_bucket(item);
        if (list.contains(item)){
            return;
        }
        list.add(std::forward<T>(item));
    }

    void remove(const T& item)
    {
        LinkedList<T>& list = get_bucket(item);
        if (!list.contains(item)){
            return;
        }
        list.remove(item);
    }

    HashSetIterator<T> begin()
    {
        std::size_t idx = 0;
        // make sure the list iterator starts at the first valid index
        for (std::size_t i = 0; i < bucket_count; i++)
        {
            if (!bucket_array[i].is_empty())
            {
                idx = i;
                break;
            }
        }
        return HashSetIterator<T>(this, idx);
    }

    HashSetIterator<T> end()
    {
        return HashSetIterator<T>(this, bucket_count);
    }

private:
    LinkedList<T>& get_bucket(const T& item) const
    {
        std::size_t bucket_idx = get_bucket_idx(item);
        return bucket_array[bucket_idx];
    }

    inline std::size_t get_bucket_idx(const T& item) const
    {
        return hasher(item) % bucket_count;
    }

    LinkedList<T>* bucket_array;
    uint bucket_count;
    std::hash<T> hasher;
};

}

#endif //HASHSET_H
