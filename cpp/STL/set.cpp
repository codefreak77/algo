#include <iostream>
#include <set>
#include <iterator>
using namespace std;

void show_set(set <int> g) 
{
    set <int> :: iterator it;

    cout << "\n";
    for (it=g.begin(); it != g.end(); it++) {
        cout << "element of set: " << *it << "\n";
    }
}


int main()
{
    set <int> gset;
    set <int> :: iterator it;

    gset.insert(50);
    gset.insert(540);
    gset.insert(98);
    gset.insert(4);
    gset.insert(5000);
    gset.insert(57);

    show_set(gset);

    cout << "\nLower bound 51: " << *gset.lower_bound(51) << "\n";
    cout << "\n";
    for (it=gset.lower_bound(51); it != gset.end(); it++) {
        cout << "element of set: " << *it << "\n";
    }
    
    cout << "\nUpper bound 51: " << *gset.upper_bound(51) << "\n";
    cout << "\n";
    for (it=gset.upper_bound(51); it != gset.end(); it++) {
        cout << "element of set: " << *it << "\n";
    }
}
