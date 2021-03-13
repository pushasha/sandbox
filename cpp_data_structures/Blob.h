#ifndef BLOB_H
#define BLOB_H

#include "Utils.h"

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

#endif //BLOB_H
