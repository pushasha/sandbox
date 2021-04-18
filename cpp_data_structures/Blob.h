#ifndef BLOB_H
#define BLOB_H

#include <functional>
#include <cstddef>
#include "Log.h"

// A test class that wraps an int
class Blob {
public:
    Blob();
    explicit Blob(int arg);
    Blob(Blob&& other) noexcept;
    Blob(const Blob& other);
    ~Blob();
    Blob& operator=(Blob&& other) noexcept;
    Blob& operator=(const Blob& other);
    bool operator==(const Blob& rhs) const;
    bool operator!=(const Blob& rhs) const;
    int get_int() const;
private:
    int member_int;
};

namespace std {
template <>
struct hash<Blob>
{
  size_t operator()(const Blob& x) const
  {
      return std::hash<int>{}(x.get_int());
  }
};
}
#endif //BLOB_H
