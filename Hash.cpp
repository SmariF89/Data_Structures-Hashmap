#include "Hash.h"

///Hash credits go to George V. Reilly at:
//http://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map

unsigned int my_hash_function(const char* p, unsigned int seed)
{
    unsigned int hash = seed;
    while (*p)
    {
        hash = hash * 101  +  *p++;
    }
    return hash;
}
