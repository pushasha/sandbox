#ifndef HASHSET_ITERATOR_H
#define HASHSET_ITERATOR_H

#include <cstddef>

namespace Collections {

template <class T> class LinkedListIterator; // fwd decl
template <class T> class HashSet;

template<class T>
class HashSetIterator {
public:
    HashSetIterator() = default;
    HashSetIterator(HashSet<T>* a_set, std::size_t a_bucket_idx)
    {
        set = a_set;
        bucket_idx = a_bucket_idx;
        list_itr = (set->bucket_array[bucket_idx]).begin();
    }
    HashSetIterator(const HashSetIterator& other) = default;
    ~HashSetIterator() = default;

    HashSetIterator& operator++()
    {
        ++list_itr;

        if ((set->bucket_array[bucket_idx]).end() == list_itr)
        {
            ++bucket_idx;

            while (bucket_idx < (set->bucket_count) && (set->bucket_array[bucket_idx].is_empty())){
                ++bucket_idx;
            }

            if (bucket_idx == (set->bucket_count))
            {
                return *this; // end of set
            }

            LinkedList<T>& bucket = set->bucket_array[bucket_idx];
            list_itr = bucket.begin();
        }

        return *this;
    }

    bool operator==(const HashSetIterator& other) const
    {
        return bucket_idx == other.bucket_idx
            && set == other.set;
    }

    bool operator!=(const HashSetIterator& other) const
    {
        return !operator==(other);
    }

    const T& operator*() const
    {
        return *list_itr;
    }

    T* operator->() const
    {
        return &(operator*());
    }

private:
    LinkedListIterator<T> list_itr;
    HashSet<T>* set;
    std::size_t bucket_idx;
};

}

#endif //HASHSET_ITERATOR_H
