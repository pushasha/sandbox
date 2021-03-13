#include <cstdio>
#include <utility>
#include <string>
#include "Blob.h"

std::string to_string(const Blob& blob)
{
    char buffer[50];
    snprintf(buffer, 50, "[Blob | int = %d | &%p]", blob.get_int(), static_cast<const void*>(&blob));
    return std::string(buffer);
}

Blob::Blob()
{
    member_int = 0;
    log_event("Creating %s (default ctor)", to_string(*this).c_str());
}

Blob::Blob(int arg)
{
    member_int = arg;
    log_event("Creating %s", to_string(*this).c_str());
}

Blob::Blob(Blob&& other) noexcept
{
    log_event("Move-constructing %s to %s", to_string(static_cast<const Blob&>(other)).c_str(), to_string(*this).c_str());
    *this = std::move(other);
}

Blob::Blob(const Blob& other)
{
    log_event("Copy-constructing %s to %s", to_string(other).c_str(), to_string(*this).c_str());
    member_int = other.member_int;
}

Blob::~Blob()
{
    log_event("Destroying %s", to_string(*this).c_str());
    member_int = 0;
}

Blob& Blob::operator=(Blob&& other) noexcept
{
    log_event("Move-assigning %s to %s", to_string(static_cast<const Blob&>(other)).c_str(), to_string(*this).c_str());
    member_int = other.member_int;//std::exchange(other.member_int, 0);
    return *this;
}

Blob& Blob::operator=(const Blob& other)
{
    log_event("Copy-assigning %s to %s", to_string(other).c_str(), to_string(*this).c_str());
    this->member_int = other.member_int;
    return *this;
}

bool Blob::operator==(const Blob& rhs) const
{
    return member_int==rhs.member_int;
}

bool Blob::operator!=(const Blob& rhs) const
{
    return !(rhs==*this);
}

int Blob::get_int() const
{
    return member_int;
}