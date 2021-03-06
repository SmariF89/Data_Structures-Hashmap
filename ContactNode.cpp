#include "ContactNode.h"

ContactNode::ContactNode(string key, Contact value, ContactNode* link)
{
    this->data = StringContactPair(key, value);
    this->link = link;
}

ContactNode::ContactNode(StringContactPair data, ContactNode* link)
{
    this->data = data;
    this->link = link;
}
