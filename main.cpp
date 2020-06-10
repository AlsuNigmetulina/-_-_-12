#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include "contact.h"
using namespace std;

int main()
{
    system("color 0B");
    int n, num, a, b;
    cout <<"Download from file - 1;\nEnter phone directory - 2;\n";
    cout << "\n>";
    cin >> a;
    if ((a == 1)||(a == 2)){
    switch (a)
    {
        case 1:{
        cout << "Input number of records 1-20\n";
        cout << "\n>";
        cin >> n;
        cout << "\n";
        if((n<1)||(n>20)){
        do{
        cout << "\nError\n";
        cout << "Input number of records 1-20\n";
        cout << "\n>";
        cin >> n;}while ((n<1)||(n>20));}
        Contacts a(n);
        a.fromfile();

        do{
         cout <<"edit record - 1;\nadd record - 2;\nremove record - 3;\nlookup category - 4;\nlookup number - 5;\nlookup name & surname -  6;\nsave to file - 7;\nremove all records - 8;\nEXIT - 9;";
         cout << "\n>";
         cin >> b;
        switch(b){
    case 1: a.edit_el(); break;
    case 2: a.push_back1(); break;
    case 3: a.del(); break;
    case 4: a.lookup_category(); break;
    case 5: a.lookup_number(); break;
    case 6: a.lookup_name_surname(); break;
    case 7: a.tofile(); break;
    case 8: a.remove_contacts(); break;
    case 9: return 0; break;
    default: cout << "\nError\n"; }
    }while (b != 9);}
    case 2:
        {
        cout << "Input number of records:\n";
        cout << "\n>";
        cin >> n;
        if (n<1)
        {
            do{
        cout << "Error";
        cout << "Input number of records:\n";
        cout << "\n>";
        cin >> n;
            }while(n<1);
        }
        Contacts a(n);
        a.input1();
        do {
         cout <<"edit record - 1; \nadd record - 2; \nremove record - 3; \nlookup category - 4; \nlookup number - 5; \nlookup name and surname - 6; \nsave to file - 7; \nremove all records - 8; \nEXIT - 9;";
         cout << "\n>";
         cin >> b;

        switch(b){
    case 1: a.edit_el(); break;
    case 2: a.push_back1(); break;
    case 3: a.del(); break;
    case 4: a.lookup_category(); break;
    case 5: a.lookup_number(); break;
    case 6: a.lookup_name_surname(); break;
    case 7: a.tofile(); break;
    case 8: a.remove_contacts(); break;
    case 9: return 0; break;
    default: cout << "\nError\n";
    }
    }while (b != 9);
        }}
    } else {cout << "Error";}
 return 0;
}
