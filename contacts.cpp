#include "contact.h"
#include <iomanip>
#include <fstream>
Contacts::Contacts()
{
    n = 0;
    name = 0;
    surname = 0;
    number = 0;
    address = 0;
    category = 0;

}
Contacts::Contacts(int size)
{
    n = size;
    name = new string[size];
    surname = new string[size];
    number = new double[size];
    address = new string[size];
    category = new string[size];
    for(int i = 0; i < size; i++)
    {
        name[i] = "none";
        surname[i] = "none";
        number[i] = 0;
        address[i] = "none";
        category[i] = "none";
    }
}
Contacts::Contacts(const Contacts &c)
{
    n=c.n;
    name = new string[n];
    surname = new string[n];
    number = new double[n];
    address = new string[n];
    category = new string[n];
    for(int i = 0; i < n; i++)
    {
        name[i] = c.name[i];
        surname[i] = c.surname[i];
        number[i] = c.number[i];
        address[i] = c.address[i];
        category[i] = c.category[i];
    }
}

void Contacts::output1() const{

    cout << setw(11) << "NAME\t" << setw(11) << "SURNAME\t" << setw(11) << "NUMBER\t" <<  setw(11) << "ADDRESS\t" <<  setw(11) << "CATEGORY\n";
cout << "\n";
for (int i = 0; i < n; i++)
{
    cout << i+1 <<"." << setw(10) << name[i] << "\t" << setw(10) << surname[i] << "\t" << setw(10)  << fixed << setprecision(0) << number[i] << "\t" << setw(10) << address[i] << "\t" << setw(10) << category[i] << "\n";

}
cout << "\n";
cout << "\n";
}
void Contacts::input1()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Write name:";
        cin >> name[i];
        cout << "Write surname:";
        cin >> surname[i];
        cout << "Write number:";
        cin >> number[i];
        if (number[i] < 0)
        {
            do{
        cout << "\nyou entered the wrong number;\n";
        cout << "Write number:";
        cin >> number[i];}while (number[i] < 0);
            }

        cout << "Write address:";
        cin >> address[i];
        cout << "Write category (if family - FM; if friend - FD; if work - WK; if other - OR):";
        cin >> category[i];
    }
    output1();
}



void Contacts::edit_el()
{
    int num;
    cout << "Input number of records to edit:";
    cin >> num;
    cout << "Write name:";
    cin >> name[num-1];
    cout << "Write surname:";
    cin >> surname[num-1];
    cout << "Write number:";
    cin >> number[num-1];
            if (number[num-1] < 0)
        {
            do{
        cout << "\nyou entered the wrong number;\n";
        cout << "Write number:";
        cin >> number[num-1];}while (number[num-1] < 0);
            }
    cout << "Write address:";
    cin >> address[num-1];
    cout << "Write category:";
    cin >> category[num-1];
output1();
}



void Contacts::remove_contacts()
{
    delete [] name;
    delete [] surname;
    delete [] number;
    delete [] address;
    delete [] category;
    cout << "Contacts deleted\n";
}

void Contacts::lookup_category()
{
    string catlook;
    cout << "Input category:";
    cin >> catlook;
    cout<< "\n";
    cout  << setw(11) << "NAME\t" << setw(11) << "SURNAME\t" << setw(11) << "NUMBER\t" << setw(11) << "ADDRESS\t" << setw(11) << "CATEGORY\n";
    for (int i =0; i < n; i++)
    {
        if(category[i] == catlook)
        {
             cout << i+1 <<"." << setw(11) << name[i] << "\t" << setw(11) << surname[i] << "\t" << setw(11)  << fixed << setprecision(0) << number[i] << "\t" << setw(11) << address[i] << "\t" << setw(11) << category[i] << "\n";
        }
    }
    cout<< "\n";
}
void Contacts::lookup_number()
{
    double numblook;
    cout << "Input number:";
    cin >> numblook;
    cout<< "\n";
    cout  << setw(11) << "NAME\t" << setw(11) << "SURNAME\t" << setw(11) << "NUMBER\t" << setw(11) << "ADDRESS\t" << setw(11) << "CATEGORY\n";
    for (int i =0; i < n; i++)
    {
        if(number[i] == numblook)
        {
             cout << i+1 <<"." << setw(11) << name[i] << "\t" << setw(11) << surname[i] << "\t" << setw(11)  << fixed << setprecision(0) << number[i] << "\t" << setw(11) << address[i] << "\t" << setw(11) << category[i] << "\n";
        }
    }
    cout<< "\n";
}

