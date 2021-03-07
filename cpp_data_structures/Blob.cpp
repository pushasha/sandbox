#include "Blob.h"

Blob::Blob(int arg)
{
    member_int = arg;
    log_event("Creating Blob with int %d", member_int);
}

Blob::Blob(const Blob& blob)
{
    member_int = blob.member_int;
    log_event("Copy-constructing Blob with int %d", blob.member_int);
}

Blob::~Blob()
{
    log_event("Destroying Blob with int %d", member_int);
    member_int = 0;
}

bool Blob::operator==(const Blob& rhs) const
{
    return member_int==rhs.member_int;
}

bool Blob::operator!=(const Blob& rhs) const
{
    return !(rhs==*this);
}
