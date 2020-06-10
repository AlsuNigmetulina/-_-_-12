#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class Contacts {
private:
    int n;
    string *name;
    string *surname;
    double *number;
    string *address;
    string *category;
    void arr()
    {
        name = new string[n];
        surname = new string[n];
        number = new double[n];
        address = new string[n];
        category = new string[n];
    }
public:
    Contacts();
    Contacts(const Contacts &c);
    Contacts(int size);
    ~Contacts();
    Contacts& operator= (const Contacts &m);
    void input1();
    void output1() const;
    void edit_el();
    void remove_contacts();
    void lookup_category();
    void tofile();
    void fromfile();
    void push_back1();
    void del();
    void lookup_number();
    void lookup_name_surname();
    };


#endif // CONTACT_H_INCLUDED
