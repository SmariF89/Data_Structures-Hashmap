#ifndef CONTACTNODE_H
#define CONTACTNODE_H

#include <string>
#include <vector>

#include "Contact.h"
#include "StringContactPair.h"

struct ContactNode
{
    ContactNode(string key, Contact value, ContactNode* link = NULL);
    ContactNode(StringContactPair data, ContactNode* link = NULL);

    StringContactPair data;
    ContactNode *link;
};

typedef ContactNode* NodePtr;

#endif
