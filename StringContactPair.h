#ifndef STRINGCONTACTPAIR_H
#define STRINGCONTACTPAIR_H

#include <string>
#include "Contact.h"

using namespace std;

struct StringContactPair
{
    StringContactPair();
    StringContactPair(string key, Contact value);

    string key;
    Contact value;
};

bool operator<(const StringContactPair& lhs, const StringContactPair& rhs);

#endif