void Contacts::lookup_name_surname()
{

    string namelook;
    string surnamelook;
    cout << "Input name:";
    cin >> namelook;
    cout << "Input surname:";
    cin >> surnamelook;
    cout<< "\n";

    cout  << setw(11) << "NAME\t" << setw(11) << "SURNAME\t" << setw(11) << "NUMBER\t" << setw(11) << "ADDRESS\t" << setw(11) << "CATEGORY\n";
    for (int i =0; i < n; i++)
    {
        if((name[i] == namelook)&(surname[i] == surnamelook))
        {
             cout << i+1 <<"." << setw(11) << name[i] << "\t" << setw(11) << surname[i] << "\t" << setw(11)  << fixed << setprecision(0) << number[i] << "\t" << setw(11) << address[i] << "\t" << setw(11) << category[i] << "\n";
        }
    }
    cout<< "\n";
}


void Contacts::tofile()
{
    ofstream fout;

    fout.open("TOtext.txt");
    if(fout.is_open()){
    cout<<"file is open"<<endl;
    } else{
    cout<<"file isn't open"<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        fout << name[i];
        fout << surname[i];
        fout << number[i];
        fout << address[i];
        fout << category[i];
    }
    cout << "\nSAVE\n";
    fout.close();
}

void Contacts::fromfile()
{
    ifstream fin;
    fin.open("FROMfile.txt");
    if(fin.is_open()){
    cout<<"file is open\n"<<endl;
    } else{
    cout<<"file isn't open\n"<<endl;
}
        for (int i = 0; i < n; i++)
    {
        fin >> name[i];
        fin >> surname[i];
        fin >> number[i];
        fin >> address[i];
        fin >> category[i];
    }
 output1();
        fin.close();
}

void Contacts::push_back1()
{
    string *name1 = new string[n+1];
    string *surname1 = new string[n+1];
    double *number1 = new double[n+1];
    string *address1 = new string[n+1];
    string *category1 = new string[n+1];
    for(int i = 0; i < n; i++)
    {
        name1[i] = name[i];
        surname1[i] = surname[i];
        number1[i] = number[i];
        address1[i] = address[i];
        category1[i] = category[i];
    }
        cout << "Write name:";
        cin >> name1[n];
         cout << "Write surname:";
        cin >> surname1[n];
         cout << "Write number:";
        cin >> number1[n];
                if (number1[n] < 0)
        {
            do{
        cout << "\nyou entered the wrong number;\n";
        cout << "Write number:";
        cin >> number1[n];}while (number1[n] < 0);
            }
         cout << "Write address:";
        cin >> address1[n];
         cout << "Write category (if family - FM; if friend - FD; if work - WK; if other - OR):";
        cin >> category1[n];
        n++;
      delete [] name;
    delete [] surname;
    delete [] number;
    delete [] address;
    delete [] category;

    name = name1;
    surname = surname1;
    number = number1;
    address = address1;
    category = category1;
 output1();
}

void Contacts::del()
{
    cout  << setw(11) << "NAME\t" << setw(11) << "SURNAME\t" << setw(11) << "NUMBER\t" << setw(11) << "ADDRESS\t" << setw(11) << "CATEGORY\n";
        for(int i = 0; i < n ; i++)
        {
            cout << i+1 <<"." << setw(11) << name[i] << "\t" << setw(11) << surname[i] << "\t" << setw(11)  << fixed << setprecision(0) << number[i] << "\t" << setw(11) << address[i] << "\t" << setw(11) << category[i] << "\n";
        }
    int rem;
    cout << "Input number jf records to which you want to remove:";
    cin >> rem;
    rem--;

    string *name2 = new string[n-1];
    string *surname2 = new string[n-1];
    double *number2 = new double[n-1];
    string *address2 = new string[n-1];
    string *category2 = new string[n-1];

   for(int i=0;i<n-1;i++)
    {
        if(i<rem)
        {
        name2[i] = name[i];
        surname2[i] = surname[i];
        number2[i] = number[i];
        address2[i] = address[i];
        category2[i] = category[i];
        }
    else if(i>=rem)
    {
        name2[i] = name[i+1];
        surname2[i] = surname[i+1];
        number2[i] = number[i+1];
        address2[i] = address[i+1];
        category2[i] = category[i+1];
    } }
    n=n-1;
    delete [] name;
    delete [] surname;
    delete [] number;
    delete [] address;
    delete [] category;
        name = name2;
        surname = surname2;
        number = number2;
        address = address2;
        category = category2;
output1();
}
Contacts::~Contacts()
{
    delete [] name;
    delete [] surname;
    delete [] number;
    delete [] address;
    delete [] category;
}

Contacts& Contacts::operator= (const Contacts &m)
{
    name = new string[n];
    surname = new string[n];
    number = new double[n];
    address = new string[n];
    category = new string[n];
    for(int i = 0; i < n; i++)
    {
        name[i] = m.name[i];
        surname[i] = m.surname[i];
        number[i] = m.number[i];
        address[i] = m.address[i];
        category[i] = m.category[i];
    }
    return *this;
}
