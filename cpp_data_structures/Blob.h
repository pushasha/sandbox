#ifndef BLOB_H
#define BLOB_H

#include "Utils.h"

// A test class that wraps an int
class Blob {
public:
    Blob() : Blob(0){};
    explicit Blob(int arg);
    Blob(const Blob& blob);
    ~Blob();
    bool operator==(const Blob& rhs) const;
    bool operator!=(const Blob& rhs) const;
private:
    int member_int;
};

#endif //BLOB_H
