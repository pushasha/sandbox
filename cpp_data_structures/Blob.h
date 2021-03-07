#ifndef BLOB_H
#define BLOB_H

#include "Utils.h"

// A test class that wraps an int
class Blob {
public:
    explicit Blob(int arg);
    Blob(Blob& b) = delete;
    ~Blob();

private:
    int member_int;
};

#endif //BLOB_H
