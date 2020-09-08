#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
#include <vector>
#include "ContactNode.h"
#include "KeyException.h"

using namespace std;

class ContactList
{
    public:
        // Creates an empty list
        ContactList();
        ~ContactList();

        // If there exists a pair with the specified key in the list, the value
        // of that pair is updated with the specified value. Otherwise, the
        // (key, value) pair is added to the back of the list.
        // The function returns true if the (key, value) pair was added to the
        // list; false otherwise (i.e., if the key was present in the list).
        bool add(string key, Contact value);

        // Removes the pair with the specified key from the list. If such a
        // pair exists, the function returns true; false otherwise.
        bool remove(string key);

        // Returns true if and only is this list contains a pair with the
        // specified key.
        bool contains(string key);

        // Returns the contact associated with the specified key.
        // If the specified key is not in the list, KeyException is thrown.
        Contact get(string key);

        // Adds all the StringContactPairs of the list to the specified
        // vector.
        void add_to_vector(vector<StringContactPair>& contacts);

        // Adds all the contacts (i.e., values) of the list, whose key is
        // prefixed by 'prefix', to the specified vector.
        void get_contacts_by_key_prefix(string prefix, vector<StringContactPair>& contacts);

        // Returns a vector containing the StringContactPairs of this list.
        vector<StringContactPair> to_vector();

        // Prints the contacts (i.e., the value of each pair) of this list to
        // the specified output stream. A newline should be printed after each
        // contact.
        friend ostream& operator <<(ostream& outs, ContactList& lis);

    private:
        // pointer to the head of the list
        NodePtr head;

        // Deallocates the memory allocated for the linked list.
        void remove_all();

        NodePtr &find(NodePtr &node, string key);

        bool isPrefix(string const& str1, string const& str2);
};

typedef ContactList* ListPtr;

#endif // INTLIST_H
