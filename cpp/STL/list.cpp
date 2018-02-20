#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void show_list(list <int> g)
{
    list <int> :: iterator it;

    cout << "\n";
    for (it=g.begin(); it != g.end(); it++) {
        cout << "Element: ";
        cout << (*it);
        cout << "\n";
    }
}

int main()
{
    //cout << "Hello world \n";
    list <int> glist;

    for (int i=0; i<10; i++) {
        glist.push_front(i);
    }

    show_list(glist);

    glist.reverse();
    show_list(glist);

    cout << "\nRemoving element at front: ";
    glist.pop_front();
    show_list(glist);


    cout << "\nElement at front: ";
    cout << glist.front() << "\n";
    show_list(glist);

    glist.reverse();
    glist.push_front(56);
    glist.push_front(76);
    glist.push_front(90);
    show_list(glist);
    
    cout << "\nSorting the list: ";
    glist.sort();
    show_list(glist);
}

