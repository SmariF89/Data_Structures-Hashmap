#include "ContactNode.h"

StringContactPair::StringContactPair()
{

}

StringContactPair::StringContactPair(string key, Contact value)
{
    this->key = key;
    this->value = value;
}

bool operator<(const StringContactPair& lhs, const StringContactPair& rhs) {
    return lhs.key < rhs.key;
}
