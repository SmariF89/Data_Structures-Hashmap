#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Contact
{
    string name;
    string phone;
    string email;
    string address;
};

ostream& operator<< (ostream& out, const Contact& contact);

ostream& operator<< (ostream& out, vector<Contact>& contacts);

// Reads contact information in CSV-format (using ';' as delimiter).
istream& operator>> (istream& out, Contact& contact);


#endif
