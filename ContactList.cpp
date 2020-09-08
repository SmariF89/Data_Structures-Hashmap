#include "ContactList.h"

using namespace std;

ContactList::ContactList()
{
    head = NULL;
}

ContactList::~ContactList()
{
    remove_all();
}

bool ContactList::add(string key, Contact value)
{
    if(head == NULL)
    {
        head = new ContactNode(key, value, NULL);               //Add head if list is empty
        return true;
    }

    NodePtr &newNode = find(head, key);                         //Find desired node

    if(newNode != NULL)                                         //If find doesn't return a nullptr
    {                                                           //then it must have found a node
        newNode->data.value = value;                            //with an already existing key.
        return false;
    }

    if(newNode == NULL)                                         //If find returns a nullptr then it
    {                                                           //must mean that it reached the end
        newNode = new ContactNode(key, value, NULL);            //end of the list and returns a
        return true;                                            //reference to it so it can be modified
    }                                                           //directly by adding a new node.

    return false;
}

NodePtr &ContactList::find(NodePtr &node, string key)           //Has to be recursive
{                                                               //or else I am always altering
    if(node == NULL)                                            //the value of head because it
    {                                                           //a is reference.
        return node;
    }

    if(node->data.key == key)
    {
        return node;
    }

    return find(node->link, key);
}

bool ContactList::remove(string key)
{
    if(head == NULL)
    {
        return false;
    }

    NodePtr &nodeToRemove = find(head, key);

    if(nodeToRemove != NULL)
    {
        NodePtr tmp = nodeToRemove;
        nodeToRemove = nodeToRemove->link;
        delete tmp;

        return true;
    }

    if(nodeToRemove == NULL)
    {
        return false;
    }

    return false;
}

bool ContactList::contains(string key)
{
    NodePtr it = head;

    while(it != NULL)
    {
        if(it->data.key == key)
        {
            return true;
        }
        it = it->link;
    }
    return false;
}

Contact ContactList::get(string key)
{
    NodePtr nodeToFind = find(head, key);
    if(nodeToFind == NULL)
    {
        throw KeyException();
    }

    return nodeToFind->data.value;
}

void ContactList::remove_all()
{
    NodePtr subjectToDestruction = head;

    while(subjectToDestruction != NULL)
    {
        head = subjectToDestruction;
        subjectToDestruction = subjectToDestruction->link;

        delete head;
    }
}

void ContactList::add_to_vector(vector<StringContactPair>& contacts)
{
    NodePtr it = head;

    while(it != NULL)
    {
        contacts.push_back(it->data);
        it = it->link;
    }
}

void ContactList::get_contacts_by_key_prefix(string prefix, vector<StringContactPair>& contacts)
{
    NodePtr it = head;

    while(it != NULL)
    {
        //Notar hjálparfall til að kanna prefixið.
        //Ef true, þá er gögnunum safnað í contacts.
        if(isPrefix(prefix, it->data.key))
        {
            contacts.push_back(it->data);
        }

        //Ítrun í næstu nóðu.
        it = it->link;
    }
}

//Almennt fall sem getur kannað prefix óháð því hvor strengurinn er lengri.
//Notar std::min til að ganga úr skugga um að réttur samanburður á sér stað.
//Range-ið er því byrjunin á fyrri strengnum(prefixið) upp að lokum þess
//sem er styttri (sem er reyndar alltaf prefixið í þessu tilfelli). Það er svo
//borið saman við seinni strenginn (sem er key). Skilar true ef stenst.
bool ContactList::isPrefix(string const& str1, string const& str2)
{
    bool prefix = equal(str1.begin(), str1.begin() + min(str1.size(), str2.size()), str2.begin());
    return prefix;
}

vector<StringContactPair> ContactList::to_vector()
{
    vector<StringContactPair> contacts;
    add_to_vector(contacts);

    return contacts;
}

ostream& operator <<(ostream& outs, ContactList& lis)
{
    vector<StringContactPair> contacts = lis.to_vector();

    for(vector<StringContactPair>::iterator it = contacts.begin(); it != contacts.end(); it++)
    {
        outs << it->value << endl;
    }
    return outs;
}
