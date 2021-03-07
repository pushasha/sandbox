#include "Blob.h"

Blob::Blob(int arg)
{
    member_int = arg;
    log_event("Creating Blob with int %d", member_int);
}

Blob::~Blob()
{
    log_event("Destroying Blob with int %d", member_int);
    member_int = 0;
}