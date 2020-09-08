#include "StringContactMap.h"
#include "Hash.h"

#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
    count = 0;
    capacity = initial_capacity;
    map = new ContactList*[capacity];

    for(int i = 0; i < capacity; i++)           //Initialization of each list
    {
        map[i] = new ContactList();
    }
}

StringContactMap::~StringContactMap()
{
    destruct();
}

void StringContactMap::load_check()
{
    if(!((count / capacity) < MAX_LOAD))
    {
        rebuild();
    }
}


void StringContactMap::rebuild()
{
    vector<StringContactPair> backup;

    for(int i = 0; i < capacity; i++)
    {
        map[i]->add_to_vector(backup);                  //Backup before deletion.
    }

    destruct();                                         //Delete old map.
    capacity *= 2;                                      //Double the capacity.
    map = new ContactList*[capacity];                   //Remaking map with bigger capacity.

    for(int i = 0; i < capacity; i++)                   //Initialization of each list in the new
    {                                                   //map. The same as is done in the constructor.
        map[i] = new ContactList();
    }

    for(size_t i = 0; i < backup.size(); i++)           //Re-adding the values from the backup. Each entry
    {                                                   //gets a new hash value calculated with the modulus
        add(backup[i].key, backup[i].value);            //of the new capacity.
    }
}

//I made this in order to reuse it in destructor and rebuild.
void StringContactMap::destruct()
{
    for(int i = 0; i < capacity; i++)
    {
        if(map[i] != NULL)                          //Deleting every single list in the map.
        {
            delete map[i];
        }
    }
    delete [] map;                                 //Finally deleting the map itself.
}

int StringContactMap::size() const
{
    return count;
}

bool StringContactMap::empty() const
{
    return count == 0;
}

vector<Contact> StringContactMap::all_contacts() const
{
    vector<StringContactPair> contactPairs;
    vector<Contact> contacts;

    for(int i = 0; i < capacity; i++)                             //Upper loop iterates through every
    {                                                             //bucket and retrieves its list of
        map[i]->add_to_vector(contactPairs);                      //contact pairs. The lower loop filters
    }                                                             //out the contacts from the pairs.

    sort(contactPairs.begin(), contactPairs.end());

    for(size_t j = 0; j < contactPairs.size(); j++)
    {
        contacts.push_back(contactPairs[j].value);
    }

    return contacts;
}

void StringContactMap::add(string key, Contact value)
{
    load_check();

    int index = hash_key(key);
    if(map[index]->add(key, value))
    {
        count++;
    }
}

int StringContactMap::hash_key(string key) const
{
    const char* p = key.c_str();                        //My hash function relies on getting
    return my_hash_function(p, 0) % capacity;           //a string as a char*. That's why I
}                                                       //convert the key this way.

void StringContactMap::remove(string key)
{
    int index = hash_key(key);

    if(map[index]->remove(key))
    {
        count--;
    }
}

bool StringContactMap::contains(string key) const
{
    int index = hash_key(key);
    return map[index]->contains(key);
}

Contact StringContactMap::get(string key) const
{
    int index = hash_key(key);
    return map[index]->get(key);
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    vector<StringContactPair> pairs;
    vector<Contact> contacts;

    for(int i = 0; i < capacity; i++)
    {
        map[i]->get_contacts_by_key_prefix(prefix, pairs);
    }

    sort(pairs.begin(), pairs.end());

    for(size_t j = 0; j < pairs.size(); j++)
    {
        contacts.push_back(pairs[j].value);
    }

    return contacts;
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
    vector<Contact> contacts = map.all_contacts();

    for(size_t i = 0; i < contacts.size(); i++) {
        out << contacts[i] << endl;
    }
    return out;
}

