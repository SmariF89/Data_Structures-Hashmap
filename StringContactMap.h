#ifndef STRINGCONTACTMAP_H
#define STRINGCONTACTMAP_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "ContactList.h"
#include "Hash.h"
#include "KeyException.h"
#include "StringContactPair.h"

// Default initial capacity of a StringContactMap.
const int INITIAL_CAPACITY = 100;

// Maximum load (i.e. [number of entries] / [number of buckets]) of a
// StringContactMap.
const double MAX_LOAD = 4.0;

class StringContactMap {

    public:
        // Creates an empty map with the specified initial capacity.
        StringContactMap(int initial_capacity = INITIAL_CAPACITY);

        ~StringContactMap();

        // Returns the number ef entries in this map.
        int size() const;

        // Returns true if and only if the map contains no entries.
        bool empty() const;

        // Returns a vector containing the contacts in this map, ordered by
        // their keys in increasing order.
        vector<Contact> all_contacts() const;

        // Adds the specified key to the map associated with the specified
        // contact.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        void add(string key, Contact value);

        // Returns true if and only if there exists an entry in the map with
        // the specified key.
        bool contains(string key) const;

        // Returns the contact associated wih the specified key.
        // Throws KeyException if no such contact exists.
        Contact get(string key) const;

        // Removes the entry with the specified key from the map.
        // If no entry in the map has the specified key, this operation has no
        // effect.
        void remove(string key);

        // Returns a vector containing the contacts in this map, whose key is
        // prefixed by 'prefix' ordered by their keys in increasing order.
        vector<Contact> prefix_search(string prefix) const;

        // Prints the contacts of this map to the specified stream ordered by
        // their keys in increasing order.
        friend ostream& operator <<(ostream& out, const StringContactMap& map);

    private:
        ListPtr* map;
        int capacity;
        int count;

        // Adds all StringContactPairs contained in the map to the specified
        // vector
        void all_contacts(vector<StringContactPair>& contacts) const;


        int hash_key(string key) const;

        /*If the test fails, the number of items in the hash map is considered to exceed the
        acceptable amount, MAX_LOAD, and we must rebuild the hash map to facilitate the addition of more
        entries. You rebuild the hash map by creating a new hash map containing double the number of buckets as
        the current hash map, and adding all the values of the old hash map to the new hash map.*/
        void load_check();
        void rebuild();

        void destruct();
};

#endif

