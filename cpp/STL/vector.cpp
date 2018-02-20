#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void show_vector(vector <int> g)
{
    vector <int> :: iterator it;

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
    vector <int> gvector;

    for (int i=0; i<10; i++) {
        gvector.push_back(i);
    }

    show_vector(gvector);

    cout << "\nElement at front: ";
    cout << gvector.front() << "\n";
    show_vector(gvector);

    gvector.push_back(77);
    gvector.push_back(76);
    gvector.push_back(90);
    show_vector(gvector);
}

